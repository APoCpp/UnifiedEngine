#include <unified/core/time.hpp>
#include <defines.hpp>

#ifndef UNIFIED_CORE_CLOCK_HPP
#define UNIFIED_CORE_CLOCK_HPP

namespace Unified
{
    class Clock
    {
    public:

        Clock();

        Time get_elapsed_time() const _OSL_NOEXCEPT;
        Time restart() _OSL_NOEXCEPT;

    protected:

        Time _timestamp;

    };
}

#endif