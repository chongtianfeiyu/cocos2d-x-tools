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

static void parseFromJsonToArray(const Value & jsonNode, CCArray * arrayNode);
static void parseFromJsonToDictionary(const Value & jsonNode, CCDictionary * dictNode);

////////////////////////////////////////////////////////////////////////////////////////////////////
// Private Functions
////////////////////////////////////////////////////////////////////////////////////////////////////

/// 从 Json 解析数据到 dictNode 中
static void parseFromJsonToDictionary(const Value & jsonNode, CCDictionary * dictNode)
{
	Value::Members members = jsonNode.getMemberNames();
	for (Value::Members::iterator beg = members.begin(); beg != members.end(); ++beg)
	{
		string name = *beg;
		Value child = jsonNode[name];
		
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
static void parseFromJsonToArray(const Value & jsonNode, CCArray * arrayNode)
{
	for (ValueIterator beg = jsonNode.begin(); beg != jsonNode.end(); ++beg)
	{
		const Value & child = *beg;
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

CCDictionary * dictionaryFromJson(const Value & root)
{
	if (!root.isObject())
		return NULL;
	
	CCDictionary * dictRoot = CCDictionary::create();
	parseFromJsonToDictionary(root, dictRoot);
	return dictRoot;
}

CCArray * arrayFromJson(const Value & root)
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
		return Value::null;
	
	Value jsonNode;
	CCDictElement * e = NULL;
	CCDICT_FOREACH(root, e)
	{
		if (dynamic_cast<CCArray *>(e->getObject()) != NULL)
		{
			Value jsonChild = jsonFromArray((CCArray *)e->getObject());
			jsonNode[e->getStrKey()] = jsonChild;
		}
		else if (dynamic_cast<CCDictionary *>(e->getObject()) != NULL)
		{
			Value jsonChild = jsonFromDictionary((CCDictionary *)e->getObject());
			jsonNode[e->getStrKey()] = jsonChild;
		}
		else if (dynamic_cast<CCString *>(e->getObject()) != NULL)
		{
			Value jsonChild = Value(((CCString *)e->getObject())->getCString());
			jsonNode[e->getStrKey()] = jsonChild;
		}
	}
	
	return jsonNode;
}

Json::Value jsonFromArray(CCArray * root)
{
	if (root == NULL)
		return NULL;
	
	Value jsonNode;
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
			jsonNode.append(Value(((CCString *)obj)->getCString()));
		}
	}
	
	return jsonNode;
}










































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


