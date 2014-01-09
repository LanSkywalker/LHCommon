//--------------------------------------------------------------------------------
// This file is a portion of the LHCommon Library.  It is distributed
// under the MIT License, available in the root of this distribution and 
// at the following URL:
//
// http://www.opensource.org/licenses/mit-license.php
//
// Copyright (c) Carber Lee 
//--------------------------------------------------------------------------------

#pragma once

#if defined(_MSC_VER)
    #include <stdlib.h>
    #include <crtdbg.h>
#else
    #include <assert.h>
#endif

//////////////////////////////////////////////////////////////////////////
#define LH_FAILED_LABEL      LH_FAILED_EXIT:
#define LH_SUCCESS_LABEL     LH_SUCCESS_EXIT:
#define LH_ASSERT(Condition) _ASSERT(Condition)
//////////////////////////////////////////////////////////////////////////
#define LH_ASSERT_EXIT(Condition)           \
    if (!(Condition))                       \
    {                                       \
        LH_ASSERT(Condition);               \
        goto LH_FAILED_LABEL;               \
    }
#define LH_PROCESS_EXIT(Condition)          \
    if (!(Condition))                       \
    {                                       \
        goto LH_FAILED_LABEL;               \
    }
#define LH_PROCESS_SUCCESS(Condition)       \
    if (Condition)                          \
    {                                       \
        goto LH_SUCCESS_LABEL;              \
    }
//////////////////////////////////////////////////////////////////////////
#define LH_COM_ASSERT_EXIT(hrRetCode)       \
    if (FAILED(hrRetCode))                  \
    {                                       \
        LH_ASSERT(SUCCEEDED(hrRetCode));    \
        goto LH_FAILED_LABEL;               \
    }
#define LH_COM_PROCESS_EXIT(hrRetCode)      \
    if (FAILED(Condition))                  \
    {                                       \
        goto LH_FAILED_LABEL;               \
    }
#define LH_COM_PROCESS_SUCCESS(hrRetCode)   \
    if (SUCCEEDED(hrRetCode))               \
    {                                       \
        goto LH_SUCCESS_LABEL;              \
    }
//////////////////////////////////////////////////////////////////////////
#define LH_USE_ARGUMENT(arg) UNREFERENCED_PARAMETER(arg)
#define LH_WIDE_TEXT _CRT_WIDE
#define LH_FUNCTION LH_WIDE_TEXT(__FUNCTION__)
//////////////////////////////////////////////////////////////////////////
#define LH_RELEASE(pInterface)              \
    if (pInterface)                         \
    {                                       \
        (pInterface)->Release();            \
        (pInterface) = NULL;                \
    }
#define LG_RELEASE_LAST(pInterface)         \
    if (pInterface)                         \
    {                                       \
        ULONG ulRef =(pInterface)->Release(); \
        (pInterface) = NULL;                \
        LH_USE_ARGUMENT(ulRef);             \
        LH_ASSERT(ulRef == 0);              \
    }
#define LH_DELETE(pObject)                  \
    if (pObject)                            \
    {                                       \
        delete (pObject)                    \
        (pObject) = NULL;                   \
    }
#define LH_DELETE_ARRAY(pArray)             \
    if (pArray)                             \
    {                                       \
        delete[] (pArray)                   \
        (pArray) = NULL;                    \
    }