//
//  YHJsonHelper.cpp
//  MonsterHunter
//
//  Created by Zhenyu Yao on 14-1-9.
//
//

#include <KYTools/Utils/Common/YHJsonHelper.h>

USING_NS_CC;

using namespace Json;

static void parseFromJsonToArray(const Json::Value & jsonNode, CCArray * arrayNode);
static void parseFromJsonToDictionary(const Json::Value & jsonNode, CCDictionary * dictNode);

////////////////////////////////////////////////////////////////////////////////////////////////////
// Private Functions
////////////////////////////////////////////////////////////////////////////////////////////////////

/// 从 Json 解析数据到 dictNode 中
static void parseFromJsonToDictionary(const Json::Value & jsonNode, CCDictionary * dictNode)
{
	Json::Value::Members members = jsonNode.getMemberNames();
	for (Json::Value::Members::iterator beg = members.begin(); beg != members.end(); ++beg)
	{
        std::string name = *beg;
		Json::Value child = jsonNode[name];
		
		if (child.isArray())
		{
			CCArray * arr = CCArray::create();
			parseFromJsonToArray(child, arr);
			dictNode->setObject(arr, name);
		}
		else if (child.isObject())
		{
			CCDictionary * dict = CCDictionary::create();
			parseFromJsonToDictionary(child, dict);
			dictNode->setObject(dict, name);
		}
		else if (child.isString())
		{
			CCString * str = CCString::createWithFormat("%s", child.asCString());
			dictNode->setObject(str, name);
		}
		else if (child.isInt())
		{
			CCString * str = CCString::createWithFormat("%d", child.asInt());
			dictNode->setObject(str, name);
		}
		else if (child.isUInt())
		{
			CCString * str = CCString::createWithFormat("%u", child.asUInt());
			dictNode->setObject(str, name);
		}
		else if (child.isInt64())
		{
			CCString * str = CCString::createWithFormat("%lld", child.asInt64());
			dictNode->setObject(str, name);
			
		}
		else if (child.isUInt64())
		{
			CCString * str = CCString::createWithFormat("%llu", child.asUInt64());
			dictNode->setObject(str, name);
		}
		else if (child.isDouble())
		{
			CCString * str = CCString::createWithFormat("%f", child.asDouble());
			dictNode->setObject(str, name);
		}
		else if (child.isBool())
		{
			CCString * str = CCString::createWithFormat("%d", child.asInt());
			dictNode->setObject(str, name);
		}
	}
}

