//
//  Test_VirguleNumber.h
//  cocos2d_x_tools
//
//  Created by Zhenyu Yao on 14-5-17.
//
//

#ifndef __cocos2d_x_tools__Test_VirguleNumber__
#define __cocos2d_x_tools__Test_VirguleNumber__

#include <cocos2d-x-tools.h>

/**
 * YHUIVirguleNumber 测试
 * @author Zhenyu Yao
 */
class Test_VirguleNumber : public cocos2d::Node
{
public:
    
    virtual ~Test_VirguleNumber();
    
    CREATE_FUNC(Test_VirguleNumber);
    
    static cocos2d::Scene * createScene()
    {
        cocos2d::Scene * scene = cocos2d::Scene::create();
        Test_VirguleNumber * instance = Test_VirguleNumber::create();
        scene->addChild(instance);
        return scene;
    }
    
    /// 初始化
    virtual bool init() override;
};

#endif /* defined(__cocos2d_x_tools__Test_VirguleNumber__) */














































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


