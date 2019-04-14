// Test.h : Declaration of the CTest

#pragma once
#include "resource.h"       // main symbols



#include "ATLProject2_i.h"
#include "_ITestEvents_CP.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

using namespace ATL;


// CTest

class ATL_NO_VTABLE CTest :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CTest, &CLSID_Test>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CTest>,
	public CProxy_ITestEvents<CTest>,
	public IDispatchImpl<ITest, &IID_ITest, &LIBID_ATLProject2Lib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CTest()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_TEST)


BEGIN_COM_MAP(CTest)
	COM_INTERFACE_ENTRY(ITest)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CTest)
	CONNECTION_POINT_ENTRY(__uuidof(_ITestEvents))
END_CONNECTION_POINT_MAP()
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:



  STDMETHOD(PutString)(BSTR str);
  STDMETHOD(GetString)(BSTR* str);
  STDMETHOD(FindLines)(BSTR path, BSTR reg, BSTR* str);
  STDMETHOD(FindFiles)(BSTR path, BSTR reg, BSTR* str);
  STDMETHOD(FindAllFiles)(BSTR path, BSTR reg, BSTR* str);
  STDMETHOD(GetFileList)(VARIANT* sFileList);
};

OBJECT_ENTRY_AUTO(__uuidof(Test), CTest)
