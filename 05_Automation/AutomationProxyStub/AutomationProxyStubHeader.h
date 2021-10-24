

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 08:44:07 2038
 */
/* Compiler settings for AutomationServerTypeLib.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
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

#ifndef __AutomationProxyStubHeader_h__
#define __AutomationProxyStubHeader_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IMyMath_FWD_DEFINED__
#define __IMyMath_FWD_DEFINED__
typedef interface IMyMath IMyMath;

#endif 	/* __IMyMath_FWD_DEFINED__ */


#ifndef __CMyMath_FWD_DEFINED__
#define __CMyMath_FWD_DEFINED__

#ifdef __cplusplus
typedef class CMyMath CMyMath;
#else
typedef struct CMyMath CMyMath;
#endif /* __cplusplus */

#endif 	/* __CMyMath_FWD_DEFINED__ */


/* header files for imported files */
#include "unknwn.h"
#include "oaidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IMyMath_INTERFACE_DEFINED__
#define __IMyMath_INTERFACE_DEFINED__

/* interface IMyMath */
/* [oleautomation][dual][unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IMyMath;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("887C1A49-67B9-4856-8909-B7E3A1907522")
    IMyMath : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SumOfTwoIntegers( 
            /* [in] */ int __MIDL__IMyMath0000,
            /* [in] */ int __MIDL__IMyMath0001,
            /* [retval][out] */ int *__MIDL__IMyMath0002) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SubtractionOfTwoIntegers( 
            /* [in] */ int __MIDL__IMyMath0003,
            /* [in] */ int __MIDL__IMyMath0004,
            /* [retval][out] */ int *__MIDL__IMyMath0005) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IMyMathVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMyMath * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMyMath * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMyMath * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMyMath * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMyMath * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMyMath * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMyMath * This,
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
        
        HRESULT ( STDMETHODCALLTYPE *SumOfTwoIntegers )( 
            IMyMath * This,
            /* [in] */ int __MIDL__IMyMath0000,
            /* [in] */ int __MIDL__IMyMath0001,
            /* [retval][out] */ int *__MIDL__IMyMath0002);
        
        HRESULT ( STDMETHODCALLTYPE *SubtractionOfTwoIntegers )( 
            IMyMath * This,
            /* [in] */ int __MIDL__IMyMath0003,
            /* [in] */ int __MIDL__IMyMath0004,
            /* [retval][out] */ int *__MIDL__IMyMath0005);
        
        END_INTERFACE
    } IMyMathVtbl;

    interface IMyMath
    {
        CONST_VTBL struct IMyMathVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMyMath_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMyMath_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMyMath_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMyMath_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMyMath_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMyMath_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMyMath_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMyMath_SumOfTwoIntegers(This,__MIDL__IMyMath0000,__MIDL__IMyMath0001,__MIDL__IMyMath0002)	\
    ( (This)->lpVtbl -> SumOfTwoIntegers(This,__MIDL__IMyMath0000,__MIDL__IMyMath0001,__MIDL__IMyMath0002) ) 

#define IMyMath_SubtractionOfTwoIntegers(This,__MIDL__IMyMath0003,__MIDL__IMyMath0004,__MIDL__IMyMath0005)	\
    ( (This)->lpVtbl -> SubtractionOfTwoIntegers(This,__MIDL__IMyMath0003,__MIDL__IMyMath0004,__MIDL__IMyMath0005) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMyMath_INTERFACE_DEFINED__ */



#ifndef __AutomationServerWithRegFileTypeLib_LIBRARY_DEFINED__
#define __AutomationServerWithRegFileTypeLib_LIBRARY_DEFINED__

/* library AutomationServerWithRegFileTypeLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_AutomationServerWithRegFileTypeLib;

EXTERN_C const CLSID CLSID_CMyMath;

#ifdef __cplusplus

class DECLSPEC_UUID("91174673-170D-4E28-A38E-F8D6570C5FA9")
CMyMath;
#endif
#endif /* __AutomationServerWithRegFileTypeLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


