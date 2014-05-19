//
//  Test_VirguleNumber.cpp
//  cocos2d_x_tools
//
//  Created by Zhenyu Yao on 14-5-17.
//
//

#include "Test_VirguleNumber.h"

USING_NS_CC;

static YHUIVirguleNumber * createNumber()
{
    Sprite * virgule = Sprite::createWithSpriteFrameName("UI_Number_Virgule.png");
    YHUIVirguleNumber * number = YHUIVirguleNumber::create("UI_Number_Font.png", cocos2d::Size(13, 17), 12, virgule);
    number->setVirguleInterval(10.0f);
    return number;
}

Test_VirguleNumber::~Test_VirguleNumber()
{
    this->cleanup();
}

bool Test_VirguleNumber::init()
{
    bool result = Node::init();
    
    if (result)
    {
        Size size = Director::getInstance()->getVisibleSize();
        Point center(size.width * 0.5f, size.height * 0.5f);
        SpriteFrameCache::getInstance()->addSpriteFramesWithFile("UI_Collection-hd.plist");
        
        DrawNode * drawNode = DrawNode::create();
        drawNode->drawSegment(Point(center.x, size.height), Point(center.x, 0.0f), 1.0f, Color4F(0, 0.5f, 0, 1.0f));
        this->addChild(drawNode);
        
        YHUISpriteNumber * testNumber = YHUISpriteNumber::create("UI_Number_Font.png", Size(13, 17), 12);
        testNumber->setNumber(999999);
        testNumber->setPosition(100, 100);
        testNumber->setColor(Color3B(0, 0xff, 0xff));
        this->addChild(testNumber);
        
        YHUIVirguleNumber * number1 = createNumber();
        number1->setLRNumber(999, 9999);
        number1->setPosition(center.x, center.y + 100);
        number1->getLNumberSprite()->setColor(Color3B(0xff, 0, 0));
        this->addChild(number1);
        
        YHUIVirguleNumber * number2 = createNumber();
        number2->setLRNumber(999, 9999);
        number2->setPosition(center);
        number2->setAlignType(YHISpriteNumber::kAlignType_Center);
        number2->getRNumberSprite()->setColor(Color3B(0, 0, 0xff));
        this->addChild(number2);

        YHUIVirguleNumber * number3 = createNumber();
        number3->setLRNumber(999, 9999);
        number3->setPosition(center.x, center.y - 100);
        number3->setAlignType(YHISpriteNumber::kAlignType_Right);
        number3->setColor(Color3B(0xff, 0xff, 0));
        this->addChild(number3);
    }
    
    return result;
}












































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


