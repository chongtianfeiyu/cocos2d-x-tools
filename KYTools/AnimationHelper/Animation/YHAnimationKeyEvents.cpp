//
//  YHAnimationKeyEvents.cpp
//  Demo
//
//  Created by Zhenyu Yao on 14-1-2.
//
//

#include "YHAnimationKeyEvents.h"

USING_NS_CC;

////////////////////////////////////////////////////////////////////////////////////////////////////
// YHAnimationKeyEventsInternalObject
////////////////////////////////////////////////////////////////////////////////////////////////////

YHAnimationKeyEventsInternalObject::YHAnimationKeyEventsInternalObject() : m_keyEvents(NULL)
{
}

YHAnimationKeyEventsInternalObject::~YHAnimationKeyEventsInternalObject()
{
}

void YHAnimationKeyEventsInternalObject::onCallFuncOHandle(cocos2d::CCObject * object)
{
	m_keyEvents->onCallFuncOHandle(object);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
// YHAnimationKeyEvents
////////////////////////////////////////////////////////////////////////////////////////////////////

YHAnimationKeyEvents::YHAnimationKeyEvents() : m_node(NULL), m_delegate(NULL), m_action(NULL), m_internalObject(NULL)
{
}

YHAnimationKeyEvents::~YHAnimationKeyEvents()
{
	CC_SAFE_RELEASE_NULL(m_action);
	CC_SAFE_RELEASE_NULL(m_internalObject);
}

bool YHAnimationKeyEvents::init(cocos2d::CCAnimation * animation, bool loop)
{
	assert(animation != NULL);
	
	m_internalObject = new YHAnimationKeyEventsInternalObject();
	m_internalObject->setKeyEvents(this);
	
	float duration = animation->getDelayPerUnit();
	CCArray * actions = CCArray::create();
	CCArray * frames = animation->getFrames();
	uint32 index = 0;
	float elapse = 0.0f;
	float lastTime = 0.0f;
	CCObject * obj = NULL;
	CCARRAY_FOREACH(frames, obj)
	{
		CCAnimationFrame * frame = (CCAnimationFrame *)obj;
		if (frame->getUserInfo() != NULL)
		{
			if (index != 0)
			{
				CCDelayTime * delay = CCDelayTime::create(elapse - lastTime);
				actions->addObject(delay);
				lastTime = elapse;
			}
			
			CCCallFuncO * callFuncO = CCCallFuncO::create(m_internalObject,
														  callfuncO_selector(YHAnimationKeyEventsInternalObject::onCallFuncOHandle),
														  frame->getUserInfo());
			actions->addObject(callFuncO);
		}
		
		elapse += frame->getDelayUnits() * duration;
		++index;
	}
	
	if (actions->count() != 0)
	{
		// 补齐动画
		CCDelayTime * delay = CCDelayTime::create(elapse - lastTime);
		actions->addObject(delay);
		
		CCSequence * sequence = CCSequence::create(actions);
		if (loop)
			m_action = CCRepeatForever::create(sequence);
		else
		{
			if (animation->getLoops() > 1)
				m_action = CCRepeat::create(sequence, animation->getLoops());
			else
				m_action = sequence;
		}
		CC_SAFE_RETAIN(m_action);
	}
	
	return true;
}

void YHAnimationKeyEvents::onCallFuncOHandle(cocos2d::CCObject * object)
{
	if (m_delegate != NULL)
	{
		m_delegate->handleKeyEvent(m_node, (CCDictionary *)object);
	}
}













































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


