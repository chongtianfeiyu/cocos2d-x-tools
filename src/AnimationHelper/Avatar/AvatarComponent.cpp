//
//  AvatarComponent.cpp
//  HelloWorld-3.0
//
//  Created by Zhenyu Yao on 14-4-12.
//
//

#include <AnimationHelper/Avatar/AvatarComponent.h>
#include <AnimationHelper/Animation/YHAnimationHelper.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
// Public Functions
////////////////////////////////////////////////////////////////////////////////////////////////////

AvatarComponent::AvatarComponent() : m_delegate(nullptr)
{
    for (int32 i = 200; i < 205; ++i)
        m_animatorDataTags.push_back(i);
}

AvatarComponent::~AvatarComponent()
{
    CC_SAFE_RELEASE_NULL(m_animation);
    CC_SAFE_RELEASE_NULL(m_ktCallback);
    CC_SAFE_RELEASE_NULL(m_animatorData);
    this->cleanup();
}

bool AvatarComponent::init(CCAnimation * animation, YHKeyTimeCallback * ktCallback, AnimatorData * animatorData)
{
    bool ret = CCSprite::init();
    
    if (ret)
    {
        setAnimation(animation);
        setKeyTimeCallback(ktCallback);
        setAnimatorData(animatorData);
    }
    
    return ret;
}

void AvatarComponent::setAnimation(CCAnimation * animation)
{
    this->stopActionByTag(m_animationTag);
    CC_SAFE_RELEASE_NULL(m_animation);
    
    if (animation != nullptr)
    {
        m_animation = animation;
        m_animation->retain();
        
        this->setSpriteFrame(animation->getFrames().at(0)->getSpriteFrame());
        
        CCAnimate * animate = CCAnimate::create(animation);
        animate->setTag(m_animationTag);
        this->runAction(animate);
    }
}

void AvatarComponent::setKeyTimeCallback(YHKeyTimeCallback * callback)
{
    this->stopActionByTag(m_ktCallbackTag);
    CC_SAFE_RELEASE_NULL(m_ktCallback);
    
    if (callback != nullptr)
    {
        m_ktCallback = callback;
        m_ktCallback->retain();
        
        m_ktCallback->setNode(this);
        m_ktCallback->setDelegate(this);
        m_ktCallback->getAction()->setTag(m_ktCallbackTag);
        this->runAction(m_ktCallback->getAction());
    }
}

void AvatarComponent::setAnimatorData(AnimatorData * animatorData)
{
    for (auto i : m_animatorDataTags)
        this->stopActionByTag(i);
    CC_SAFE_RELEASE_NULL(m_animatorData);
    
    if (animatorData != nullptr)
    {
        m_animatorData = animatorData;
        m_animatorData->retain();
        
        m_animatorData->getInitData()->initializeNode(this);
        m_animatorData->getAnimData()->runActions(this);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// Interface - YHKeyTimeCallbackDelegate
////////////////////////////////////////////////////////////////////////////////////////////////////

void AvatarComponent::handleKeyEvent(CCNode * node, CCAnimationFrame * frame)
{
    if (m_delegate != nullptr)
        m_delegate->handleKeyEvent(node, frame);
}

void AvatarComponent::handleKeyEvent(CCNode * node, CCDictionary * userInfo)
{
    if (m_delegate != nullptr)
        m_delegate->handleKeyEvent(node, userInfo);
}










































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


