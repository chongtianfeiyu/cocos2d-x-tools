//
//  YHHttpClient.h
//  cocos2d-x-Utils
//
//  Created by Zhenyu Yao on 13-8-15.
//
//

#ifndef __cocos2d_x_Utils__YHHttpClient__
#define __cocos2d_x_Utils__YHHttpClient__

#include <YHTypes.h>
#include <Utils/Buffer/YHByteArray.h>

using namespace cocos2d::network;

/**
 * 对 CCHttpClient 的封装, 将接收到的数据解析为 YHGameLogicData, 放入队列中.
 * @author Zhenyu Yao
 */
class YHHttpClient : public YHObject
{
public:
	
	YHHttpClient();
	~YHHttpClient();
	
	/**
	 * 发送数据
	 * @param data 发送的数据
	 * @param len 发送数据的长度
	 * @param type 发送 http  协议的类型
	 */
	void sendData(YHByteArray * bytes, CCHttpRequest::Type type);
	
	/**
	 * 从接收数据队列中, 得到接收的数据. 调用者必须手动 release 掉返回的 YHByteArray 对象.
	 * @return 从队列中获得的数据
	 */
	YHByteArray * recvData();
	
	/// getter/setter url
	void setURL(const std::string & url)
	{
		m_url = url;
	}
	
	const std::string & getURL() const
	{
		return m_url;
	}
	
	/// getter/setter connect timeout
	void setTimeoutForConnect(int value)
	{
		m_httpClient->setTimeoutForConnect(value);
	}
	
	int getTimeoutForConnect()
	{
		return m_httpClient->getTimeoutForConnect();
	}
	
	/// getter/setter download timeout
	void setTimeoutForRead(int value)
	{
		m_httpClient->setTimeoutForRead(value);
	}
	
	int getTimeoutForRead()
	{
		return m_httpClient->getTimeoutForRead();
	}
	
private:
	
	/// 响应请求的回调函数
	void onResponseCallBack(CCHttpClient * client, CCHttpResponse * response);
	
private:
	
	std::string m_url;
	cocos2d::CCArray * m_queue;
	CCHttpClient * m_httpClient;
};

#endif /* defined(__cocos2d_x_Utils__YHHttpClient__) */














































////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// end file


