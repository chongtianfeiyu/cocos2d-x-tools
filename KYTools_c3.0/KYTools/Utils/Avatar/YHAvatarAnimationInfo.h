//
//  YHAvatarAnimationInfo.h
//  MGBX
//
//  Created by Zhenyu Yao on 14-3-25.
//  Copyright (c) 2014年 Mog Gen. All rights reserved.
//

#ifndef MGBX_YHAvatarAnimationInfo_h
#define MGBX_YHAvatarAnimationInfo_h

#include <KYTools/YHTypes.h>
#include <KYTools/AnimationHelper/Action/AnimationTypes.h>

class YHAvatarSegment;

/**
 * Avatar 动画的信息
 * @author Zhenyu Yao
 */
class YHAvatarAnimationInfo : public YHObject
{
public:
    
    YHAvatarAnimationInfo() :
    m_animatorData(nullptr),
    m_animation(nullptr),
    m_dataDict(nullptr),
    m_callback(nullptr),
    m_loop(false)
    {
    }
    
    virtual ~YHAvatarAnimationInfo()
    {
        CC_SAFE_RELEASE_NULL(m_animatorData);
        CC_SAFE_RELEASE_NULL(m_animation);
        CC_SAFE_RELEASE_NULL(m_dataDict);
    }
    
    static YHAvatarAnimationInfo * create(cocos2d::CCAnimation * animation,
                                          AnimatorData * animatorData = nullptr,
                                          cocos2d::CCDictionary * dataDict = nullptr,
                                          const std::function<void (YHAvatarSegment *)> & callback = nullptr,
                                          bool loop = false)
    {
        YHAvatarAnimationInfo * instance = new YHAvatarAnimationInfo();
        instance->setAnimation(animation);
        instance->setAnimatorData(animatorData);
        instance->setDataDict(dataDict);
        instance->setCallback(callback);
        instance->setLoop(loop);
        instance->autorelease();
        return instance;
    }
    
    /// 骨骼动画数据
    CC_SYNTHESIZE_RETAIN(AnimatorData *, m_animatorData, AnimatorData);
    
    /// 序列帧数据
    CC_SYNTHESIZE_RETAIN(cocos2d::CCAnimation *, m_animation, Animation);
    
    /// 关键帧数据, 当次数据不为 nullptr 的时候, 将忽略 animation 中的关键帧数据
    CC_SYNTHESIZE_RETAIN(cocos2d::CCDictionary *, m_dataDict, DataDict);
    
    /// 每次骨骼动画播放结束后的回调, 注意: 是骨骼动画结束后的回调
    CC_SYNTHESIZE_PASS_BY_REF(std::function<void (YHAvatarSegment *)>, m_callback, Callback);
    
    /// 序列帧是否循环
    CC_SYNTHESIZE(bool, m_loop, Loop);
};

#endif














































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


