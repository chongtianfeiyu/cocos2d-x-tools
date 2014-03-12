//
//  CCKeyTimeCallbackSprite.cpp
//  HelloWorld-3.0
//
//  Created by Zhenyu Yao on 14-3-12.
//
//

#include "CCKeyTimeCallbackSprite.h"
#include <KYTools/AnimationHelper/Animation/YHAnimationHelper.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
// Public Functions
////////////////////////////////////////////////////////////////////////////////////////////////////

CCKeyTimeCallbackSprite::CCKeyTimeCallbackSprite() :
m_callback(NULL)
{
}

CCKeyTimeCallbackSprite::~CCKeyTimeCallbackSprite()
{
    CC_SAFE_RELEASE_NULL(m_callback);
}

bool CCKeyTimeCallbackSprite::init(CCAnimation * animation, bool loop)
{
    bool result = CCSprite::init();
    
    // 运行动画和关键帧
    YHAnimationPair * aPair = YHAnimationHelper::createAnimationPairAndRun(animation, this, loop);
    m_callback = aPair->getKeyEvents();
    m_callback->retain();
    
    return result;
}

bool CCKeyTimeCallbackSprite::init(CCAnimation * animation, CCDictionary * dataDict, bool loop)
{
    bool result = CCSprite::init();
    
    // 动画
    if (loop)
        YHAnimationHelper::runForeverAnimation(animation, this);
    else
        YHAnimationHelper::runAnimation(animation, this);
    
    // 关键帧
    m_callback = YHKeyTimeCallback::create(dataDict);
    CC_SAFE_RETAIN(m_callback);
    this->runAction(m_callback->getAction());
    m_callback->setNode(this);
    
    return result;
}











































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


