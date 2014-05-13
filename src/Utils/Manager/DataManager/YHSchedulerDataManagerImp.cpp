//
//  YHSchedulerDataManagerImp.cpp
//  MonsterHunter
//
//  Created by Zhenyu Yao on 14-1-10.
//
//

#include <Utils/Manager/DataManager/YHSchedulerDataManagerImp.h>
#include <Utils/Buffer/YHByteArray.h>
#include <Utils/Common/CommonUtils.h>
#include <Utils/Common/YHJsonHelper.h>

USING_NS_CC;
using namespace std;

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
	return dynamic_cast<YHByteArray *>(getDict()->objectForKey(file));
}

CCTexture2D * YHSchedulerDataManagerImp::textureForFile(const std::string & file)
{
	return dynamic_cast<CCTexture2D *>(getDict()->objectForKey(file));
}

CCDictionary * YHSchedulerDataManagerImp::dictionaryForFile(const std::string & file)
{
	return dynamic_cast<CCDictionary *>(getDict()->objectForKey(file));
}

CCArray * YHSchedulerDataManagerImp::arrayForFile(const std::string & file)
{
	return dynamic_cast<CCArray *>(getDict()->objectForKey(file));
}

std::vector<std::string> YHSchedulerDataManagerImp::allFiles()
{
    return m_finishedFiles;
}

void YHSchedulerDataManagerImp::update(float dt)
{
	if (m_waitingFiles->count() == 0)
	{
        if (m_callback != nullptr)
            m_callback();
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
        {
            if (m_callback != nullptr)
                m_callback();
			CCDirector::sharedDirector()->getScheduler()->unscheduleUpdateForTarget(this);
        }
		return;
	}
	
	// 装载对应的对象
	CCObject * obj = loadFile(fullpath);
    if (obj != NULL)
    {
        if (dynamic_cast<Image *>(obj) != nullptr)
        {
            CCTexture2D * tex = CCTextureCache::getInstance()->addImage((Image *)obj, fullpath);
            getDict()->setObject(tex, file);
        }
        else
        {
            getDict()->setObject(obj, file);
        }
        
        obj->release();
        m_finishedFiles.push_back(file);
    }
	
	if (m_waitingFiles->count() == 0)
    {
        if (m_callback != nullptr)
            m_callback();
		CCDirector::sharedDirector()->getScheduler()->unscheduleUpdateForTarget(this);
    }
}






































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


