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
	CFUUIDRef puuid = CFUUIDCreate(nil);
	CFStringRef uuidString = CFUUIDCreateString(nil, puuid);
	NSString * result = (NSString *)CFStringCreateCopy(NULL, uuidString);
	CFRelease(puuid);
	CFRelease(uuidString);
	string identifier = [result cStringUsingEncoding:NSUTF8StringEncoding];
	[result release];
	return identifier;
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


