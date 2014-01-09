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

#include "LH_Exports.h"
#include "ILH_LogStream.h"

LHCOMMON_API ILH_LogStream *LH_CreateConsoleLogStream(
    const wchar_t *pcszBaseDirectory,
    const wchar_t *pcszExtionDirectory,
    unsigned uMaxLogCount
);
LHCOMMON_API ILH_LogStream *LH_CreateFileLogStream();

// Register for use LH_PrintfLog Common
LHCOMMON_API BOOL LH_RegisterLogStream(ILH_LogStream *piLogStream);
LHCOMMON_API BOOL LH_UnRegisterLogStream(ILH_LogStream *piLogStream);

// printf(_In_z_ _Printf_format_string_ const char * _Format, ...)
LHCOMMON_API BOOL LH_PrintfLog(const wchar_t *pcszFormat, ...);
LHCOMMON_API BOOL LH_PrintfLogEx(ILH_LogStream *piLogStream, const wchar_t *pcszFormat, ...);

//////////////////////////////////////////////////////////////////////////
//      Helper macro for write log
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
#define LH_LOG_ASSERT_EXIT(Condition)       \
    if (!(Condition))                       \
    {                                       \
        LH_PrintfLog(                       \
            LH_WIDE_TEXT"LH_LOG_ASSERT_EXIT(%ls) at line %u in %ls",        \
            LH_WIDE_TEXT(#Condition), __LINE__, LH_FUNCTION                 \
        );                                  \
        LH_ASSERT(Condition);               \
        goto LH_FAILED_LABEL;               \
    }
#define LH_LOG_PROCESS_EXIT(Condition)      \
    if (!(Condition))                       \
    {                                       \
        LH_PrintfLog(                       \
            LH_WIDE_TEXT"LH_LOG_PROCESS_ERROR(%ls) at line %u in %ls",      \
            LH_WIDE_TEXT(#Condition), __LINE__, LH_FUNCTION                 \
        );                                  \
        goto LH_FAILED_LABEL;               \
    }
//////////////////////////////////////////////////////////////////////////
#define LH_LOG_COM_ASSERT_EXIT(hrRetCode)   \
    if (FAILED(hrRetCode))                  \
    {                                       \
        LH_PrintfLog(                       \
            LH_WIDE_TEXT"LH_LOG_COM_ASSERT_EXIT(0x%x) at line %u in %ls",   \
            (int)(hrRetCode), __LINE__, LH_FUNCTION                         \
        );                                  \
        LH_ASSERT(SUCCEEDED(hrRetCode));    \
        goto LH_FAILED_LABEL;               \
    }
#define LH_LOG_COM_PROCESS_EXIT(hrRetCode)  \
    if (FAILED(Condition))                  \
    {                                       \
        LH_PrintfLog(                       \
            LH_WIDE_TEXT"LH_LOG_COM_ASSERT_EXIT(0x%x) at line %u in %ls",   \
            int(hrRetCode), __LINE__, LH_FUNCTION                           \
        );                                  \
        goto LH_FAILED_LABEL;               \
    }

