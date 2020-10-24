#include <unified/defines.hpp>

#ifndef UNIFIED_CORE_CLOCK_HPP
#define UNIFIED_CORE_CLOCK_HPP

#include <unified/core/time.hpp>

UNIFIED_BEGIN_NAMESPACE

class Clock
{
public:

    Clock();

    Time get_elapsed_time() const _OSL_NOEXCEPT;
    Time restart() _OSL_NOEXCEPT;

protected:

    Time _timestamp;

};

UNIFIED_END_NAMESPACE

#endif
