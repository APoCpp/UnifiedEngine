#ifndef UNIFIED_CORE_COLOR_HPP
#define UNIFIED_CORE_COLOR_HPP

#include <unified/defines.hpp>
#include <unified/core/int_types.hpp>

UNIFIED_BEGIN_NAMESPACE

// @todo: functions for converting
class Color
{
public:

    Color();
    Color(u8 r, u8 g, u8 b, u8 a);

    u8 r, g, b, a;

};

UNIFIED_END_NAMESPACE

#endif
