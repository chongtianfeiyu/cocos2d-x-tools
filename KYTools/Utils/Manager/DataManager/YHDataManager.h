//
//  YHDataManager.h
//  MonsterHunter
//
//  Created by Zhenyu Yao on 14-1-9.
//
//

#ifndef __MonsterHunter__YHDataManager__
#define __MonsterHunter__YHDataManager__

#include <KYTools/Utils/Common/YHAbstractDataSetting.h>

class YHByteArray;
class YHDataManagerImp;

/**
 * 游戏数据装载/管理器
 * @author Zhenyu Yao
 */
class YHDataManager : public YHObject
{
public:
	
	/**
	 * 创建 YHDataManager 对象
	 * @param type 类型
	 */
	static YHDataManager * create(const std::string & type = "Default");
	
	YHDataManager();
	virtual ~YHDataManager();
	
	/// 初始化
	virtual bool init(YHDataManagerImp * imp);
	
	/**
	 * 添加文件
	 * @param file 待装载的文件
	 */
	virtual void addFile(const std::string & file);
	
	/**
	 * 移除文件. 无论文件已经装载还是没有装载, 都将移除. 如果已经装载, 那么其关联的文件一并移除.
	 * @param file 将要移除的文件
	 */
	virtual void removeFile(const std::string & file);
	
	/**
	 * 移除所有的文件. 无论文件已经装载还是没有装载, 都将移除. 如果已经装载, 那么其关联的文件一并移除.
	 */
	virtual void removeAllFiles();
	
	/**
	 * 开始装载. 如果已经在装载, 那么调用该函数将不会起到任何作用
	 */
	virtual void start();
	
	/**
	 * 停止装载.
	 */
	virtual void stop();
	
	/**
	 * 判断是否文件是否装载完成
	 * @return true 完成, false 没有
	 */
	virtual bool completed();
	
	/**
	 * 根据文件得到已经装载好的 YHByteArray 对象
	 * @param file 之前加入的装载文件
	 */
	virtual YHByteArray * bytesForFile(const std::string & file);
	
	/**
	 * 根据文件得到已经装载好的 CCTexture2D 对象
	 * @param file 之前加入的装载文件
	 */
	virtual cocos2d::CCTexture2D * textureForFile(const std::string & file);
	
	/**
	 * 根据文件得到已经装载好的 CCDictionary 对象
	 * @param file 之前加入的装载文件
	 */
	virtual cocos2d::CCDictionary * dictionaryForFile(const std::string & file);
	
	/**
	 * 根据文件得到已经装载好的 CCArray 对象
	 * @param file 之前加入的装载文件
	 */
	virtual cocos2d::CCArray * arrayForFile(const std::string & file);
	
private:
	
	YHDataManagerImp * m_imp;
};

#endif /* defined(__MonsterHunter__YHDataManager__) */














































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


