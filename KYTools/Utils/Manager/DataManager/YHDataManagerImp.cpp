//
//  YHDataManagerImp.cpp
//  MonsterHunter
//
//  Created by Zhenyu Yao on 14-1-10.
//
//

#include <KYTools/Utils/Manager/DataManager/YHDataManagerImp.h>

YHDataManagerImp::YHDataManagerImp() : m_waitingFiles(NULL)
{
}

YHDataManagerImp::~YHDataManagerImp()
{
	CC_SAFE_RELEASE_NULL(m_waitingFiles);
}

bool YHDataManagerImp::init()
{
	bool result = YHAbstractDataSetting::init(NULL);
	
	setDict(CCDictionary::create());
	
	m_waitingFiles = CCArray::create();
	CC_SAFE_RETAIN(m_waitingFiles);
	
	return result;
}












































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


