#ifndef __KYTOOLS_SAMPLE_SCENE_H__
#define __KYTOOLS_SAMPLE_SCENE_H__

#include "cocos2d.h"
#include "KYTools/KYTools.h"

class KYToolsSample_3_X : public cocos2d::Layer, public YHAnimationKeyEventsDelegate
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(Object* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(KYToolsSample_3_X);
    
    virtual void handleKeyEvent(cocos2d::CCNode * node, cocos2d::CCAnimationFrame * frame) override;
    
private:
    
    CCSpecialSprite * createModuleSprite(const std::string & moduleFile);
    cocos2d::CCSprite * createSegmentSprite(const std::string & animFile, const std::string & animationName);
    
    YHEffectFactory * m_effectFactory;
    YHAnimationPair * m_animationPair;
};

#endif // __KYTOOLS_SAMPLE_SCENE_H__
