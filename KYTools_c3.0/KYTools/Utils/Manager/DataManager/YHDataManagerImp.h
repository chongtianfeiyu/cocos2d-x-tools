//
//  YHDataManagerImp.h
//  MonsterHunter
//
//  Created by Zhenyu Yao on 14-1-10.
//
//

#ifndef __MonsterHunter__YHDataManagerImp__
#define __MonsterHunter__YHDataManagerImp__

#include <KYTools/YHTypes.h>
#include <KYTools/Utils/Common/YHAbstractDataSetting.h>

class YHByteArray;

/// 优先级
#define DataManagerPriority     0

/**
 * YHDataManager 的实现基类
 * @author Zhenyu Yao
 */
class YHDataManagerImp : public YHAbstractDataSetting
{
public:
	
	YHDataManagerImp();
	virtual ~YHDataManagerImp();
	
	virtual bool init();
	
	virtual void addFile(const std::string & file) = 0;
	virtual void removeFile(const std::string & file) = 0;
	virtual void removeAllFiles() = 0;
	virtual void start() = 0;
	virtual void stop() = 0;
	virtual bool completed() = 0;
	virtual YHByteArray * dataForFile(const std::string & file) = 0;
	virtual cocos2d::CCTexture2D * textureForFile(const std::string & file) = 0;
	virtual cocos2d::CCDictionary * dictionaryForFile(const std::string & file) = 0;
	virtual cocos2d::CCArray * arrayForFile(const std::string & file) = 0;
	
protected:
	
    /// 装载文件, 返回装载文件生成的对象, 在使用完返回对象后, 必须手动调用 release
    virtual cocos2d::CCObject * loadFile(const std::string & fullpath);
    
	cocos2d::CCArray * m_waitingFiles;
};

#endif /* defined(__MonsterHunter__YHDataManagerImp__) */














































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


