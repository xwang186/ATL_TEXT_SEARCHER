// FileMng.cpp : Implementation of CFileMng
#include "stdafx.h"
#include "FileMng.h"

#include <string>
#include "Utilities.h"
#include "Searcher.h"
#include<vector>
using namespace std;
using namespace ATL;

// CFileMng

STDMETHODIMP CFileMng::GetFileList(BSTR path, BSTR regu,VARIANT* sFileList)
{
	SAFEARRAY* psa;
	SAFEARRAYBOUND rgsabound[1];
	VARIANT var;
	CComBSTR bstrTmp;
	long nIndex=0;
	rgsabound[0].lLbound = 0;

	Searcher searcher;
	vector<string> result;
	searcher.GetMatchedFiles(Utilities::ConvertBSTRToMBS(path), Utilities::ConvertBSTRToMBS(regu), result);
	int size = result.size();
	rgsabound[0].cElements = size;
	psa = SafeArrayCreate(VT_BSTR, 1, rgsabound);
	for (string i:result) {
		bstrTmp= Utilities::ConvertMBSToBSTR(i);
		SafeArrayPutElement(psa, &nIndex, bstrTmp);
		nIndex++;
	}

	/*
	for (long i = 0; i < size; i++)
	{
		bstrTmp = Utilities::ConvertMBSToBSTR(result.front());
		result.pop_back();
		SafeArrayPutElement(psa, &i, bstrTmp);
	}
	
	nIndex = 0;
	bstrTmp = "Test01";
	SafeArrayPutElement(psa, &nIndex, bstrTmp);
	nIndex = 1;
	bstrTmp = "Test02";
	SafeArrayPutElement(psa, &nIndex, bstrTmp);
	*/
	var.vt = VT_BSTR | VT_ARRAY;
	var.parray = psa;
	*sFileList = var;
	
	return  S_OK;
}