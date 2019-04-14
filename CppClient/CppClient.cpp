///////////////////////////////////////////////////////////////////////
// CppClient.cpp - demonstrate how to build C++ client for ATL demo  //
//                                                                   //
// Jim Fawcett, CSE775 - Distributed Objects, Spring 2016            //
///////////////////////////////////////////////////////////////////////
/*
* Rebuilding projects in this solution:
* -------------------------------------
* 1. Make sure you are running Visual Studio as administrator.
* 2. Right-click on idl file and select compile.
* 3. Rebuild ATLProject2 and register using Tools > Register Component.
*    This step assumes you've added Register Component to your External Tools.
*    Otherwise you have to navigate to the project debug directory and run
*    regsvr32 ATLProject2.dll.
* 4. Add a COM reference to ATLProjectLib2 for the C# client project.
* 5. The CppClient doesn't need a reference.
* 6. Set whichever client you want to run as startup and go!
*/

#include <atlbase.h>
#include "..\ATLProject2\ATLProject2_i.h"  // declarations generated from ATLProject2.idl by MIDL
/*
 *  Note: - You have to include ATLProject2_i.c in C++ client project.  This file is generated
 *          MIDL from ATLProject2.idl and contains definitions of the component's GUIDs.
 *        - Don't include ATL header Test.h - that's private to the component.
 */
#include <iostream>
#include <atlsafe.h>

///////////////////////////////////////////////////////////////////////
// Implementation of Connection Points sink component for _ITestEvents
// -------------------------------------------------------------------
// - We could have avoided this by creating the sink component
//   with ATL.  
// - When I started this approach seemed like a quicker way.
// - Now I'm not so sure that was a good idea.
//
class Sink : public _ITestEvents
{
  size_t m_dwRefCount;

public:

  //----< callback function >----------------------------------------

  STDMETHODIMP Notify(BSTR str)
  {
    CComBSTR ccb(str);
    std::wcout << "\n  -- Client Notified with string echoed back from server-- " 
               << ccb.m_str;
    ccb.Detach();
    return S_OK;
  }
  //----< IUnknnow Method >------------------------------------------

  HRESULT STDMETHODCALLTYPE QueryInterface(REFIID iid, void**ppvObject)
  {
    if (iid == DIID__ITestEvents)
    {
      m_dwRefCount++;
      *ppvObject = (void *)this;
      return S_OK;
    }
    if (iid == IID_IUnknown)
    {
      m_dwRefCount++;
      *ppvObject = (void *)this;
      return S_OK;
    }
    return E_NOINTERFACE;
  }
  //----< IUnknnow Method >------------------------------------------

  ULONG STDMETHODCALLTYPE AddRef()
  {
    m_dwRefCount++;
    return m_dwRefCount;
  }
  //----< IUnknnow Method >------------------------------------------

  ULONG STDMETHODCALLTYPE Release()
  {
    ULONG l;
    l = m_dwRefCount--;
    if (0 == m_dwRefCount)
      delete this;

    return l;
  }
  //----< stub for IDispatch method >--------------------------------

  HRESULT STDMETHODCALLTYPE GetTypeInfoCount(UINT *pTInfo) 
  { 
    return !S_OK; 
  }
  //----< stub for IDispatch method >--------------------------------

  HRESULT STDMETHODCALLTYPE GetTypeInfo(UINT iTInfo, LCID lcid, ITypeInfo **ppTInfo)
  { 
    return !S_OK; 
  }
  //----< stub for IDispatch method >--------------------------------

  HRESULT STDMETHODCALLTYPE GetIDsOfNames(
    REFIID riid, LPOLESTR* rgszNames, UINT CNames, LCID lcid, DISPID *pId
  )
  { 
    return !S_OK; 
  }
  //----< partial implementation of IDispatch method >---------------
  /*
   *  This is the only IDispatch method used by the connection point implementation
   */
  HRESULT STDMETHODCALLTYPE Invoke(
    DISPID dId, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS *pDis, 
    VARIANT *pVar, EXCEPINFO *pEx, UINT *puArg
  ) 
  { 
    CComVariant var = ((*pDis).rgvarg)[0];
    CComBSTR bstr = var.bstrVal;
    Notify(CComBSTR(bstr));
    return S_OK; 
  }
};

