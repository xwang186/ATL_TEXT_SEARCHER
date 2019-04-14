#pragma once
#include<string>
class Utilities
{
public:
	Utilities();
	~Utilities();
	static std::string ConvertBSTRToMBS(BSTR bstr);
	static std::string ConvertWCSToMBS(const wchar_t* pstr, long wslen);
	static BSTR ConvertMBSToBSTR(const std::string& str);
};

