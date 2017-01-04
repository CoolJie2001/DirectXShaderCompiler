/*===---- rtmintrin.h - RTM intrinsics -------------------------------------===
///////////////////////////////////////////////////////////////////////////////
//                                                                           //
// rtmintrin.h                                                               //
// Copyright (C) Microsoft Corporation. All rights reserved.                 //
// Licensed under the MIT license. See COPYRIGHT in the project root for     //
// full license information.                                                 //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////
#ifndef __IMMINTRIN_H
#error "Never use <rtmintrin.h> directly; include <immintrin.h> instead."
#endif

#ifndef __RTMINTRIN_H
#define __RTMINTRIN_H

#define _XBEGIN_STARTED   (~0u)
#define _XABORT_EXPLICIT  (1 << 0)
#define _XABORT_RETRY     (1 << 1)
#define _XABORT_CONFLICT  (1 << 2)
#define _XABORT_CAPACITY  (1 << 3)
#define _XABORT_DEBUG     (1 << 4)
#define _XABORT_NESTED    (1 << 5)
#define _XABORT_CODE(x)   (((x) >> 24) & 0xFF)

/* Define the default attributes for the functions in this file. */
#define __DEFAULT_FN_ATTRS __attribute__((__always_inline__, __nodebug__))

static __inline__ unsigned int __DEFAULT_FN_ATTRS
_xbegin(void)
{
  return __builtin_ia32_xbegin();
}

static __inline__ void __DEFAULT_FN_ATTRS
_xend(void)
{
  __builtin_ia32_xend();
}

#define _xabort(imm) __builtin_ia32_xabort((imm))

#undef __DEFAULT_FN_ATTRS

#endif /* __RTMINTRIN_H */
