//
//  Demo_YHUITimenumber.cpp
//  cocos2d_x_tools
//
//  Created by Zhenyu Yao on 14-5-19.
//
//

#include "Demo_YHUITimenumber.h"

USING_NS_CC;

Demo_YHUITimeNumber::~Demo_YHUITimeNumber()
{
    this->cleanup();
}

bool Demo_YHUITimeNumber::init()
{
    bool result = Node::init();
    
    if (result)
    {
        Size size = Director::getInstance()->getVisibleSize();
        Point center(size.width * 0.5f, size.height * 0.5f);
        
        DrawNode * drawNode = DrawNode::create();
        drawNode->drawSegment(Point(center.x, size.height), Point(center.x, 0.0f), 1.0f, Color4F(0, 0.5f, 0, 1.0f));
        this->addChild(drawNode);
        
        SpriteFrameCache::getInstance()->addSpriteFramesWithFile("UI_Collection-hd.plist");
        
        {
            YHUITimeNumber * number = YHUITimeNumber::create(Sprite::createWithSpriteFrameName("Pic_Number_Cln.png"), 6,
                                                             Sprite::createWithSpriteFrameName("Pic_Number_Cln.png"), 6,
                                                             "UI_Number_Font.png", Size(13, 17), 12);
            number->setPosition(center.x, center.y + center.y * 0.8f);
            number->setTimeWithSecond(1000);
            number->setAlignType(YHISpriteNumber::kAlignType_Left);
            this->addChild(number);
        }
        
        {
            YHUITimeNumber * number = YHUITimeNumber::create(Sprite::createWithSpriteFrameName("Pic_Number_Cln.png"), 6,
                                                             Sprite::createWithSpriteFrameName("Pic_Number_Cln.png"), 6,
                                                             "UI_Number_Font.png", Size(13, 17), 12);
            number->setPosition(center.x, center.y + center.y * 0.5f);
            number->setTimeWithSecond(1000);
            number->setAlignType(YHISpriteNumber::kAlignType_Center);
            this->addChild(number);
        }
        
        {
            YHUITimeNumber * number = YHUITimeNumber::create(Sprite::createWithSpriteFrameName("Pic_Number_Cln.png"), 6,
                                                             Sprite::createWithSpriteFrameName("Pic_Number_Cln.png"), 6,
                                                             "UI_Number_Font.png", Size(13, 17), 12);
            number->setPosition(center.x, center.y + center.y * 0.2f);
            number->setTimeWithSecond(1000);
            number->setAlignType(YHISpriteNumber::kAlignType_Right);
            this->addChild(number);
        }
        
        {
            YHUITimeNumber * number = YHUITimeNumber::create(Sprite::createWithSpriteFrameName("Pic_Number_Cln.png"), 6,
                                                             Sprite::createWithSpriteFrameName("Pic_Number_Cln.png"), 6,
                                                             "UI_Number_Font.png", Size(13, 17), 12);
            number->setPosition(center.x, center.y - center.y * 0.8f);
            number->setTimeWithSecond(1000);
            number->setAlignType(YHISpriteNumber::kAlignType_Left);
            number->setIcon(Sprite::createWithSpriteFrameName("Pic_UI_Bar_Time.png"));
            number->setIconInterval(15);
            number->setHourVisible(false);
            this->addChild(number);
        }
        
        {
            YHUITimeNumber * number = YHUITimeNumber::create(Sprite::createWithSpriteFrameName("Pic_Number_Cln.png"), 6,
                                                             Sprite::createWithSpriteFrameName("Pic_Number_Cln.png"), 6,
                                                             "UI_Number_Font.png", Size(13, 17), 12);
            number->setPosition(center.x, center.y - center.y * 0.5f);
            number->setTimeWithSecond(1000);
            number->setAlignType(YHISpriteNumber::kAlignType_Center);
            number->setIcon(Sprite::createWithSpriteFrameName("Pic_UI_Bar_Time.png"));
            number->setIconInterval(15);
            number->setMinVisible(false);
            this->addChild(number);
        }
        
        {
            YHUITimeNumber * number = YHUITimeNumber::create(Sprite::createWithSpriteFrameName("Pic_Number_Cln.png"), 6,
                                                             Sprite::createWithSpriteFrameName("Pic_Number_Cln.png"), 6,
                                                             "UI_Number_Font.png", Size(13, 17), 12);
            number->setPosition(center.x, center.y - center.y * 0.2f);
            number->setTimeWithSecond(1000);
            number->setAlignType(YHISpriteNumber::kAlignType_Right);
            number->setIcon(Sprite::createWithSpriteFrameName("Pic_UI_Bar_Time.png"));
            number->setIconInterval(15);
            this->addChild(number);
        }
    }
    
    return result;
}












































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