void main()
{
  std::wcout << L"\n  Demonstrating use of ATLProject2 with C++ Client";
  std::wcout << L"\n ==================================================\n";

  HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
  if (!SUCCEEDED(hr))
  {
    std::wcout << L"\n  could not initialize COM";
  }

  try
  {
    // COM wrapper objects should be embedded inside a scope
    // between calls to CoInitialize(Ex) and CoUninitialize
    // so that their destructors get called BEFORE the COM
    // libraries are shut down with CoUninitialize.
    // Doing this inside a try-catch block is a good way to
    // do that, because the wrappers will throw exceptions if
    // calls fail.
    //
    CComQIPtr<ITest> pTest;  // ITest and CLSID_Test are defined in ATLProject2_i.h
    pTest.CoCreateInstance(CLSID_Test);

    if (pTest != 0)
    {
      ///////////////////////////////////////////////////////////
      // this code implements binding our sink to the
      // component's connection point

      HRESULT hr;
      DWORD dwAdvise;  // can use to unAdvise
      IConnectionPointContainer* pCPC;
      hr = pTest->QueryInterface(IID_IConnectionPointContainer, (void**)&pCPC);
      if (SUCCEEDED(hr))
      {
        IConnectionPoint* pCP;
        hr = pCPC->FindConnectionPoint(DIID__ITestEvents, &pCP);
        if (SUCCEEDED(hr))
        {
          IUnknown* pSinkUnk;
          Sink* pSink = new Sink();

          hr = pSink->QueryInterface(IID_IUnknown, (void**)&pSinkUnk);
          if (SUCCEEDED(hr))
          {
            hr = pCP->Advise(pSinkUnk, &dwAdvise);
          }
          else
          {
            std::cout << "\n  -- Advise failed --";
          }
          pCPC->Release();
        }
        else
        {
          std::cout << "\n  -- FindConnectionPoint failed --";
        }
      }
      else
      {
        std::cout << "\n  -- QueryInterface for connection point container failed --";
      }

      /////////////////////////////////////////////////////////////
      // Now we can use the component and receive callbacks

      pTest->PutString(L"Hi from client");

      ///////////////////////////////////////////////////////////////
      // Using CComBSTR as an [out] parameter
      // - We don't need the call to Empty() here, because we
      //   haven't used returnStr.  However, if returnStr had some
      //   contents we will get a memory leak unless we empty it
      //   before the call.

      CComBSTR returnStr;
      std::wcout << L"\n\n  Length of CComBSTR before [out] call: "
        << returnStr.Length();
      returnStr.Empty();

      pTest->GetString(&returnStr);  // note use of empty CComBSTR

      std::wcout << L"\n  Length of CComBSTR after [out] call:  "
        << returnStr.Length();
      std::wcout << "\n  " << returnStr.Detach();

      ///////////////////////////////////////////////////////////////
      // Using a BSTR as an [out] parameter
      // - we're using an unnecessary allocation before call to
      //   simulate what the CComBSTR is doing.
      // - you always want to supply an unallocated string that
      //   proxy allocates and fills, and you use and deallocate.

      BSTR rStr = SysAllocString(L"");
      std::wcout << L"\n\n  Length of BSTR before [out] call: "
        << SysStringLen(rStr);
      SysFreeString(rStr);

      pTest->GetString(&rStr);  // note use of unallocated BSTR

      std::wcout << L"\n  Length of BSTR after [out] call:  "
        << SysStringLen(rStr);
      std::wcout << "\n  " << rStr;

      SysFreeString(rStr);
    }
    else
    {
      throw std::exception("CoCreateInstance failed");
    }
    // Don't call release with pStrings.  CComQIPtr destructor takes
    // care of that.
  }
  catch (std::exception& ex)
  {
    std::wcout << L"\n  " << ex.what() << L"\n\n";
    return;
  }
  std::wcout << L"\n\n";
  CoUninitialize();
}