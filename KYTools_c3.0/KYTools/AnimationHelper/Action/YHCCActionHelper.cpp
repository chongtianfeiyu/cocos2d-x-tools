//
//  YHCCActionHelper.cpp
//  AndroidaBooM
//
//  Created by Zhenyu Yao on 13-4-29.
//
//

#include <KYTools/AnimationHelper/Action/YHCCActionHelper.h>
#include <KYTools/AnimationHelper/Animation/YHAnimationHelper.h>

using namespace cocos2d;

void YHCCActionHelper::runNormalForeverScale(float initScale, float finishScale, float duration, CCNode * pNode)
{
	pNode->setScale(initScale);
	CCScaleTo * scaleTo1 = CCScaleTo::create(duration * 0.5f, finishScale);
	CCScaleTo * scaleTo2 = CCScaleTo::create(duration * 0.5f, initScale);
	CCSequence * seq = CCSequence::create(scaleTo1, scaleTo2, NULL);
	CCRepeatForever * forever = CCRepeatForever::create(seq);
	pNode->runAction(forever);
}

void YHCCActionHelper::runIntervalForeverAnimation(float interval, CCAnimation * animation, CCSprite * pSprite)
{
	CCAnimate * animate = CCAnimate::create(animation);
	CCDelayTime * delay = CCDelayTime::create(interval);
	CCSequence * sequence = CCSequence::create(animate, delay, NULL);
	CCRepeatForever * forever = CCRepeatForever::create(sequence);
	CCAnimationFrame * animationFrame = static_cast<CCAnimationFrame *>(animate->getAnimation()->getFrames().at(0));
	pSprite->setDisplayFrame(animationFrame->getSpriteFrame());
	pSprite->runAction(forever);
}

void YHCCActionHelper::runNormalForeverMove(const cocos2d::Point & delta, float duration, cocos2d::CCNode * pNode)
{
    CCMoveBy * moveBy1 = CCMoveBy::create(duration * 0.5f, delta);
    CCMoveBy * moveBy2 = CCMoveBy::create(duration * 0.5f, Point(-delta.x, -delta.y));
    CCSequence * sequence = CCSequence::create(moveBy1, moveBy2, nullptr);
    pNode->runAction(CCRepeatForever::create(sequence));
}















































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


