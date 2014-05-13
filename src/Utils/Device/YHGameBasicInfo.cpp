//
//  YHGameBasicInfo.cpp
//  MGBX
//
//  Created by Zhenyu Yao on 14-3-17.
//  Copyright (c) 2014年 Mog Gen. All rights reserved.
//

#include <Utils/Device/YHGameBasicInfo.h>
#include <Utils/Device/YHGameBasicInfo-iOS.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
// Public Functions
////////////////////////////////////////////////////////////////////////////////////////////////////

YHGameBasicInfo * YHGameBasicInfo::sharedInstance()
{
    static YHGameBasicInfo * s_instance = nullptr;
    if (s_instance == nullptr)
    {
        s_instance = new YHGameBasicInfo_iOS();
        s_instance->init();
    }
    
    return s_instance;
}












































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


