// TextSearcher.cpp : Implementation of CTextSearcher

#include "stdafx.h"
#include "TextSearcher.h"
#include<string>
#include"Searcher.h"
#include"Utilities.h"

// CTextSearcher

STDMETHODIMP CTextSearcher::FindLines(BSTR path, BSTR reg, BSTR* str)
{
	string realpath = Utilities::ConvertBSTRToMBS(path);
	string realreg = Utilities::ConvertBSTRToMBS(reg);
	Searcher s;
	string result = s.FindLines(realpath, realreg);
	BSTR rep = Utilities::ConvertMBSToBSTR(result);
	CComBSTR bstr("");
	bstr.Append(rep);
	*str = bstr;
	bstr.Detach();
	return S_OK;
}