//
//  ActionParseBase.cpp
//  cocos2d-x-Utils
//
//  Created by mac on 13-6-18.
//
//

#include <AnimationHelper/Action/ActionParseBase.h>
#include <AnimationHelper/Action/ActionContext.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
// Public Functions
////////////////////////////////////////////////////////////////////////////////////////////////////

CCPoint ActionParseBase::pointWithContentScale(const CCPoint & point)
{
    float contentScale = Director::getInstance()->getContentScaleFactor();
    return ccp(point.x / contentScale, point.y / contentScale);
}

float ActionParseBase::floatWithContentScale(float value)
{
    return value / Director::getInstance()->getContentScaleFactor();
}

