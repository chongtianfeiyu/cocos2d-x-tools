//
//  YHAnimationHelper.cpp
//  AndroidaBooM
//
//  Created by Zhenyu Yao on 13-4-27.
//
//

#include <KYTools/AnimationHelper/Animation/YHAnimationHelper.h>
#include <KYTools/AnimationHelper/Action/AnimationTypes.h>
#include <KYTools/Utils/Common/CommonUtils.h>

using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////
// YHAnimationFrameDefiner
////////////////////////////////////////////////////////////////////////////////////////////////////

YHAnimationFrameDefiner::YHAnimationFrameDefiner(CCDictionary * dict)
{
	// index
	CCString * strIndex = dynamic_cast<CCString *>(dict->objectForKey("Index"));
	m_index = strIndex->uintValue();
	
	// Delay units
	CCString * strDelayUnits = dynamic_cast<CCString *>(dict->objectForKey("DelayUnits"));
	m_delayUnit = strDelayUnits != NULL ? strDelayUnits->floatValue() : 1.0f;
	
	// UserData
	m_userInfo = dynamic_cast<CCDictionary *>(dict->objectForKey("UserInfo"));
	CC_SAFE_RETAIN(m_userInfo);
}

YHAnimationFrameDefiner::YHAnimationFrameDefiner(const YHAnimationFrameDefiner & definer)
{
	m_index = definer.getIndex();
	m_delayUnit = definer.getDelayUnit();
	m_userInfo = definer.getUserInfo();
	CC_SAFE_RETAIN(m_userInfo);
}

YHAnimationFrameDefiner & YHAnimationFrameDefiner::operator = (const YHAnimationFrameDefiner & definer) 
{
	m_index = definer.getIndex();
	m_delayUnit = definer.getDelayUnit();
	CC_SAFE_RELEASE(m_userInfo);
	m_userInfo = definer.getUserInfo();
	CC_SAFE_RETAIN(m_userInfo);
	return *this;
}

