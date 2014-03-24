
#include <KYTools/Utils/Manager/YHFontManager.h>
#include <KYTools/YHTypes.h>

USING_NS_CC;

YHFontManager * YHFontManager::defaultFontManager()
{
	static YHFontManager s_instance;
	return &s_instance;
}

void YHFontManager::addFonts(cocos2d::CCDictionary * dict)
{
    CCDictElement * e = nullptr;
    CCDICT_FOREACH(dict, e)
    {
        m_dict->setObject(e->getObject(), e->getStrKey());
    }
}

const char * YHFontManager::fontNameForKey(const char * key)
{
	return (dynamic_cast<CCString *>(m_dict->objectForKey(key)))->getCString();
}

YHFontManager::YHFontManager()
{
    m_dict = new cocos2d::CCDictionary();
    m_dict->init();
}

YHFontManager::~YHFontManager() 
{
	CC_SAFE_RELEASE(m_dict);
}


