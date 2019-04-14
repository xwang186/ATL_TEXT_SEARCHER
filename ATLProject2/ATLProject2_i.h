

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 22:14:07 2038
 */
/* Compiler settings for ATLProject2.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ATLProject2_i_h__
#define __ATLProject2_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ITest_FWD_DEFINED__
#define __ITest_FWD_DEFINED__
typedef interface ITest ITest;

#endif 	/* __ITest_FWD_DEFINED__ */


#ifndef __IFileMng_FWD_DEFINED__
#define __IFileMng_FWD_DEFINED__
typedef interface IFileMng IFileMng;

#endif 	/* __IFileMng_FWD_DEFINED__ */


#ifndef __ITextSearcher_FWD_DEFINED__
#define __ITextSearcher_FWD_DEFINED__
typedef interface ITextSearcher ITextSearcher;

#endif 	/* __ITextSearcher_FWD_DEFINED__ */


#ifndef ___ITestEvents_FWD_DEFINED__
#define ___ITestEvents_FWD_DEFINED__
typedef interface _ITestEvents _ITestEvents;

#endif 	/* ___ITestEvents_FWD_DEFINED__ */


#ifndef __Test_FWD_DEFINED__
#define __Test_FWD_DEFINED__

#ifdef __cplusplus
typedef class Test Test;
#else
typedef struct Test Test;
#endif /* __cplusplus */

#endif 	/* __Test_FWD_DEFINED__ */


#ifndef __FileMng_FWD_DEFINED__
#define __FileMng_FWD_DEFINED__

#ifdef __cplusplus
typedef class FileMng FileMng;
#else
typedef struct FileMng FileMng;
#endif /* __cplusplus */

#endif 	/* __FileMng_FWD_DEFINED__ */


#ifndef __TextSearcher_FWD_DEFINED__
#define __TextSearcher_FWD_DEFINED__

#ifdef __cplusplus
typedef class TextSearcher TextSearcher;
#else
typedef struct TextSearcher TextSearcher;
#endif /* __cplusplus */

#endif 	/* __TextSearcher_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "shobjidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ITest_INTERFACE_DEFINED__
#define __ITest_INTERFACE_DEFINED__

