#ifndef UNIFIED_CORE_INPUT_MOUSE_HPP
#define UNIFIED_CORE_INPUT_MOUSE_HPP

#include <unified/defines.hpp>

UNIFIED_BEGIN_NAMESPACE

namespace Mouse
{
    enum class Action : int
    {
        Release,
        Press
    };

    enum class Code : int
    {
        None = -1,

        Button0,
        Button1,
        Button2,
        Button3,
        Button4,
        Button5,
        Button6,
        Button7,

        ButtonLeft   = Button0,
        ButtonRight  = Button1,
        ButtonMiddle = Button2
    };
}

UNIFIED_END_NAMESPACE

#endif
