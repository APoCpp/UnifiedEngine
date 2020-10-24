#ifndef UNIFIED_PLATFORM_HPP
#define UNIFIED_PLATFORM_HPP

# if defined(_WIN32) || defined(_WIN64)
#  define UNIFIED_PLATFORM_WINDOWS
# elif defined(__linux__)
#  define UNIFIED_PLATFORM_LINUX
# else
#  error UNIFIED_PLATFORM_NOT_SUPPORTED
# endif

#endif
