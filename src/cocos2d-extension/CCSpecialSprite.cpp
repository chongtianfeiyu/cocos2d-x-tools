
#include <cocos2d-extension/CCSpecialSprite.h>
#include <AnimationHelper/Action/AnimationTypes.h>

void CCSpecialSprite::draw(Renderer *renderer, const kmMat4 &transform, bool transformUpdated)
{
}

void CCSpecialSprite::setColor(const ccColor3B & color3)
{
	CCSprite::setColor(color3);
    
    Vector<CCNode *>::const_iterator beg = _children.begin();
    Vector<CCNode *>::const_iterator end = _children.end();
    for (; beg != end; ++beg)
    {
        CCRGBAProtocol * rgba = dynamic_cast<CCRGBAProtocol *>(*beg);
        if (rgba != NULL)
            rgba->setColor(color3);
    }
}

void CCSpecialSprite::setOpacity(GLubyte opacity)
{
	CCSprite::setOpacity(opacity);
    
    Vector<CCNode *>::const_iterator beg = _children.begin();
    Vector<CCNode *>::const_iterator end = _children.end();
    for (; beg != end; ++beg)
    {
        CCRGBAProtocol * rgba = dynamic_cast<CCRGBAProtocol *>(*beg);
        if (rgba != NULL)
            rgba->setOpacity(opacity);
    }
}

void CCSpecialSprite::setBlendFunc(const cocos2d::BlendFunc & blendFunc)
{
    CCSprite::setBlendFunc(blendFunc);
    
    Vector<CCNode *>::const_iterator beg = _children.begin();
    Vector<CCNode *>::const_iterator end = _children.end();
    for (; beg != end; ++beg)
    {
        CCBlendProtocol * blend = dynamic_cast<CCBlendProtocol *>(*beg);
        if (blend != NULL)
            blend->setBlendFunc(blendFunc);
    }
}

void CCSpecialSprite::addChild(CCNode *pChild, int zOrder, int tag)
{
	CCSprite::addChild(pChild, zOrder, tag);

	setTexture(((CCSprite*)pChild)->getTexture());
    
	CCRGBAProtocol * rgba = dynamic_cast<CCRGBAProtocol *>(pChild);
	if (rgba != NULL)
	{
		rgba->setColor(this->getColor());
		rgba->setOpacity(this->getOpacity());
	}
}

bool CCSpecialSprite::init(cocos2d::CCDictionary * moduleDict)
{
	assert(moduleDict);
	
	bool bRet = false;
	
	do {
		AnimatorModuleData * moduleData = AnimatorModuleData::data(moduleDict);
		CC_BREAK_IF(!init(moduleData));
		
		bRet = true;
	} while (0);
	
	return bRet;
}

bool CCSpecialSprite::init(AnimatorModuleData * moduleData)
{
	bool bRet = false;
	
	do {
		CC_BREAK_IF(!CCSprite::init());
        moduleData->assignToNode(this);
		bRet = true;
	} while (0);
	
	return bRet;
}

CCSpecialSprite* CCSpecialSprite::create(cocos2d::CCDictionary * moduleDict)
{
	CCSpecialSprite* sp = new CCSpecialSprite();
	if (sp && sp->init(moduleDict))
	{
		sp->autorelease();
		return sp;
	}
	CC_SAFE_DELETE(sp);
	return NULL;
}

CCSpecialSprite* CCSpecialSprite::create(AnimatorModuleData * moduleData)
{
	CCSpecialSprite* sp = new CCSpecialSprite();
	if (sp && sp->init(moduleData))
	{
		sp->autorelease();
		return sp;
	}
	CC_SAFE_DELETE(sp);
	return NULL;
}
