//
//  YHAsynDataManagerImp.cpp
//  MonsterHunter
//
//  Created by Zhenyu Yao on 14-2-14.
//
//

#include <Utils/Manager/DataManager/YHAsynDataManagerImp.h>
#include <Utils/Buffer/YHByteArray.h>

//#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
//#include "platform/android/jni/JniHelper.h"
//#include <jni.h>
//#endif

USING_NS_CC;

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
    if (m_thread == NULL && m_waitingFiles->count() != 0)
    {
        m_thread = new LoadThread();
        m_thread->m_parent = this;
        m_thread->m_flag = true;
        m_thread->LaunchThread();
        
        // 必须等待线程启动, 为的是防止接下来马上调用 stop 方法不会 crash
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
    YHByteArray * bytes = dynamic_cast<YHByteArray *>(getDict()->objectForKey(file));
    m_lock.Unlock();
    
    return bytes;
}

CCTexture2D * YHAsynDataManagerImp::textureForFile(const std::string & file)
{
    m_lock.Lock();
    CCTexture2D * tex = dynamic_cast<CCTexture2D *>(getDict()->objectForKey(file));
    m_lock.Unlock();
 
    return tex;
}

CCDictionary * YHAsynDataManagerImp::dictionaryForFile(const std::string & file)
{
    m_lock.Lock();
    CCDictionary * dict = dynamic_cast<CCDictionary *>(getDict()->objectForKey(file));
    m_lock.Unlock();
    
    return dict;
}

CCArray * YHAsynDataManagerImp::arrayForFile(const std::string & file)
{
    m_lock.Lock();
    CCArray * arr = dynamic_cast<CCArray *>(getDict()->objectForKey(file));
    m_lock.Unlock();
    
    return arr;
}

std::vector<std::string> YHAsynDataManagerImp::allFiles()
{
    m_lock.Lock();
    std::vector<std::string> ret = m_finishedFiles;
    m_lock.Unlock();
    
    return ret;
}

void YHAsynDataManagerImp::update(float dt)
{
    if (m_waitingFiles->count() == 0 && !m_thread->ThreadRunning())
    {
        CC_SAFE_DELETE(m_thread);
        
        // Image -> CCTexture2D
        for (auto f : m_finishedFiles)
        {
            Image * img = dynamic_cast<Image *>(getDict()->objectForKey(f));
            if (img != nullptr)
            {
                std::string fullpath = CCFileUtils::getInstance()->fullPathForFilename(f);
                CCTexture2D * tex = CCTextureCache::getInstance()->addImage(img, fullpath);
                getDict()->setObject(tex, f);
            }
        }
        
        if (m_callback != nullptr)
            m_callback();
        CCDirector::sharedDirector()->getScheduler()->unscheduleUpdateForTarget(this);
    }
}

void * YHAsynDataManagerImp::LoadThread::Execute()
{
    
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
//    JavaVM *vm;
//    JNIEnv *env;
//    vm = JniHelper::getJavaVM();
//    
//    JavaVMAttachArgs thread_args;
//    
//    thread_args.name = "YHAsynDataManagerImp";
//    thread_args.version = JNI_VERSION_1_4;
//    thread_args.group = NULL;
//    
//    vm->AttachCurrentThread(&env, &thread_args);
//#endif
    
    while (m_parent->m_waitingFiles->count() != 0 && m_flag)
    {
        // 得到文件路径, 并且将等待文件移除
        m_parent->m_lock.Lock();
        std::string file, fullpath;
        if (m_parent->m_waitingFiles->count() != 0)
        {
            file = ((CCString *)m_parent->m_waitingFiles->objectAtIndex(0))->getCString();
            fullpath = CCFileUtils::sharedFileUtils()->fullPathForFilename(file.c_str());
            
            // 如果没有该文件, 直接移除
            if (file.compare(fullpath) == 0)
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
            m_parent->m_finishedFiles.push_back(file);
            m_parent->m_waitingFiles->removeObjectAtIndex(0);
            m_parent->m_lock.Unlock();
            obj->release();
        }
    }
    
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
//    vm->DetachCurrentThread();
//#endif
    
    return NULL;
}












































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


