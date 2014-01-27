//
//  YHDataManager.cpp
//  MonsterHunter
//
//  Created by Zhenyu Yao on 14-1-9.
//
//

#include <KYTools/Utils/Manager/DataManager/YHDataManager.h>
#include <KYTools/Utils/Manager/DataManager/YHDataManagerImp.h>
#include <KYTools/Utils/Manager/DataManager/YHSchedulerDataManagerImp.h>

////////////////////////////////////////////////////////////////////////////////////////////////////
// Public Functions
////////////////////////////////////////////////////////////////////////////////////////////////////

YHDataManager * YHDataManager::create(const std::string & type)
{
	YHDataManagerImp * imp = NULL;
	if (type.compare("Default") == 0)
		imp = new YHSchedulerDataManagerImp();
	
	imp->autorelease();
	
	YHDataManager * manager = new YHDataManager();
	manager->init(imp);
	manager->autorelease();
	
	return manager;
}

YHDataManager::YHDataManager() : m_imp(NULL)
{
}

YHDataManager::~YHDataManager()
{
	CC_SAFE_RELEASE_NULL(m_imp);
}

bool YHDataManager::init(YHDataManagerImp * imp)
{
	m_imp = imp;
	CC_SAFE_RETAIN(m_imp);
	return true;
}

void YHDataManager::addFile(const std::string & file)
{
	m_imp->addFile(file);
}

void YHDataManager::removeFile(const std::string & file)
{
	m_imp->removeFile(file);
}

void YHDataManager::removeAllFiles()
{
	m_imp->removeAllFiles();
}

void YHDataManager::start()
{
	m_imp->start();
}

void YHDataManager::stop()
{
	m_imp->stop();
}

bool YHDataManager::completed()
{
	return m_imp->completed();
}

YHByteArray * YHDataManager::bytesForFile(const std::string & file)
{
	return m_imp->dataForFile(file);
}

CCTexture2D * YHDataManager::textureForFile(const std::string & file)
{
	return m_imp->textureForFile(file);
}

CCDictionary * YHDataManager::dictionaryForFile(const std::string & file)
{
	return m_imp->dictionaryForFile(file);
}

CCArray * YHDataManager::arrayForFile(const std::string & file)
{
	return m_imp->arrayForFile(file);
}









































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


