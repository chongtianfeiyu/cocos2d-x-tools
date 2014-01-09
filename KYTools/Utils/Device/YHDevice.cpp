//
//  YHDevice.cpp
//  MonsterHunter
//
//  Created by Zhenyu Yao on 14-1-9.
//
//

#include <KYTools/Utils/Device/YHDevice.h>
#include <KYTools/Utils/Device/YHDevice-iOS.h>

static YHDevice * s_instance = NULL;

YHDevice * YHDevice::sharedInstance()
{
	if (s_instance == NULL)
		s_instance = new YHDevice_iOS();
	return s_instance;
}










































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


