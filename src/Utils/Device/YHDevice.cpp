//
//  YHDevice.cpp
//  MonsterHunter
//
//  Created by Zhenyu Yao on 14-1-9.
//
//

#include "YHDevice.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    #include "YHDevice-Android.h"
#else
    #include "YHDevice-iOS.h"
#endif

static YHDevice * s_instance = NULL;

YHDevice * YHDevice::sharedInstance()
{
	if (s_instance == NULL)
    {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        s_instance = new YHDevice_Android();
#else
        s_instance = new YHDevice_iOS();
#endif
    }
		
	return s_instance;
}










































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


