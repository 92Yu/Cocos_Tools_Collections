#ifndef __Tools_h__
#define __Tools_h__

#include <string>

namespace HN
{
	class Tools
	{
	public:
		static bool verifyEmailAddress(const std::string& email);
		static bool verifyPhone(const std::string& phone);
		static bool verifyChinese(const std::string& word);
		static bool verifyNumber(const std::string& word);
		static bool verifyNumberAndEnglish(const std::string& word);
	};
}


#endif // __Tools_h__