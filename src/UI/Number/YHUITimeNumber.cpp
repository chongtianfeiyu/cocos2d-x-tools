
#include <UI/Number/YHUITimeNumber.h>
#include <UI/Number/YHUISpriteNumber.h>

USING_NS_CC;

/// 图层定义
typedef enum
{
	kTimeNumberLayer_Separator,
	kTimeNumberLayer_Number,
	
}TimeNumberLayer;


YHUITimeNumber::YHUITimeNumber(void)
{
}


YHUITimeNumber::~YHUITimeNumber(void)
{
    this->cleanup();
}

float YHUITimeNumber::contentWidth()
{
    float32 width = 0.0f;
    float32 halfFontSize = m_fontSize.width * 0.5f;
    
    // 计算 Icon -> Hour
    if (m_icon != nullptr)
    {
        width += m_icon->getContentSize().width * m_icon->getAnchorPoint().x;
        width += m_iconInterval;
    }
    
    // 计算 Hour
    width += m_hourNumber->getNumberFontWidth() - halfFontSize;
    
    // 计算 Hour -> IconHour
    width += m_hourSeparatorInterval - halfFontSize;
    
    // 计算 IconHour -> Min
    width += m_hourSeparatorInterval - halfFontSize;
    
    // 计算 Min
    width += m_minNumber->getNumberFontWidth();
    
    // 计算 Min -> IconMin
    width += m_minSeparatorInterval - halfFontSize;
    
    // 计算 IconMin -> Sec
    width += m_minSeparatorInterval - halfFontSize;
    
    // 计算 Sec
    width += m_secNumber->getNumberFontWidth();
    
    return width;
}

YHUITimeNumber* YHUITimeNumber::create(cocos2d::CCSprite * iconHour, float hourInterval,
                                       cocos2d::CCSprite * iconMin, float minInterval,
                                       const std::string & fontName, const cocos2d::CCSize & fontSize,
                                       float fontInterval)
{
	YHUITimeNumber* instance = new YHUITimeNumber();
	if ( instance && instance->init(iconHour, hourInterval,
									iconMin, minInterval,
									fontName, fontSize,
									fontInterval))
	{
		instance->autorelease();
		return instance;
	}
	CC_SAFE_DELETE(instance);
	return NULL;
}

bool YHUITimeNumber::init(cocos2d::CCSprite * iconHour, float hourInterval,
                          cocos2d::CCSprite * iconMin, float minInterval,
                          const std::string & fontName, const cocos2d::CCSize & fontSize,
                          float fontInterval)
{
	bool bRet = false;
	do
	{
		CC_BREAK_IF(!CCSprite::init());
		this->setTexture(iconHour->getTexture());
        
		m_iconHour = iconHour;
		m_iconMin = iconMin;
		addChild(m_iconHour, kTimeNumberLayer_Separator);
		addChild(m_iconMin, kTimeNumberLayer_Separator);
		
		m_hourSeparatorInterval = hourInterval;
		m_minSeparatorInterval = minInterval;
		
		m_hourNumber = YHUISpriteNumber::create(fontName.c_str(), fontSize, fontInterval);
		m_minNumber = YHUISpriteNumber::create(fontName.c_str(), fontSize, fontInterval);
		m_secNumber = YHUISpriteNumber::create(fontName.c_str(), fontSize, fontInterval);
		
        m_hourNumber->setAlignType(YHISpriteNumber::kAlignType_Left);
        m_minNumber->setAlignType(YHISpriteNumber::kAlignType_Left);
        m_secNumber->setAlignType(YHISpriteNumber::kAlignType_Left);
        
		addChild(m_hourNumber, kTimeNumberLayer_Number);
		addChild(m_minNumber, kTimeNumberLayer_Number);
		addChild(m_secNumber, kTimeNumberLayer_Number);
		
        m_fontSize = fontSize;
        m_iconInterval = fontInterval;
        
		setTimeWithSecond(0);
		
		bRet = true;
	} while (0);
	
	return bRet;
}

void YHUITimeNumber::setTimeWithSecond(uint32 second, bool zerofill)
{
	int hour = second / 3600;
	int min = (second - hour * 3600) / 60;
	int sec = (second - hour * 3600 - min * 60);
	
    if (!zerofill)
    {
        m_hourNumber->setNumber(hour);
        m_minNumber->setNumber(min);
        m_secNumber->setNumber(sec);
    }
    else
    {
        char buf[8] = {0, };
        sprintf(buf, "%02d", hour);
        m_hourNumber->setNumber(buf);
        
        sprintf(buf, "%02d", min);
        m_minNumber->setNumber(buf);
        
        sprintf(buf, "%02d", sec);
        m_secNumber->setNumber(buf);
    }
	
    layout();
}

void YHUITimeNumber::setTimeWithMilliSecond(uint32 milliSecond, bool zerofill)
{
	uint32 second = milliSecond / 1000;
	setTimeWithSecond(second, zerofill);
}

void YHUITimeNumber::setIcon(cocos2d::CCSprite * icon)
{
    if (m_icon != nullptr)
    {
        m_icon->removeFromParentAndCleanup(true);
    }
    
    m_icon = icon;
    
    if (m_icon != nullptr)
    {
        this->addChild(m_icon, kTimeNumberLayer_Separator);
    }
    
    layout();
}

void YHUITimeNumber::setIconInterval(float32 interval)
{
    m_iconInterval = interval;
    layout();
}

void YHUITimeNumber::setAlignType(YHISpriteNumber::AlignType alignType)
{
    m_alignType = alignType;
    layout();
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// Private Functions
////////////////////////////////////////////////////////////////////////////////////////////////////

void YHUITimeNumber::layout()
{
    float32 beginX = 0.0f;
    
    if (m_icon != nullptr)
    {
        beginX += m_icon->getContentSize().width * m_icon->getAnchorPoint().x;
    }
    else
    {
        beginX += m_fontSize.width * 0.5f;
    }
    
    switch (m_alignType)
    {
        case YHISpriteNumber::kAlignType_Left:
            break;
        case YHISpriteNumber::kAlignType_Center:
            beginX -= contentWidth() * 0.5f;
            break;
        case YHISpriteNumber::kAlignType_Right:
            beginX -= contentWidth();
            break;
    }
    
    Point cursor(beginX, 0.0f);
    
    // Icon
    if (m_icon != nullptr)
    {
        m_icon->setPosition(cursor);
        cursor.x += m_iconInterval;
    }
    
    // Hour
    m_hourNumber->setPosition(cursor);
    cursor.x += m_hourNumber->getNumberFontWidth() - m_fontSize.width * 0.5f + m_hourSeparatorInterval;
    
    // Icon Hour
    m_iconHour->setPosition(cursor);
    cursor.x += m_hourSeparatorInterval - m_fontSize.width * 0.5f;
    
    // Min
    m_minNumber->setPosition(cursor);
    cursor.x += m_minNumber->getNumberFontWidth() - m_fontSize.width * 0.5f + m_minSeparatorInterval;
    
    // Icon min
    m_iconMin->setPosition(cursor);
    cursor.x += m_minSeparatorInterval - m_fontSize.width * 0.5f;
    
    // Sec
    m_secNumber->setPosition(cursor);
}












































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