YHAnimationFrameDefiner::~YHAnimationFrameDefiner()
{
	CC_SAFE_RELEASE(m_userInfo);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// YHAnimationDefiner
////////////////////////////////////////////////////////////////////////////////////////////////////

void YHAnimationDefiner::parse_ver1(CCDictionary * dict)
{
	m_delay = dict->valueForKey("Delay")->floatValue();

	CCArray * resources = dynamic_cast<CCArray *>(dict->objectForKey("Resources"));
	CCObject * pObj = NULL;
	CCARRAY_FOREACH(resources, pObj)
	{
		CCString * spriteFrameName = static_cast<CCString *>(pObj);
		m_resources.push_back(spriteFrameName->getCString());
	}
}

void YHAnimationDefiner::parse_ver2(CCDictionary * dict)
{
	// File name
	CCString * name = dynamic_cast<CCString *>(dict->objectForKey("FileName"));

	// Range
	CCString * strRange = dynamic_cast<CCString *>(dict->objectForKey("Range"));
	CCPoint point = CCPointFromString(strRange->getCString());
	
	// Extension
	CCString * extension = dynamic_cast<CCString *>(dict->objectForKey("Extension"));

	// Delay
	CCString * strDelay = dynamic_cast<CCString *>(dict->objectForKey("Delay"));
	m_delay = strDelay->floatValue();
	
	// Loop
	CCString * strLoop = dynamic_cast<CCString *>(dict->objectForKey("Loop"));
	m_loop = strLoop->uintValue();
	
	// RestoreOriginFrame
	CCString * strRestoreOriginFrame = dynamic_cast<CCString *>(dict->objectForKey("RestoreOriginFrame"));
	m_restoreOriginFrame = strRestoreOriginFrame != NULL ? strRestoreOriginFrame->boolValue() : false;
	
	// resources
	for (uint32 i = point.x; i <= point.y; ++i)
	{
		string spriteFrameName = name->getCString() + uint32ToString(i) + "." + extension->getCString();
		m_resources.push_back(spriteFrameName.c_str());
	}
	
	// 设置各个帧的参数
	CCArray * frames = dynamic_cast<CCArray *>(dict->objectForKey("Frames"));
	CCObject * pObj = NULL;
	CCARRAY_FOREACH(frames, pObj)
	{
		CCDictionary * frameDict = dynamic_cast<CCDictionary *>(pObj);
		YHAnimationFrameDefiner frameDefiner = YHAnimationFrameDefiner(frameDict);
		frameDefiner.m_index = frameDefiner.m_index - point.x;		// 计算出实际帧的 Index
		m_frameDefiners.push_back(frameDefiner);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// YHSpriteDefiner
////////////////////////////////////////////////////////////////////////////////////////////////////

YHSpriteDefiner::YHSpriteDefiner(CCDictionary * dict) :
m_anchorPoint(ccp(0.5f, 0.5f)),
m_position(CCPointZero),
m_zOrder(0),
m_randomRotate(false)
{
	m_blendFunc.src = CC_BLEND_SRC;
	m_blendFunc.dst = CC_BLEND_DST;
	
	if (dict != NULL)
	{
		m_anchorPoint = CCPointFromString(dict->valueForKey("Anchor")->getCString());
		m_position = CCPointFromString(dict->valueForKey("Position")->getCString());
		m_zOrder = dict->valueForKey("ZOrder")->intValue();
		m_randomRotate = dict->valueForKey("RandomRotate")->boolValue();
		
		CCDictionary * blendFuncDict = (CCDictionary *)dict->objectForKey("BlendFunc");
		if (blendFuncDict != NULL)
		{
			m_blendFunc.src = blendFuncDict->valueForKey("Src")->uintValue();
			m_blendFunc.dst = blendFuncDict->valueForKey("Dst")->uintValue();
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// YHAnimationHelper
////////////////////////////////////////////////////////////////////////////////////////////////////

CCAnimation * YHAnimationHelper::createAnimation_Ver1(CCDictionary * dict)
{
	YHAnimationDefiner definer = createAnimationDefiner_Ver1(dict);
	return createAnimation(definer);
}

CCAnimation * YHAnimationHelper::createAnimation_Ver2(CCDictionary * dict)
{
	YHAnimationDefiner definer = createAnimationDefiner_Ver2(dict);
	return createAnimation(definer);
}

CCAnimation * YHAnimationHelper::createAnimation(const YHAnimationDefiner & definer)
{
	// 创建 CCAnimationFrame 对象数组
	vector<string>::const_iterator resBeg = definer.getResources().begin();
	vector<string>::const_iterator resEnd = definer.getResources().end();
	CCArray * animationFrames = new CCArray();
	CCSpriteFrameCache * cache = CCSpriteFrameCache::sharedSpriteFrameCache();
	for (; resBeg != resEnd; ++resBeg)
	{
		CCSpriteFrame * spriteFrame = cache->spriteFrameByName(resBeg->c_str());
		CCAnimationFrame * animationFrame = new CCAnimationFrame();
		animationFrame->initWithSpriteFrame(spriteFrame, 1.0f, NULL);
		animationFrame->autorelease();
		animationFrames->addObject(animationFrame);
	}
	
	// 设置各个帧的参数
	vector<YHAnimationFrameDefiner>::const_iterator frameBeg = definer.getFrameDefines().begin();
	vector<YHAnimationFrameDefiner>::const_iterator frameEnd = definer.getFrameDefines().end();
	for(; frameBeg != frameEnd; ++frameBeg)
	{
		YHAnimationFrameDefiner frameDefiner = *frameBeg;
		CCAnimationFrame * animationFrame = static_cast<CCAnimationFrame *>(animationFrames->objectAtIndex(frameDefiner.getIndex()));
		animationFrame->setDelayUnits(frameDefiner.getDelayUnit());
		animationFrame->setUserInfo(frameDefiner.getUserInfo());
	}
	
	CCAnimation * animation = CCAnimation::create(animationFrames, definer.getDelay(), definer.getLoop());
	animation->setRestoreOriginalFrame(definer.getRestoreOriginFrame());
	animationFrames->release();
	return animation;
}

YHAnimationDefiner YHAnimationHelper::createAnimationDefiner_Ver1(CCDictionary * dict)
{
	YHAnimationDefiner definer;
	definer.parse_ver1(dict);
	return definer;
}

YHAnimationDefiner YHAnimationHelper::createAnimationDefiner_Ver2(CCDictionary * dict)
{
	YHAnimationDefiner definer;
	definer.parse_ver2(dict);
	return definer;
}

CCAnimate * YHAnimationHelper::createAnimate(CCAnimation * animation)
{
	return CCAnimate::create(animation);
}

CCRepeatForever * YHAnimationHelper::createForeverAnimate(CCAnimation * animation)
{
	return CCRepeatForever::create(createAnimate(animation));
}

YHAnimationPair * YHAnimationHelper::createAnimationPair(CCAnimation * animation, bool loop)
{
	CCAction * action = NULL;
	if (loop)
		action = createForeverAnimate(animation);
	else
		action = createAnimate(animation);
	
	YHAnimationKeyEvents * keyEvents = YHAnimationKeyEvents::create(animation, loop);
	YHAnimationPair * animPair = new YHAnimationPair();
	animPair->autorelease();
	animPair->setAction(action);
	animPair->setKeyEvents(keyEvents);
	return animPair;
}

void YHAnimationHelper::runAnimation(CCAnimation * animation, CCSprite * sprite)
{
	CCAnimationFrame * animationFrame = static_cast<CCAnimationFrame *>(animation->getFrames()->objectAtIndex(0));
	sprite->setDisplayFrame(animationFrame->getSpriteFrame());

	CCAnimate * animate = CCAnimate::create(animation);
	sprite->runAction(animate);
}

void YHAnimationHelper::runForeverAnimation(CCAnimation * animation, CCSprite * sprite)
{
	CCAnimate * animate = CCAnimate::create(animation);
	CCRepeatForever * forever = CCRepeatForever::create(animate);
	sprite->runAction(forever);

	CCAnimationFrame * animationFrame = static_cast<CCAnimationFrame *>(animate->getAnimation()->getFrames()->objectAtIndex(0));
	sprite->setDisplayFrame(animationFrame->getSpriteFrame());
}

void YHAnimationHelper::spriteWithDictionary(CCSprite * sprite, CCDictionary * dict)
{
	YHSpriteDefiner definer(dict);
	sprite->setAnchorPoint(definer.getAnchorPoint());
	sprite->setPosition(definer.getPosition());
	sprite->setZOrder(definer.getZOrder());
}

void YHAnimationHelper::runActionWithSprite(cocos2d::CCSprite *sprite,
											cocos2d::CCAnimation *animation,
											bool forever,
											AnimatorInitData *initData,
											AnimatorAnimData *animData)
{
	assert(sprite);
	assert(animation);
	assert(initData);
	assert(animData);
	
	sprite->stopAllActions();
	if (forever)
		runForeverAnimation(animation, sprite);
	else
		runAnimation(animation, sprite);
	
	initData->initializeNode(sprite);
	animData->runActions(sprite);
}

void YHAnimationHelper::runActionWithSprite(cocos2d::CCSprite *sprite,
											cocos2d::CCAnimation *animation,
											bool forever,
											AnimatorData *animatorData)
{
	runActionWithSprite(sprite, animation, forever, animatorData->m_initData, animatorData->m_animData);
}
