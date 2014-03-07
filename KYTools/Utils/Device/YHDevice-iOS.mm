//
//  YHDevice-iOS.mm
//  MonsterHunter
//
//  Created by Zhenyu Yao on 14-1-9.
//
//

#include <KYTools/Utils/Device/YHDevice-iOS.h>

using namespace std;

string YHDevice_iOS::deviceIdentifier()
{
	NSUUID * uuid = [[UIDevice currentDevice] identifierForVendor];
    string strIdentifier = [[uuid UUIDString] cStringUsingEncoding:NSUTF8StringEncoding];
    return strIdentifier;
}

string YHDevice_iOS::osVersion()
{
	NSString * result = [[UIDevice currentDevice] systemVersion];
	string version = [result cStringUsingEncoding:NSUTF8StringEncoding];
	return version;
}

string YHDevice_iOS::platform()
{
	return "iOS";
}












































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


