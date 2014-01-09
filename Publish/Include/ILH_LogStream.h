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

#include <ObjBase.h>

// {1ECC39B0-6BE9-4455-B795-A1CD3A295862}
static const GUID IID_ILH_LogStream = 
{ 0x1ecc39b0, 0x6be9, 0x4455, { 0xb7, 0x95, 0xa1, 0xcd, 0x3a, 0x29, 0x58, 0x62 } };

interface ILH_LogStream : public IUnknown
{
public:
    virtual HRESULT STDMETHODCALLTYPE puts(const wchar_t *pcszMessage) = 0;
};
