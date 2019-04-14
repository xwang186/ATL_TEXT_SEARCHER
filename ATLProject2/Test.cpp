// Test.cpp : Implementation of CTest

#include "stdafx.h"
#include "Test.h"
#include "_ITestEvents_CP.h"
#include <iostream>
#include <string>
#include "_ITestEvents_CP.h"
#include "Searcher.h"
#include "Utilities.h"

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
	string realpath= Utilities::ConvertBSTRToMBS(path);
	string realreg = Utilities::ConvertBSTRToMBS(reg);
	Searcher s;
	string result = s.FindLines(realpath,realreg);
	BSTR rep= Utilities::ConvertMBSToBSTR(result);
	CComBSTR bstr(L"Server's message for client");
	bstr.Append(rep);
	*str = bstr;
	bstr.Detach();
	return S_OK;
}
STDMETHODIMP CTest::FindFiles(BSTR path, BSTR reg, BSTR* str)
{
	string realpath = Utilities::ConvertBSTRToMBS(path);
	string realreg = Utilities::ConvertBSTRToMBS(reg);
	Searcher s;
	string result = s.FindFiles(realpath, realreg);
	BSTR rep = Utilities::ConvertMBSToBSTR(result);
	CComBSTR bstr(L"Server's message for client");
	bstr.Append(rep);
	*str = bstr;
	bstr.Detach();
	return S_OK;
}
STDMETHODIMP CTest::FindAllFiles(BSTR path, BSTR reg, BSTR* str)
{
	string realpath = Utilities::ConvertBSTRToMBS(path);
	string realreg = Utilities::ConvertBSTRToMBS(reg);
	Searcher s;
	string result = s.FindAllFiles(realpath, realreg);
	BSTR rep = Utilities::ConvertMBSToBSTR(result);
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