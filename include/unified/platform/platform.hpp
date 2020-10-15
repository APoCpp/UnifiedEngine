#ifndef UNIFIED_PLATFORM_HPP
#define UNIFIED_PLATFORM_HPP

# if defined(_WIN32) || defined(_WIN64)
#  define UNIFIED_PLATFORM_WINDOWS
# else
#  error UNIFIED_PLATFORM_NOT_SUPPORTED
# endif

#endif