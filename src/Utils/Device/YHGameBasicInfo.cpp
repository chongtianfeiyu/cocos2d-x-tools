//
//  YHGameBasicInfo.cpp
//  MGBX
//
//  Created by Zhenyu Yao on 14-3-17.
//  Copyright (c) 2014年 Mog Gen. All rights reserved.
//

#include "YHGameBasicInfo.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    #include "YHGameBasicInfo-Android.h"
#else
    #include "YHGameBasicInfo-iOS.h"
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////
// Public Functions
////////////////////////////////////////////////////////////////////////////////////////////////////

YHGameBasicInfo * YHGameBasicInfo::sharedInstance()
{
    static YHGameBasicInfo * s_instance = nullptr;
    if (s_instance == nullptr)
    {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        s_instance = new YHGameBasicInfo_Android();
#else
        s_instance = new YHGameBasicInfo_iOS();
#endif
        s_instance->init();
    }
    
    return s_instance;
}












































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


