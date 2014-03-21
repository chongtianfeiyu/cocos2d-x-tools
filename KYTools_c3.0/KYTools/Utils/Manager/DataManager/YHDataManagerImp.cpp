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

CCObject * YHDataManagerImp::loadFile(const std::string & fullpath)
{
    string suffix = pathExtensionWithString(fullpath);
    
    // 装载对应的对象
    CCObject * obj = NULL;
    if (suffix.compare("plist-array") == 0)
    {
        ValueVector vv = CCFileUtils::getInstance()->getValueVectorFromFile(fullpath);
        CCArray * arr = new CCArray();
        arr->initWithCapacity((ssize_t)vv.size());
        for(const auto & value : vv) {
            arr->addObject(__String::create(value.asString()));
        }
        
        obj = arr;
    }
    else if (suffix.compare("plist-dictionary") == 0)
    {
        obj = CCDictionary::createWithContentsOfFileThreadSafe(fullpath.c_str());
    }
    else if (suffix.compare("png") == 0 || suffix.compare("jpg") == 0 || suffix.compare("jpeg") == 0
             || suffix.compare("tif") == 0 || suffix.compare("tiff") == 0 || suffix.compare("webp") == 0)
    {
        obj = CCTextureCache::sharedTextureCache()->addImage(fullpath.c_str());
        obj->retain();		// 因为 addImage 里面没有 autorelease.
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
        }
    }
    
    return obj;
}












































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


