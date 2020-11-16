#ifndef _UNIFIED_CORE_CLOCK_HPP
#define _UNIFIED_CORE_CLOCK_HPP

# include <unified/core/time.hpp>

UNIFIED_BEGIN_NAMESPACE

class Clock
{
public:

    Clock();

    UNIFIED_NODISCARD Time get_elapsed_time() const;
    Time restart();

protected:

    Time _timestamp;

};

UNIFIED_END_NAMESPACE

#endif