/// 从 Json 解析数据到 arrayNode 中
static void parseFromJsonToArray(const Json::Value & jsonNode, CCArray * arrayNode)
{
	for (ValueIterator beg = jsonNode.begin(); beg != jsonNode.end(); ++beg)
	{
		const Json::Value & child = *beg;
		if (child.isArray())
		{
			CCArray * arr = CCArray::create();
			parseFromJsonToArray(child, arr);
			arrayNode->addObject(arr);
		}
		else if (child.isObject())
		{
			CCDictionary * dict = CCDictionary::create();
			parseFromJsonToDictionary(child, dict);
			arrayNode->addObject(dict);
		}
		else if (child.isString())
		{
			arrayNode->addObject(CCString::createWithFormat("%s", child.asCString()));
		}
		else if (child.isInt())
		{
			arrayNode->addObject(CCString::createWithFormat("%d", child.asInt()));
		}
		else if (child.isUInt())
		{
			arrayNode->addObject(CCString::createWithFormat("%u", child.asUInt()));
		}
		else if (child.isInt64())
		{
			arrayNode->addObject(CCString::createWithFormat("%lld", child.asInt64()));
		}
		else if (child.isUInt64())
		{
			arrayNode->addObject(CCString::createWithFormat("%llu", child.asUInt64()));
		}
		else if (child.isDouble())
		{
			arrayNode->addObject(CCString::createWithFormat("%f", child.asDouble()));
		}
		else if (child.isBool())
		{
			arrayNode->addObject(CCString::createWithFormat("%d", child.asInt()));
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// Public Functions
////////////////////////////////////////////////////////////////////////////////////////////////////

CCDictionary * dictionaryFromJson(const Json::Value & root)
{
	if (!root.isObject())
		return NULL;
	
	CCDictionary * dictRoot = CCDictionary::create();
	parseFromJsonToDictionary(root, dictRoot);
	return dictRoot;
}

CCArray * arrayFromJson(const Json::Value & root)
{
	if (!root.isArray())
		return NULL;
	
	CCArray * arrayRoot = CCArray::create();
	parseFromJsonToArray(root, arrayRoot);
	return arrayRoot;
}

Json::Value jsonFromDictionary(CCDictionary * root)
{
	if (root == NULL)
		return Json::Value::null;
	
	Json::Value jsonNode;
	CCDictElement * e = NULL;
	CCDICT_FOREACH(root, e)
	{
		if (dynamic_cast<CCArray *>(e->getObject()) != NULL)
		{
			Json::Value jsonChild = jsonFromArray((CCArray *)e->getObject());
			jsonNode[e->getStrKey()] = jsonChild;
		}
		else if (dynamic_cast<CCDictionary *>(e->getObject()) != NULL)
		{
			Json::Value jsonChild = jsonFromDictionary((CCDictionary *)e->getObject());
			jsonNode[e->getStrKey()] = jsonChild;
		}
		else if (dynamic_cast<CCString *>(e->getObject()) != NULL)
		{
			Json::Value jsonChild = Json::Value(((CCString *)e->getObject())->getCString());
			jsonNode[e->getStrKey()] = jsonChild;
		}
	}
	
	return jsonNode;
}

Json::Value jsonFromArray(CCArray * root)
{
	if (root == NULL)
		return NULL;
	
	Json::Value jsonNode;
	CCObject * obj = NULL;
	CCARRAY_FOREACH(root, obj)
	{
		if (dynamic_cast<CCArray *>(obj) != NULL)
		{
			jsonNode.append(jsonFromArray((CCArray *)obj));
		}
		else if (dynamic_cast<CCDictionary *>(obj) != NULL)
		{
			jsonNode.append(jsonFromDictionary((CCDictionary *)obj));
		}
		else if (dynamic_cast<CCString *>(obj) != NULL)
		{
			jsonNode.append(Json::Value(((CCString *)obj)->getCString()));
		}
	}
	
	return jsonNode;
}

ValueMap valueMapFromDictionary(CCDictionary * root)
{
    assert(root != NULL);
    
    ValueMap map;
    CCDictElement * e = NULL;
    CCDICT_FOREACH(root, e)
    {
        CCObject * obj = e->getObject();
        if (dynamic_cast<CCString *>(obj) != NULL)
        {
            CCString * str = (CCString *)obj;
            map[e->getStrKey()] = cocos2d::Value(str->getCString());
        }
        else if (dynamic_cast<CCFloat *>(obj) != NULL)
        {
            CCFloat * val = (CCFloat *)obj;
            map[e->getStrKey()] = cocos2d::Value(val->getValue());
        }
        else if (dynamic_cast<CCDouble *>(obj) != NULL)
        {
            CCDouble * val = (CCDouble *)obj;
            map[e->getStrKey()] = cocos2d::Value(val->getValue());
        }
        else if (dynamic_cast<CCInteger *>(obj) != NULL)
        {
            CCInteger * val = (CCInteger *)obj;
            map[e->getStrKey()] = cocos2d::Value(val->getValue());
        }
        else if (dynamic_cast<CCBool *>(obj) != NULL)
        {
            CCBool * val = (CCBool *)obj;
            map[e->getStrKey()] = cocos2d::Value(val->getValue());
        }
        else if (dynamic_cast<CCDictionary *>(obj) != NULL)
        {
            CCDictionary * dict = (CCDictionary *)obj;
            map[e->getStrKey()] = cocos2d::Value(valueMapFromDictionary(dict));
        }
        else if (dynamic_cast<CCArray *>(obj) != NULL)
        {
            CCArray * arr = (CCArray *)obj;
            map[e->getStrKey()] = cocos2d::Value(valueVectorFromArray(arr));
        }
    }
    
    return map;
}

ValueVector valueVectorFromArray(CCArray * root)
{
    assert(root != NULL);
    
    ValueVector vec;
    CCObject * obj = NULL;
    CCARRAY_FOREACH(root, obj)
    {
        if (dynamic_cast<CCString *>(obj) != NULL)
        {
            CCString * str = (CCString *)obj;
            vec.push_back(cocos2d::Value(str->getCString()));
        }
        else if (dynamic_cast<CCFloat *>(obj) != NULL)
        {
            CCFloat * val = (CCFloat *)obj;
            vec.push_back(cocos2d::Value(val->getValue()));
        }
        else if (dynamic_cast<CCDouble *>(obj) != NULL)
        {
            CCDouble * val = (CCDouble *)obj;
            vec.push_back(cocos2d::Value(val->getValue()));
        }
        else if (dynamic_cast<CCInteger *>(obj) != NULL)
        {
            CCInteger * val = (CCInteger *)obj;
            vec.push_back(cocos2d::Value(val->getValue()));
        }
        else if (dynamic_cast<CCBool *>(obj) != NULL)
        {
            CCBool * val = (CCBool *)obj;
            vec.push_back(cocos2d::Value(val->getValue()));
        }
        else if (dynamic_cast<CCDictionary *>(obj) != NULL)
        {
            CCDictionary * dict = (CCDictionary *)obj;
            vec.push_back(cocos2d::Value(valueMapFromDictionary(dict)));
        }
        else if (dynamic_cast<CCArray *>(obj) != NULL)
        {
            CCArray * arr = (CCArray *)obj;
            vec.push_back(cocos2d::Value(valueVectorFromArray(arr)));
        }
    }
    
    return vec;
}








































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


