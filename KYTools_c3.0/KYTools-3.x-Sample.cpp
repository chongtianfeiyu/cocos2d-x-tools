
#include "KYTools-3.x-Sample.h"

USING_NS_CC;

#define CENTER ccp(240, 160)

Scene* KYToolsSample_3_X::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = KYToolsSample_3_X::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool KYToolsSample_3_X::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(KYToolsSample_3_X::menuCloseCallback, this));
    
	closeItem->setPosition(Point(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    label->setPosition(Point(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);

// KYTools some samples.
{
    // 初始化
    ActionContext::getContext()->initialize();
    
    // 加载图片资源
    CCSpriteFrameCache::getInstance()->addSpriteFramesWithFile("test/Pic_Lives_0-hd.plist");
    CCSpriteFrameCache::getInstance()->addSpriteFramesWithFile("test/Effect_All-hd.plist");
    
    // 加载动画配置文件
    CCDictionary * animationDict = CCDictionary::createWithContentsOfFile(CCFileUtils::getInstance()->fullPathForFilename("test/Set_Animation.plist").c_str());
    YHAnimationCache::sharedAnimationCache()->addAnimations(animationDict);
    
    // 加载特效配置文件
    m_effectFactory = YHEffectFactory::create();
    m_effectFactory->retain();
    m_effectFactory->addEffectDefiner(CCDictionary::createWithContentsOfFile(CCFileUtils::getInstance()->fullPathForFilename("test/Set_Effect.plist").c_str()));
    
    // 运行动画脚本
    CCSpecialSprite * ss = createModuleSprite("test/Moudle_11_Normal_11_Normal.plist");
    CCSprite * armL = createSegmentSprite("test/Anim_11_Normal_11_Normal_Arm_L.plist", "Pic_Live_Ogre_Lv1_Arm_L");
    CCSprite * armR = createSegmentSprite("test/Anim_11_Normal_11_Normal_Arm_R.plist", "Pic_Live_Ogre_Lv1_Arm_R");
    CCSprite * body = createSegmentSprite("test/Anim_11_Normal_11_Normal_Body.plist", "Pic_Live_Ogre_Lv1_Body");
    CCSprite * hammer = createSegmentSprite("test/Anim_11_Normal_11_Normal_Hammer.plist", "Pic_Live_Runner_Hammer");
    CCSprite * head = createSegmentSprite("test/Anim_11_Normal_11_Normal_Head.plist", "Pic_Live_Ogre_Lv1_Head");
    CCSprite * legL = createSegmentSprite("test/Anim_11_Normal_11_Normal_Leg_L.plist", "Pic_Live_Ogre_Lv1_Leg_L");
    CCSprite * legR = createSegmentSprite("test/Anim_11_Normal_11_Normal_Leg_R.plist", "Pic_Live_Ogre_Lv1_Leg_R");
    ss->addChild(armL);
    ss->addChild(armR);
    ss->addChild(body);
    ss->addChild(hammer);
    ss->addChild(head);
    ss->addChild(legL);
    ss->addChild(legR);
    ss->setPosition(CENTER);
    this->addChild(ss);
    
    // 关键帧
    CCAnimation * animation = YHAnimationCache::sharedAnimationCache()->animationForKeyFromCache_Ver2("KeyFrameTest");
    CCSprite * runKeyFrameSP = CCSprite::create();
    m_animationPair = YHAnimationHelper::createAnimationPairAndRun(animation, runKeyFrameSP, true);
    m_animationPair->retain();
    m_animationPair->getKeyEvents()->setDelegate(this);
    runKeyFrameSP->setPosition(ccp(200, 240));
    this->addChild(runKeyFrameSP);
}
    
    return true;
}

void KYToolsSample_3_X::menuCloseCallback(Object* pSender)
{
//    CCSprite * sp = m_effectFactory->effectSpriteForKey("Stars-2");
    CCSprite * sp = m_effectFactory->effectSpriteForKey("Stars");
    sp->setPosition(CENTER);
    this->addChild(sp);
}

CCSpecialSprite * KYToolsSample_3_X::createModuleSprite(const std::string & moduleFile)
{
    AnimatorModuleData * moduleData = AnimatorModuleDataCache::sharedCache()->getData(moduleFile);
    if (moduleData == NULL)
    {
        std::string fullpath = CCFileUtils::getInstance()->fullPathForFilename(moduleFile);
        CCDictionary * dict = CCDictionary::createWithContentsOfFile(fullpath.c_str());
        moduleData = AnimatorModuleData::data(dict);
        AnimatorModuleDataCache::sharedCache()->addData(moduleData, moduleFile);
    }
    
    return moduleData->createSpecialSprite();
}

CCSprite * KYToolsSample_3_X::createSegmentSprite(const std::string & animFile, const std::string & animationName)
{
    AnimatorData * animData = AnimatorDataCache::sharedCache()->getData(animFile);
    if (animData == NULL)
    {
        std::string fullpath = CCFileUtils::getInstance()->fullPathForFilename(animFile);
        CCDictionary * dict = CCDictionary::createWithContentsOfFile(fullpath.c_str());
        animData = AnimatorData::data(dict);
        AnimatorDataCache::sharedCache()->addData(animData, animFile);
    }
    
    CCSprite * sprite = CCSprite::create();
    CCAnimation * animation = YHAnimationCache::sharedAnimationCache()->animationForKeyFromCache_Ver2(animationName);
    YHAnimationHelper::runActionWithSprite(sprite, animation, true, animData->getInitData(), animData->getAnimData());
    return sprite;
}

void KYToolsSample_3_X::handleKeyEvent(cocos2d::CCNode * node, cocos2d::CCAnimationFrame * frame)
{
    static unsigned int s_count = 0;
    
    CCLOG("---- Tigger count: %u ----", ++s_count);
    
    const ValueMap & userInfo = frame->getUserInfo();
    ValueMap::const_iterator beg = userInfo.begin();
    ValueMap::const_iterator end = userInfo.end();
    for (; beg != end; ++beg)
    {
        std::string key = beg->first;
        const cocos2d::Value & value = beg->second;
        std::string descr = key + ": ";
        
        if (value.getType() == cocos2d::Value::Type::STRING)
        {
            descr += value.asString();
        }
        else if (value.getType() == cocos2d::Value::Type::VECTOR)
        {
            descr += value.asValueVector()[0].asString();
        }
        else if (value.getType() == cocos2d::Value::Type::MAP)
        {
            ValueMap tmp = value.asValueMap();
            descr += tmp["Child1"].asString();
        }
        else if (value.getType() == cocos2d::Value::Type::FLOAT)
        {
            descr += value.asFloat();
        }
        
        CCLOG("---- %s ----", descr.c_str());
    }
}












































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file

