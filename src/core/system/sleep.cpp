#include <unified/core/system/sleep.hpp>
#include <unified/platform/platform.hpp>

#if defined(UNIFIED_PLATFORM_WINDOWS)

#  include <windows.h>

UNIFIED_BEGIN_NAMESPACE

void sleep(Time duration) {
    ::Sleep(duration.asMilliseconds());
}

UNIFIED_END_NAMESPACE

# elif defined(UNIFIED_PLATFORM_LINUX)

#  include <unistd.h>

UNIFIED_BEGIN_NAMESPACE

void sleep(Time duration) {
    ::usleep(duration.asMicroseconds());
}

UNIFIED_END_NAMESPACE

#endif
