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
    static std::string s_identifier;
    
    if (s_identifier.empty())
    {
        NSUUID * uuid = [[UIDevice currentDevice] identifierForVendor];
        s_identifier = [[uuid UUIDString] cStringUsingEncoding:NSUTF8StringEncoding];
    }
    
    return s_identifier;
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

bool YHDevice_iOS::isJailBrokeDevice()
{
    static const char* jailbreak_apps[] =
    {
        "/Applications/Cydia.app",
        "/Applications/blackra1n.app",
        "/Applications/blacksn0w.app",
        "/Applications/greenpois0n.app",
        "/Applications/limera1n.app",
        "/Applications/redsn0w.app",
        NULL,
    };
    
    for (int i = 0; jailbreak_apps[i] != NULL; ++i)
    {
        if ([[NSFileManager defaultManager] fileExistsAtPath:
             [NSString stringWithCString:jailbreak_apps[i] encoding:NSUTF8StringEncoding]])
        {
            return true;
        }
    }
    
    return false;
}












































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


