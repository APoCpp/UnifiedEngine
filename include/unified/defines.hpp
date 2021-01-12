#ifndef _UNIFIED_DEFINES_HPP
#define _UNIFIED_DEFINES_HPP

# define UNIFIED_NAMESPACE Unified
# define UNIFIED_NAMESPACE_STRING "Unified"

# define UNIFIED_BEGIN_NAMESPACE namespace UNIFIED_NAMESPACE {
# define UNIFIED_END_NAMESPACE }

# define UNIFIED_GRAPHICS_NAMESPACE Graphics
# define UNIFIED_GRAPHICS_NAMESPACE_STRING "Graphics"

# define UNIFIED_GRAPHICS_BEGIN_NAMESPACE namespace UNIFIED_GRAPHICS_NAMESPACE {
# define UNIFIED_GRAPHICS_END_NAMESPACE }

# define UNIFIED_GRAPHICS_2D_NAMESPACE Graphics2D
# define UNIFIED_GRAPHICS_2D_NAMESPACE_STRING "Graphics2D"

# define UNIFIED_GRAPHICS_2D_BEGIN_NAMESPACE namespace UNIFIED_GRAPHICS_2D_NAMESPACE {
# define UNIFIED_GRAPHICS_2D_END_NAMESPACE }

# define UNIFIED_GRAPHICS_3D_NAMESPACE Graphics3D
# define UNIFIED_GRAPHICS_3D_NAMESPACE_STRING "Graphics3D"

# define UNIFIED_GRAPHICS_3D_BEGIN_NAMESPACE namespace UNIFIED_GRAPHICS_3D_NAMESPACE {
# define UNIFIED_GRAPHICS_3D_END_NAMESPACE }

# if __cplusplus >= 201703L
#  define UNIFIED_NODISCARD [[nodiscard]]
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
