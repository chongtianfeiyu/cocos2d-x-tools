//
//  YHAvatarSegment.h
//  MGBX
//
//  Created by Zhenyu Yao on 14-3-25.
//  Copyright (c) 2014年 Mog Gen. All rights reserved.
//

#ifndef __MGBX__YHAvatarSegment__
#define __MGBX__YHAvatarSegment__

#include <KYTools/Utils/Avatar/YHAvatarAnimationInfo.h>
#include <KYTools/cocos2d-extension/CCKeyTimeCallbackSprite.h>

class YHAvatar;

/**
 * Avatar 的关节, 它内部维护着一个 YHAvatarAnimationInfo 队列, 一般情况下播放完当前的动画之后, 就播放下一个.
 * @note 当前动画的结束是根据骨骼动画的结束来决定, 而不是序列帧动画.
 * @author Zhenyu Yao
 */
class YHAvatarSegment : public CCKeyTimeCallbackSprite
{
public:
    
    YHAvatarSegment();
    virtual ~YHAvatarSegment();
    
    /**
     * 立即播放, 并将 info 插入到队列头
     */
    void immediatePlay(YHAvatarAnimationInfo * info);
    
    /**
     * 添加到队列尾
     */
    void pushInfo(YHAvatarAnimationInfo * info);
    
protected:
    
    /// 骨骼动画播放结束
    virtual void onSkeletonFinished();
    
    /// 根据 info 播放动画
    virtual void play(YHAvatarAnimationInfo * info);
    
protected:
    
    cocos2d::Vector<YHAvatarAnimationInfo *> m_infos;
};

#endif /* defined(__MGBX__YHAvatarSegment__) */














































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


