// TextSearcher.h : Declaration of the CTextSearcher

#pragma once
#include "resource.h"       // main symbols



#include "ATLProject2_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CTextSearcher

class ATL_NO_VTABLE CTextSearcher :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CTextSearcher, &CLSID_TextSearcher>,
	public IDispatchImpl<ITextSearcher, &IID_ITextSearcher, &LIBID_ATLProject2Lib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CTextSearcher()
	{
	}

DECLARE_REGISTRY_RESOURCEID(108)


BEGIN_COM_MAP(CTextSearcher)
	COM_INTERFACE_ENTRY(ITextSearcher)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	STDMETHOD(FindLines)(BSTR path, BSTR reg, BSTR* str);


};

OBJECT_ENTRY_AUTO(__uuidof(TextSearcher), CTextSearcher)
