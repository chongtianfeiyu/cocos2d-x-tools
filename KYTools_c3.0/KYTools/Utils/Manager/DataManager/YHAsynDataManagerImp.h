//
//  YHAsynDataManagerImp.h
//  MonsterHunter
//
//  Created by Zhenyu Yao on 14-2-14.
//
//

#ifndef __MonsterHunter__YHAsynDataManagerImp__
#define __MonsterHunter__YHAsynDataManagerImp__

#include <KYTools/Utils/Manager/DataManager/YHDataManagerImp.h>
#include <KYTools/libs/pthreadcc/pthreadcc.h>

/**
 * 使用异步装载文件的管理器
 * @author Zhenyu Yao
 */
class YHAsynDataManagerImp : public YHDataManagerImp
{
public:
    
    YHAsynDataManagerImp() : m_thread(NULL)
	{
	}
	
	virtual ~YHAsynDataManagerImp()
	{
        removeAllFiles();
        CC_SAFE_DELETE(m_thread);
	}
	
	virtual void addFile(const std::string & file);
	virtual void removeFile(const std::string & file);
	virtual void removeAllFiles();
	virtual void start();
	virtual void stop();
	virtual bool completed();
	virtual YHByteArray * dataForFile(const std::string & file);
	virtual cocos2d::CCTexture2D * textureForFile(const std::string & file);
	virtual cocos2d::CCDictionary * dictionaryForFile(const std::string & file);
	virtual cocos2d::CCArray * arrayForFile(const std::string & file);
    virtual std::vector<std::string> allFiles();
	virtual void update(float dt) override;
    
private:
    
    /**
     * 装载线程
     * @author Zhenyu Yao
     */
    class LoadThread : public ThreadBase
    {
    public:
        
        virtual void * Execute();
        YHAsynDataManagerImp * m_parent;
        bool m_flag;
    };
    
    LoadThread * m_thread;
    MutualExclusion m_lock;
};

#endif /* defined(__MonsterHunter__YHAsynDataManagerImp__) */
//













































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


