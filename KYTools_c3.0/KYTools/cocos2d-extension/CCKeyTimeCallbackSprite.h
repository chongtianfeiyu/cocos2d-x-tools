//
//  CCKeyTimeCallbackSprite.h
//  HelloWorld-3.0
//
//  Created by Zhenyu Yao on 14-3-12.
//
//

#ifndef __HelloWorld_3_0__CCKeyTimeCallbackSprite__
#define __HelloWorld_3_0__CCKeyTimeCallbackSprite__

#include <cocos2d.h>
#include <KYTools/AnimationHelper/Animation/YHAnimationKeyEvents.h>

/**
 * 处理关键时间回调的显示对象
 * @author Zhenyu Yao
 */
class CCKeyTimeCallbackSprite : public cocos2d::CCSprite
{
public:
    
    CCKeyTimeCallbackSprite();
    virtual ~CCKeyTimeCallbackSprite();
    
    YHKeyTimeCallbackDelegate * getDelegate() const { return m_callback->getDelegate(); }
    void setDelegate(YHKeyTimeCallbackDelegate * delegate) { m_callback->setDelegate(delegate); }
    
    /// 初始化
    virtual bool init(cocos2d::CCAnimation * animation, bool loop);
    
    /// 初始化
    virtual bool init(cocos2d::CCAnimation * animation, cocos2d::CCDictionary * dataDict, bool loop);
    
    /// 创建 CCKeyTimeCallbackSprite 对象
    static CCKeyTimeCallbackSprite * create(cocos2d::CCAnimation * animation, bool loop)
    {
        CCKeyTimeCallbackSprite * instance = new CCKeyTimeCallbackSprite();
        if (instance != NULL && instance->init(animation, loop))
        {
            instance->autorelease();
            return instance;
        }
        
        CC_SAFE_DELETE(instance);
        return instance;
    }
    
    /// 创建 CCKeyTimeCallbackSprite 对象
    static CCKeyTimeCallbackSprite * create(cocos2d::CCAnimation * animation, cocos2d::CCDictionary * dataDict, bool loop)
    {
        CCKeyTimeCallbackSprite * instance = new CCKeyTimeCallbackSprite();
        if (instance != NULL && instance->init(animation, dataDict, loop))
        {
            instance->autorelease();
            return instance;
        }
        
        CC_SAFE_DELETE(instance);
        return instance;
    }
    
private:
    
    YHKeyTimeCallback * m_callback;
};

#endif /* defined(__HelloWorld_3_0__CCKeyTimeCallbackSprite__) */














































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


