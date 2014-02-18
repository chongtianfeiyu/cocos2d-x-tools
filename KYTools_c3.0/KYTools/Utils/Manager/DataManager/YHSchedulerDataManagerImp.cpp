//
//  YHSchedulerDataManagerImp.cpp
//  MonsterHunter
//
//  Created by Zhenyu Yao on 14-1-10.
//
//

#include <KYTools/Utils/Manager/DataManager/YHSchedulerDataManagerImp.h>
#include <KYTools/Utils/Buffer/YHByteArray.h>
#include <KYTools/Utils/Common/CommonUtils.h>
#include <KYTools/Utils/Common/YHJsonHelper.h>

void YHSchedulerDataManagerImp::addFile(const std::string & file)
{
	CCObject * obj = NULL;
	CCARRAY_FOREACH(m_waitingFiles, obj)
	{
		CCString * str = (CCString *)obj;
		if (strcmp(str->getCString(), file.c_str()) == 0)
			return;
	}
	
	if (getDict()->objectForKey(file) != NULL)
		return;
	
	m_waitingFiles->addObject(CCString::create(file));
}

void YHSchedulerDataManagerImp::removeFile(const std::string & file)
{
	uint32 index = 0;
	CCObject * obj = NULL;
	CCARRAY_FOREACH(m_waitingFiles, obj)
	{
		CCString * str = (CCString *)obj;
		if (strcmp(str->getCString(), file.c_str()) == 0)
			break;
		++index;
	}
	m_waitingFiles->removeObjectAtIndex(index);
	
	getDict()->removeObjectForKey(file);
}

void YHSchedulerDataManagerImp::removeAllFiles()
{
	m_waitingFiles->removeAllObjects();
	getDict()->removeAllObjects();
}

void YHSchedulerDataManagerImp::start()
{
	CCScheduler * scheduler = CCDirector::sharedDirector()->getScheduler();
	scheduler->unscheduleUpdateForTarget(this);
	scheduler->scheduleUpdateForTarget(this, DataManagerPriority, false);
}

void YHSchedulerDataManagerImp::stop()
{
	CCDirector::sharedDirector()->getScheduler()->unscheduleUpdateForTarget(this);
}

bool YHSchedulerDataManagerImp::completed()
{
	return m_waitingFiles->count() == 0;
}

YHByteArray * YHSchedulerDataManagerImp::dataForFile(const std::string & file)
{
	return (YHByteArray *)getDict()->objectForKey(file);
}

CCTexture2D * YHSchedulerDataManagerImp::textureForFile(const std::string & file)
{
	return (CCTexture2D *)getDict()->objectForKey(file);
}

CCDictionary * YHSchedulerDataManagerImp::dictionaryForFile(const std::string & file)
{
	return (CCDictionary *)getDict()->objectForKey(file);
}

CCArray * YHSchedulerDataManagerImp::arrayForFile(const std::string & file)
{
	return (CCArray *)getDict()->objectForKey(file);
}

void YHSchedulerDataManagerImp::update(float dt)
{
	if (m_waitingFiles->count() == 0)
	{
		CCDirector::sharedDirector()->getScheduler()->unscheduleUpdateForTarget(this);
		return;
	}
	
	string file = ((CCString *)m_waitingFiles->objectAtIndex(0))->getCString();
	m_waitingFiles->removeObjectAtIndex(0);
	
	string suffix = pathExtensionWithString(file);
	string fullpath = CCFileUtils::sharedFileUtils()->fullPathForFilename(file.c_str());
	
	// 如果没有该文件
	if (fullpath.compare(file) == 0)
	{
		if (m_waitingFiles->count() == 0)
			CCDirector::sharedDirector()->getScheduler()->unscheduleUpdateForTarget(this);
		return;
	}
	
	// 装载对应的对象
	CCObject * obj = loadFile(fullpath);
    if (obj != NULL)
        getDict()->setObject(obj, file);
	
	if (m_waitingFiles->count() == 0)
		CCDirector::sharedDirector()->getScheduler()->unscheduleUpdateForTarget(this);
}






































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


