#ifndef _UNIFIED_DEFINES_HPP
#define _UNIFIED_DEFINES_HPP

# define UNIFIED_NAMESPACE Unified
# define UNIFIED_BEGIN_NAMESPACE namespace UNIFIED_NAMESPACE {
# define UNIFIED_END_NAMESPACE }

# if __cplusplus >= 201703L
#  define UNIFIED_NODISCARD [[__nodiscard__]]
# else
#  define UNIFIED_NODISCARD
# endif

# if __cplusplus >= 201103L
#  define UNIFIED_CONSTEXPR constexpr
# else
#  define UNIFIED_CONSTEXPR const
# endif

# if __cplusplus >= 201703L
#  define UNIFIED_INLINE inline
# else
#  define UNIFIED_INLINE
# endif

# if __cplusplus >= 201103L
#  define UNIFIED_NOEXCEPT noexcept
#  define UNIFIED_NOEXCEPT_IF(...) noexcept(__VA_ARGS__)
#  define UNIFIED_THROW(_EXC)
# else
#  define UNIFIED_NOEXCEPT throw()
#  define UNIFIED_NOEXCEPT_IF(...)
#  define UNIFIED_THROW(_EXC) throw(_EXC)
# endif

# if defined(__GNUC__)
#  define UNIFIED_FORCE_INLINE __attribute__((always_inline)) inline
# elif defined(_MSC_VER)
#  define UNIFIED_FORCE_INLINE __forceinline
# else
#  define UNIFIED_FORCE_INLINE UNIFIED_INLINE
# endif

#endif
