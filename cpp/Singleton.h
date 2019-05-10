#pragma once
/*
 * 单例模式模板
 ** 使用时头文件继承此类即可
 *** eg： class XMLParser : public Object, public SAXParser, public Singleton<XMLParser> 
 */
template <class SINGLETON>
class Singleton
{
public:
	Singleton()
	{
		//CCAssert(!ms_pInstance, "Singleton Instance Invalid !!");
		ms_pInstance = static_cast<SINGLETON*>(this);
	}

	~Singleton()
	{
		//CCAssert(ms_pInstance, "Singleton Instance Invalid !!");
		ms_pInstance = 0;
	}

	static SINGLETON*	createInstance()	{ return isInstantiated() ? getInstance() : new SINGLETON; }
	static void			destroyInstance()	{ if (isInstantiated()) delete SINGLETON::getInstance(); ms_pInstance = 0; }
	static SINGLETON*	getInstance()		{ return ms_pInstance; }
	static bool			isInstantiated()	{ return ms_pInstance ? true : false; }

protected:
	static SINGLETON*	ms_pInstance;
};

template <class SINGLETON> SINGLETON*	Singleton<SINGLETON>::ms_pInstance = 0;