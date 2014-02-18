//
//  YHDevice.h
//  MonsterHunter
//
//  Created by Zhenyu Yao on 14-1-9.
//
//

#ifndef __MonsterHunter__YHDevice__
#define __MonsterHunter__YHDevice__

#include <KYTools/YHTypes.h>

/**
 * 与设备相关的功能, 因各个平台不同会有不同的返回值
 * @author Zhenyu Yao
 */
class YHDevice : public YHObject
{
public:
	
	/// 单例模式, 获得唯一的 YHDevice 对象
	static YHDevice * sharedInstance();
	
	/// 每台设备唯一的标识符
	virtual std::string deviceIdentifier() = 0;
	
	/// 当前的系统版本
	virtual std::string osVersion() = 0;
	
	/// 当前运行的平台, 当前 iOS, Android
	virtual std::string platform() = 0;
	
protected:
	YHDevice() {}
	virtual ~YHDevice() {}
};

#endif /* defined(__MonsterHunter__YHDevice__) */














































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


