#include <unified/core/system/sleep.hpp>
#include <unified/platform/platform.hpp>

#if defined(UNIFIED_PLATFORM_WINDOWS)

#include <windows.h>

void Unified::sleep(Time duration) {
    ::Sleep(duration.asMilliseconds());
}

#elif defined(UNIFIED_PLATFORM_LINUX)

#include <unistd.h>

void Unified::sleep(Time duration) {
    ::sleep(duration.asMilliseconds());
}

#endif
