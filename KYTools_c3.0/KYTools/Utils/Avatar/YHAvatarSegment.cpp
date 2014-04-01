//
//  YHAvatarSegment.cpp
//  MGBX
//
//  Created by Zhenyu Yao on 14-3-25.
//  Copyright (c) 2014年 Mog Gen. All rights reserved.
//

#include <KYTools/Utils/Avatar/YHAvatarSegment.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
// Public Functions
////////////////////////////////////////////////////////////////////////////////////////////////////

void YHAvatarSegment::immediatePlay(YHAvatarAnimationInfo * info)
{
    m_infos.insert(0, info);
    play(info);
}

void YHAvatarSegment::pushInfo(YHAvatarAnimationInfo * info)
{
    m_infos.pushBack(info);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// Private Functions
////////////////////////////////////////////////////////////////////////////////////////////////////

void YHAvatarSegment::onSkeletonFinished()
{
    // 执行回调
    YHAvatarAnimationInfo * info = m_infos.front();
    info->getCallback()(this);
    
    // 删除队首元素
    m_infos.erase(0);
    
    // 如果队列不空, 继续播放
    if (!m_infos.empty())
    {
        play(m_infos.front());
    }
}

void YHAvatarSegment::play(YHAvatarAnimationInfo * info)
{
    this->stopAllActions();
    
    if (info->getDataDict() == nullptr)
        CCKeyTimeCallbackSprite::playWithSequenceFrames(info->getAnimation(), info->getLoop());
    else
        CCKeyTimeCallbackSprite::playWithDataDict(info->getAnimation(), info->getDataDict(), info->getLoop());
    
    AnimatorInitData * initData = info->getAnimatorData()->getInitData();
    AnimatorAnimData * animData = info->getAnimatorData()->getAnimData();
    initData->initializeNode(this);
    animData->runActions(this);
    
    // 有回调
    if (info->getCallback() != nullptr)
    {
        CCDelayTime * delay = CCDelayTime::create(animData->getSumTime());
        CCCallFunc * callfunc = CCCallFunc::create(CC_CALLBACK_0(YHAvatarSegment::onSkeletonFinished, this));
        CCSequence * sequence = CCSequence::create(delay, callfunc, nullptr);
        this->runAction(sequence);
    }
}






































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


