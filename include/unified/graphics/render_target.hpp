#ifndef UNIFIED_GRAPHICS_RENDER_TARGET_HPP
#define UNIFIED_GRAPHICS_RENDER_TARGET_HPP

#include <unified/defines.hpp>

#include <unified/core/math/vector2.hpp>
#include <unified/core/color.hpp>

UNIFIED_BEGIN_NAMESPACE

class RenderTarget
{
public:

    RenderTarget();
    virtual ~RenderTarget() _OSL_NOEXCEPT = default;

    void clear(Color const &color = Color(0, 0, 0, 255)) _OSL_NOEXCEPT;

    void push_gl_states() _OSL_NOEXCEPT;
    void pop_gl_states() _OSL_NOEXCEPT;

    void reset_gl_states() _OSL_NOEXCEPT;

};

UNIFIED_END_NAMESPACE

#endif
