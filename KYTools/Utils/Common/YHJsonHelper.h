//
//  YHJsonHelper.h
//  MonsterHunter
//
//  Created by Zhenyu Yao on 14-1-9.
//
//

#ifndef __MonsterHunter__YHDictionaryHelper__
#define __MonsterHunter__YHDictionaryHelper__

#include <KYTools/libs/jsoncpp/include/json/json.h>
#include <KYTools/YHTypes.h>

/// Json -> CCDictionary
extern cocos2d::CCDictionary * dictionaryFromJson(const Json::Value & root);

/// Json -> CCArray
extern cocos2d::CCArray * arrayFromJson(const Json::Value & root);

/// CCDictionary -> Json
extern Json::Value jsonFromDictionary(cocos2d::CCDictionary * root);

/// CCArray -> Json
extern Json::Value jsonFromArray(cocos2d::CCArray * root);

#endif /* defined(__MonsterHunter__YHJsonHelper__) */














































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


