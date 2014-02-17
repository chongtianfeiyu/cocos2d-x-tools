//
//  YHAsynDataManagerImp.cpp
//  MonsterHunter
//
//  Created by Zhenyu Yao on 14-2-14.
//
//

#include "YHAsynDataManagerImp.h"

void YHAsynDataManagerImp::addFile(const std::string & file)
{
    m_lock.Lock();
    
    CCObject * obj = NULL;
    bool exist = false;
    CCARRAY_FOREACH(m_waitingFiles, obj)
    {
        CCString * str = (CCString *)obj;
        if (strcmp(str->getCString(), file.c_str()) == 0)
        {
            exist = true;
            break;
        }
    }
    
    if (getDict()->objectForKey(file) != NULL)
        exist = true;
    
    if (!exist)
        m_waitingFiles->addObject(CCString::create(file));
    
    m_lock.Unlock();
}

void YHAsynDataManagerImp::removeFile(const std::string & file)
{
    m_lock.Lock();
    
    CCObject * obj = NULL;
    bool exist = false;
    CCARRAY_FOREACH(m_waitingFiles, obj)
    {
        CCString * str = (CCString *)obj;
        if (strcmp(str->getCString(), file.c_str()) == 0)
        {
            exist = true;
            break;
        }
    }
    
    if (exist)
    {
        m_waitingFiles->removeObject(obj);
        getDict()->removeObjectForKey(file);
    }
    
    m_lock.Unlock();
}

void YHAsynDataManagerImp::removeAllFiles()
{
    m_lock.Lock();
    
    m_waitingFiles->removeAllObjects();
    getDict()->removeAllObjects();
    
    m_lock.Unlock();
}

void YHAsynDataManagerImp::start()
{
    if (m_thread == NULL)
    {
        m_thread = new LoadThread();
        m_thread->m_parent = this;
        m_thread->m_flag = true;
        m_thread->LaunchThread();
        
        // 必须等待线程启动
        while (!m_thread->ThreadRunning());
        
        CCDirector::sharedDirector()->getScheduler()->scheduleUpdateForTarget(this, DataManagerPriority, false);
    }
}

void YHAsynDataManagerImp::stop()
{
    if (m_thread != NULL)
    {
        m_thread->m_flag = false;
        while (m_thread->ThreadRunning());  // 必须等待线程结束
        CC_SAFE_DELETE(m_thread);
        
        CCDirector::sharedDirector()->getScheduler()->unscheduleUpdateForTarget(this);
    }
}

bool YHAsynDataManagerImp::completed()
{
    m_lock.Lock();
    bool c = m_waitingFiles->count() == 0 && m_thread == NULL;
    m_lock.Unlock();
    
    return c;
}

YHByteArray * YHAsynDataManagerImp::dataForFile(const std::string & file)
{
    m_lock.Lock();
    YHByteArray * bytes = (YHByteArray *)getDict()->objectForKey(file);
    m_lock.Unlock();
    
    return bytes;
}

CCTexture2D * YHAsynDataManagerImp::textureForFile(const std::string & file)
{
    m_lock.Lock();
    CCTexture2D * tex = (CCTexture2D *)getDict()->objectForKey(file);
    m_lock.Unlock();
 
    return tex;
}

CCDictionary * YHAsynDataManagerImp::dictionaryForFile(const std::string & file)
{
    m_lock.Lock();
    CCDictionary * dict = (CCDictionary *)getDict()->objectForKey(file);
    m_lock.Unlock();
    
    return dict;
}

CCArray * YHAsynDataManagerImp::arrayForFile(const std::string & file)
{
    m_lock.Lock();
    CCArray * arr = (CCArray *)getDict()->objectForKey(file);
    m_lock.Unlock();
    
    return arr;
}

void YHAsynDataManagerImp::update(float dt)
{
    if (m_waitingFiles->count() == 0 && !m_thread->ThreadRunning())
    {
        CC_SAFE_DELETE(m_thread);
        CCDirector::sharedDirector()->getScheduler()->unscheduleUpdateForTarget(this);
    }
}

void * YHAsynDataManagerImp::LoadThread::Execute()
{
    while (m_parent->m_waitingFiles->count() != 0 && m_flag)
    {
        // 得到文件路径, 并且将等待文件移除
        m_parent->m_lock.Lock();
        string file, fullpath;
        if (m_parent->m_waitingFiles->count() != 0)
        {
            file = ((CCString *)m_parent->m_waitingFiles->objectAtIndex(0))->getCString();
            fullpath = CCFileUtils::sharedFileUtils()->fullPathForFilename(file.c_str());
            m_parent->m_waitingFiles->removeObjectAtIndex(0);
        }
        m_parent->m_lock.Unlock();
        
        // 如果没有该文件
        if (fullpath.compare(file) == 0 || fullpath.length() == 0 || file.length() == 0)
            continue;
        
        CCObject * obj = m_parent->loadFile(fullpath);
        if (obj != NULL)
        {
            m_parent->m_lock.Lock();
            m_parent->getDict()->setObject(obj, file);
            m_parent->m_lock.Unlock();
        }
    }
    
    return NULL;
}












































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


