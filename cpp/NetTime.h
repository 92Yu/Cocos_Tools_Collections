#define __NETTIME_H___
#ifdef __NETTIME_H___

#include "cocos2d.h"
#include "network/HttpClient.h"
USING_NS_CC;
using namespace network;

class NetTime : public Node
{
public:
	NetTime();
	~NetTime();
	CREATE_FUNC(NetTime);

	CC_SYNTHESIZE(int, nDay, Day);
	CC_SYNTHESIZE(int, nMonth, Month);
	CC_SYNTHESIZE(int, nYear, Year);
	CC_SYNTHESIZE(int, nHour, Hour);
	CC_SYNTHESIZE(int, nMinute, Minute);
	CC_SYNTHESIZE(int, nSecond, Second);
	CC_SYNTHESIZE(time_t, tTime, Time);

	void onRequestTime();

	static void splitString(std::vector<std::string> &contentVector, std::string content, std::string pattern);

	void onHttpComplete(HttpClient * sender, HttpResponse * response);
	void spliteTime(std::string htmlStr);
	void initTime(time_t time);

	static NetTime* getInstance();
	static NetTime* pInstance;

};

#endif