/* interface ITest */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITest;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("457651B4-5871-4E19-9726-5CE3339E1ABF")
    ITest : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE PutString( 
            /* [in] */ BSTR str) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetString( 
            BSTR *str) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE FindLines( 
            /* [in] */ BSTR str1,
            /* [in] */ BSTR str2,
            BSTR *str) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE FindFiles( 
            /* [in] */ BSTR str1,
            /* [in] */ BSTR str2,
            BSTR *str) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE FindAllFiles( 
            /* [in] */ BSTR str1,
            /* [in] */ BSTR str2,
            BSTR *str) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetFileList( 
            VARIANT *str) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITestVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITest * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITest * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITest * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITest * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITest * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITest * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITest * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *PutString )( 
            ITest * This,
            /* [in] */ BSTR str);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetString )( 
            ITest * This,
            BSTR *str);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *FindLines )( 
            ITest * This,
            /* [in] */ BSTR str1,
            /* [in] */ BSTR str2,
            BSTR *str);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *FindFiles )( 
            ITest * This,
            /* [in] */ BSTR str1,
            /* [in] */ BSTR str2,
            BSTR *str);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *FindAllFiles )( 
            ITest * This,
            /* [in] */ BSTR str1,
            /* [in] */ BSTR str2,
            BSTR *str);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetFileList )( 
            ITest * This,
            VARIANT *str);
        
        END_INTERFACE
    } ITestVtbl;

    interface ITest
    {
        CONST_VTBL struct ITestVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITest_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITest_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITest_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITest_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITest_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITest_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITest_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITest_PutString(This,str)	\
    ( (This)->lpVtbl -> PutString(This,str) ) 

#define ITest_GetString(This,str)	\
    ( (This)->lpVtbl -> GetString(This,str) ) 

#define ITest_FindLines(This,str1,str2,str)	\
    ( (This)->lpVtbl -> FindLines(This,str1,str2,str) ) 

#define ITest_FindFiles(This,str1,str2,str)	\
    ( (This)->lpVtbl -> FindFiles(This,str1,str2,str) ) 

#define ITest_FindAllFiles(This,str1,str2,str)	\
    ( (This)->lpVtbl -> FindAllFiles(This,str1,str2,str) ) 

#define ITest_GetFileList(This,str)	\
    ( (This)->lpVtbl -> GetFileList(This,str) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITest_INTERFACE_DEFINED__ */


#ifndef __IFileMng_INTERFACE_DEFINED__
#define __IFileMng_INTERFACE_DEFINED__

/* interface IFileMng */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IFileMng;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("34fb491a-51b0-4a73-932b-3a57ddf0ad47")
    IFileMng : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetFileList( 
            /* [in] */ BSTR str1,
            /* [in] */ BSTR str2,
            VARIANT *str) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IFileMngVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFileMng * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFileMng * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFileMng * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFileMng * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFileMng * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFileMng * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFileMng * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetFileList )( 
            IFileMng * This,
            /* [in] */ BSTR str1,
            /* [in] */ BSTR str2,
            VARIANT *str);
        
        END_INTERFACE
    } IFileMngVtbl;

    interface IFileMng
    {
        CONST_VTBL struct IFileMngVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFileMng_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFileMng_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFileMng_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFileMng_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFileMng_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFileMng_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFileMng_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFileMng_GetFileList(This,str1,str2,str)	\
    ( (This)->lpVtbl -> GetFileList(This,str1,str2,str) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFileMng_INTERFACE_DEFINED__ */


#ifndef __ITextSearcher_INTERFACE_DEFINED__
#define __ITextSearcher_INTERFACE_DEFINED__

/* interface ITextSearcher */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITextSearcher;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("82223877-39b2-45f8-bc91-3cad708f5c3f")
    ITextSearcher : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE FindLines( 
            /* [in] */ BSTR str1,
            /* [in] */ BSTR str2,
            BSTR *str) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITextSearcherVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITextSearcher * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITextSearcher * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITextSearcher * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITextSearcher * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITextSearcher * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITextSearcher * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITextSearcher * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *FindLines )( 
            ITextSearcher * This,
            /* [in] */ BSTR str1,
            /* [in] */ BSTR str2,
            BSTR *str);
        
        END_INTERFACE
    } ITextSearcherVtbl;

    interface ITextSearcher
    {
        CONST_VTBL struct ITextSearcherVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITextSearcher_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITextSearcher_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITextSearcher_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITextSearcher_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITextSearcher_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITextSearcher_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITextSearcher_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITextSearcher_FindLines(This,str1,str2,str)	\
    ( (This)->lpVtbl -> FindLines(This,str1,str2,str) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITextSearcher_INTERFACE_DEFINED__ */



#ifndef __ATLProject2Lib_LIBRARY_DEFINED__
#define __ATLProject2Lib_LIBRARY_DEFINED__

/* library ATLProject2Lib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_ATLProject2Lib;

#ifndef ___ITestEvents_DISPINTERFACE_DEFINED__
#define ___ITestEvents_DISPINTERFACE_DEFINED__

/* dispinterface _ITestEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__ITestEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("21303CFD-EE31-46DC-AF36-7D2AE499194E")
    _ITestEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _ITestEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _ITestEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _ITestEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _ITestEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _ITestEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _ITestEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _ITestEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _ITestEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _ITestEventsVtbl;

    interface _ITestEvents
    {
        CONST_VTBL struct _ITestEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ITestEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _ITestEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _ITestEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _ITestEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _ITestEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _ITestEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _ITestEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___ITestEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Test;

#ifdef __cplusplus

class DECLSPEC_UUID("060FA8F2-43A2-4C1B-B7B7-3BEDB3D4AA5A")
Test;
#endif

EXTERN_C const CLSID CLSID_FileMng;

#ifdef __cplusplus

class DECLSPEC_UUID("d35e9a50-dba7-498e-85f8-587a70b1ed3f")
FileMng;
#endif

EXTERN_C const CLSID CLSID_TextSearcher;

#ifdef __cplusplus

class DECLSPEC_UUID("5d936b77-5215-4e42-b5b6-383d6a23101d")
TextSearcher;
#endif
#endif /* __ATLProject2Lib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

unsigned long             __RPC_USER  BSTR_UserSize64(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal64(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal64(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree64(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize64(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal64(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal64(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree64(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


