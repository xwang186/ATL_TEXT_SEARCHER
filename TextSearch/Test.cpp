// Test.cpp : Implementation of CTest

#include "stdafx.h"
#include "Test.h"
#include "_ITestEvents_CP.h"
#include <iostream>
#include <string>
#include "_ITestEvents_CP.h"
#include "Searcher.h"

// CTest
std::string ConvertBSTRToMBS(BSTR bstr);
std::string ConvertWCSToMBS(const wchar_t* pstr, long wslen);
BSTR ConvertMBSToBSTR(const std::string& str);
std::string ConvertBSTRToMBS(BSTR bstr)
{
	int wslen = ::SysStringLen(bstr);
	return ConvertWCSToMBS((wchar_t*)bstr, wslen);
}

std::string ConvertWCSToMBS(const wchar_t* pstr, long wslen)
{
	int len = ::WideCharToMultiByte(CP_ACP, 0, pstr, wslen, NULL, 0, NULL, NULL);

	std::string dblstr(len, '\0');
	len = ::WideCharToMultiByte(CP_ACP, 0 /* no flags */,
		pstr, wslen /* not necessary NULL-terminated */,
		&dblstr[0], len,
		NULL, NULL /* no default char */);

	return dblstr;
}

BSTR ConvertMBSToBSTR(const std::string& str)
{
	int wslen = ::MultiByteToWideChar(CP_ACP, 0 /* no flags */,
		str.data(), str.length(),
		NULL, 0);

	BSTR wsdata = ::SysAllocStringLen(NULL, wslen);
	::MultiByteToWideChar(CP_ACP, 0 /* no flags */,
		str.data(), str.length(),
		wsdata, wslen);
	return wsdata;
}
STDMETHODIMP CTest::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* const arr[] = 
	{
		&IID_ITest
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}


STDMETHODIMP CTest::PutString(BSTR str)
{
  CComBSTR bstr(str);
  std::wcout << "\n  Server received string \"" << bstr.m_str << "\"";
  Fire_Notify(bstr);
  return S_OK;
}


STDMETHODIMP CTest::GetString(BSTR* str)
{
  CComBSTR bstr(L"Server's message for client");
  *str = bstr;
  bstr.Detach();
  return S_OK;
}

STDMETHODIMP CTest::FindLines(BSTR path, BSTR reg, BSTR* str)
{
	string realpath=ConvertBSTRToMBS(path);
	string realreg = ConvertBSTRToMBS(reg);
	Searcher s;
	string result = s.FindLines(realpath,realreg);
	BSTR rep=ConvertMBSToBSTR(result);
	CComBSTR bstr(L"Server's message for client");
	bstr.Append(rep);
	*str = bstr;
	bstr.Detach();
	return S_OK;
}
STDMETHODIMP CTest::FindFiles(BSTR path, BSTR reg, BSTR* str)
{
	string realpath = ConvertBSTRToMBS(path);
	string realreg = ConvertBSTRToMBS(reg);
	Searcher s;
	string result = s.FindFiles(realpath, realreg);
	BSTR rep = ConvertMBSToBSTR(result);
	CComBSTR bstr(L"Server's message for client");
	bstr.Append(rep);
	*str = bstr;
	bstr.Detach();
	return S_OK;
}
STDMETHODIMP CTest::FindAllFiles(BSTR path, BSTR reg, BSTR* str)
{
	string realpath = ConvertBSTRToMBS(path);
	string realreg = ConvertBSTRToMBS(reg);
	Searcher s;
	string result = s.FindAllFiles(realpath, realreg);
	BSTR rep = ConvertMBSToBSTR(result);
	CComBSTR bstr(L"Server's message for client");
	bstr.Append(rep);
	*str = bstr;
	bstr.Detach();
	return S_OK;
}
STDMETHODIMP CTest::GetFileList(VARIANT* sFileList)
{
	SAFEARRAY* psa;
	SAFEARRAYBOUND rgsabound[1];
	VARIANT var;
	CComBSTR bstrTmp;
	long nIndex;
	rgsabound[0].lLbound = 0;
	rgsabound[0].cElements = 2;
	psa = SafeArrayCreate(VT_BSTR, 1, rgsabound);
	nIndex = 0;
	bstrTmp = "Test01";
	SafeArrayPutElement(psa, &nIndex, bstrTmp);
	nIndex = 1;
	bstrTmp = "Test02";
	SafeArrayPutElement(psa, &nIndex, bstrTmp);
	var.vt = VT_BSTR | VT_ARRAY;
	var.parray = psa;
	*sFileList = var;
	return  S_OK;
}