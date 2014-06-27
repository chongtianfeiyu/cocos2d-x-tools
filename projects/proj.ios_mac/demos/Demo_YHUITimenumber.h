//
//  Demo_YHUITimenumber.h
//  cocos2d_x_tools
//
//  Created by Zhenyu Yao on 14-5-19.
//
//

#ifndef __cocos2d_x_tools__Demo_YHUITimenumber__
#define __cocos2d_x_tools__Demo_YHUITimenumber__

#include <cocos2d-x-tools.h>

class Demo_YHUITimeNumber : public cocos2d::Node
{
public:
    
    virtual ~Demo_YHUITimeNumber();
    
    static cocos2d::Scene * createScene()
    {
        cocos2d::Scene * scene = cocos2d::Scene::create();
        scene->addChild(Demo_YHUITimeNumber::create());
        return scene;
    }
    
    /// 创建 Demo_YHUITimeNumber 对象
    CREATE_FUNC(Demo_YHUITimeNumber);
    
    /// 初始化
    virtual bool init() override;
};

#endif /* defined(__cocos2d_x_tools__Demo_YHUITimenumber__) */














































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


