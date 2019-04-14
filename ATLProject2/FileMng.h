// FileMng.h : Declaration of the CFileMng

#pragma once
#include "resource.h"       // main symbols



#include "ATLProject2_i.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CFileMng

class ATL_NO_VTABLE CFileMng :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFileMng, &CLSID_FileMng>,
	public IDispatchImpl<IFileMng, &IID_IFileMng, &LIBID_ATLProject2Lib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CFileMng()
	{

	}

DECLARE_REGISTRY_RESOURCEID(107)


BEGIN_COM_MAP(CFileMng)
	COM_INTERFACE_ENTRY(IFileMng)
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
	STDMETHOD(GetFileList)(BSTR path, BSTR regu,VARIANT* sFileList);


};

OBJECT_ENTRY_AUTO(__uuidof(FileMng), CFileMng)
