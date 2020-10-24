#ifndef UNIFIED_HPP
#define UNIFIED_HPP

#include <unified/platform/platform.hpp>

# if defined(UNIFIED_PLATFORM_WINDOWS)
#  include <unified/platform/windows/windows.hpp>
# elif defined(UNIFIED_PLATFORM_LINUX)
#  include <unified/platform/linux/linux.hpp>
# endif

#endif
