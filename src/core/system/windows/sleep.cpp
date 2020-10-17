#include <unified/platform/platform.hpp>

#ifdef UNIFIED_PLATFORM_WINDOWS 

# include <unified/core/system/sleep.hpp>
# include <windows.h>

void Unified::sleep(Time duration) {
    ::Sleep(duration.asMilliseconds());
}

#endif