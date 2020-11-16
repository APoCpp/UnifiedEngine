#ifndef _UNIFIED_CORE_INT_TYPES_HPP
#define _UNIFIED_CORE_INT_TYPES_HPP

# include <unified/defines.hpp>
# include <bits/wordsize.h>

UNIFIED_BEGIN_NAMESPACE

typedef signed char s8;
typedef short int   s16;
typedef int         s32;

# if __WORDSIZE == 64
 typedef long int s64;
# else
 typedef long long int s64;
# endif

typedef unsigned char      u8;
typedef unsigned short int u16;
typedef unsigned int       u32;

#if __WORDSIZE == 64
 typedef unsigned long int u64;
#else
 typedef unsigned long long int u64;
#endif

UNIFIED_END_NAMESPACE

#endif
