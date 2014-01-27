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
	scheduler->scheduleUpdateForTarget(this, 0, false);
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
	CCObject * obj = NULL;
	if (suffix.compare("plist-array") == 0)
	{
		obj = CCArray::createWithContentsOfFile(fullpath.c_str());
	}
	else if (suffix.compare("plist-dictionary") == 0)
	{
		obj = CCDictionary::createWithContentsOfFile(fullpath.c_str());
	}
	else if (suffix.compare("png") == 0 || suffix.compare("jpg") == 0 || suffix.compare("jpeg") == 0
		|| suffix.compare("tif") == 0 || suffix.compare("tiff") == 0 || suffix.compare("webp") == 0)
	{
		obj = CCTextureCache::sharedTextureCache()->addImage(fullpath.c_str());
	}
	else
	{
		FILE * pFile = fopen(fullpath.c_str(), "r");
		if (pFile != NULL)
		{
			// 获得文件大小
			fseek(pFile, 0, SEEK_END);
			uint32 size = ftell(pFile);
			fseek(pFile, 0, SEEK_SET);
			
			YHByteArray * bytes = new YHByteArray();
			bytes->init(size);
			fread(bytes->getBuffer(), size, 1, pFile);
			
			fclose(pFile);
			
			obj = bytes->autorelease();
		}
	}
	
	getDict()->setObject(obj, file);
	
	if (m_waitingFiles->count() == 0)
		CCDirector::sharedDirector()->getScheduler()->unscheduleUpdateForTarget(this);
}






































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


