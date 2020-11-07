#ifndef UNIFIED_DEFINES_HPP
#define UNIFIED_DEFINES_HPP

#include <unified/core/int_types.hpp>

#define UNIFIED_NAMESPACE Unified

#define UNIFIED_BEGIN_NAMESPACE namespace UNIFIED_NAMESPACE {
#define UNIFIED_END_NAMESPACE }

# if __cplusplus >= 201103L
#  define _UNIFIED_NOEXCEPT noexcept
# else
#  define _UNIFIED_NOEXCEPT
# endif

# if __cplusplus >= 201103L
#  define _UNIFIED_CONSTEXPR constexpr
# else
#  define _UNIFIED_CONSTEXPR const
# endif

# if __cplusplus >= 201703L
#  define _UNIFIED_NODISCARD [[__nodiscard__]]
# else
#  define _UNIFIED_NODISCARD
# endif

#endif
