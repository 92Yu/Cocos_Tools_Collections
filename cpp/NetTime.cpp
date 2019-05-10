
#include "NetTime.h"

NetTime* NetTime::pInstance = NULL;

NetTime::NetTime() : nDay(0), nMonth(0), nYear(0), nHour(0), nMinute(0), nSecond(0)
{
}

NetTime::~NetTime()
{
}


void NetTime::onRequestTime()
{
	HttpRequest* request = new HttpRequest();
	request->setUrl("http://open.baidu.com/special/time/");//baidu getNetTime api
	request->setRequestType(HttpRequest::Type::GET);
	request->setTag("getNetTime");
	request->setResponseCallback(this, httpresponse_selector(NetTime::onHttpComplete));
	HttpClient::getInstance()->send(request);
}

void NetTime::onHttpComplete(HttpClient * sender, HttpResponse * response)
{
	if (!response)
		return;

	if (0 != strlen(response->getHttpRequest()->getTag()))
	{
		CCLOG("%s  completed", response->getHttpRequest()->getTag());
	}
	int statusCode = response->getResponseCode();
	char statusString[64] = {};
	sprintf_s(statusString, "HTTP Status : %d, tag = %s", statusCode, response->getHttpRequest()->getTag());
	CCLOG("%s", statusString);

	if (!response->isSucceed())
	{
		CCLOG(" response failed !");
		CCLOG(" error buffer is :%s", response->getErrorBuffer());
		return;
	}
	
	std::vector<char> * buffer = response->getResponseData();
	std::string str;
	for (unsigned i = 0; i < buffer->size(); i++)
	{
		char a = (*buffer)[i];
		str.append(1, a);
	}
	spliteTime(str);
}

void NetTime::spliteTime(std::string htmlStr)
{
	std::vector<std::string> tmp;
	splitString(tmp, htmlStr, "baidu_time");

	std::string str = tmp.at(2);
	std::string tmpTime = str.substr(1, 10);
	time_t tt = atoi(tmpTime.c_str());
	initTime(tt);
}

void NetTime::initTime(time_t time)
{
	time_t t;
	struct tm* p;
	t = time;
	p = localtime(&t);

	setSecond(p->tm_sec);
	setMinute(p->tm_min);
	setHour(p->tm_hour);
	setDay(p->tm_mday);
	setMonth(p->tm_mon + 1);
	setYear(p->tm_year + 1900);

	setTime(t);
	log("time is : %d-%d-%d %d:%d:%d", getYear(), getMonth(), getDay(), getHour(), getMinute(), getSecond());
}

//ÇÐ¸î×Ö·û´®
void NetTime::splitString(std::vector<std::string> &contentVector, std::string content, std::string pattern){
	std::string::size_type pos;
	content += pattern;
	int size = content.size();
	for (int i = 0; i < size; i++)
	{
		pos = content.find(pattern, i);
		if (pos < size)
		{
			std::string s = content.substr(i, pos - i);
			contentVector.push_back(s);
			i = pos + pattern.size() - 1;
		}
	}
}

NetTime* NetTime::getInstance()
{
	if (pInstance == NULL)
	{
		pInstance = new NetTime;
	}
	return pInstance;
}
