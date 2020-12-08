#ifndef _UNIFIED_HPP
#define _UNIFIED_HPP

# include <unified/platform/platform.hpp>

# ifndef UNIFIED_LIBRARY_MODE
#  if defined(UNIFIED_PLATFORM_WINDOWS)
#   include <unified/platform/windows/windows.hpp>
#  elif defined(UNIFIED_PLATFORM_LINUX)
#   include <unified/platform/linux/linux.hpp>
#  endif
# else
#  include <unified/application/application.hpp>
# endif

#endif
