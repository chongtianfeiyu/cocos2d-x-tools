//
//  YHDevice-iOS.h
//  MonsterHunter
//
//  Created by Zhenyu Yao on 14-1-9.
//
//

#ifndef __MonsterHunter__YHDevice_iOS__
#define __MonsterHunter__YHDevice_iOS__

#include <KYTools/Utils/Device/YHDevice.h>

/**
 * iOS 平台设备
 * @author Zhenyu Yao
 */
class YHDevice_iOS : public YHDevice
{
public:
	
	YHDevice_iOS() {}
	virtual ~YHDevice_iOS() {}
	
	virtual std::string deviceIdentifier();
	virtual std::string osVersion();
	virtual std::string platform();
};

#endif /* defined(__MonsterHunter__YHDevice_iOS__) */














































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


