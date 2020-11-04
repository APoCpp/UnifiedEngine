#ifndef UNIFIED_CORE_COLOR_HPP
#define UNIFIED_CORE_COLOR_HPP

#include <unified/defines.hpp>
#include <unified/core/int_types.hpp>

UNIFIED_BEGIN_NAMESPACE

// @todo: methods for converting
class Color
{
public:

    Color() _OSL_NOEXCEPT;
    Color(u8 r, u8 g, u8 b) _OSL_NOEXCEPT;
    Color(u8 r, u8 g, u8 b, u8 a) _OSL_NOEXCEPT;

    u8 r, g, b, a;

};

UNIFIED_END_NAMESPACE

#endif
