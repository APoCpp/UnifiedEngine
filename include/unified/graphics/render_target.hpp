#ifndef UNIFIED_GRAPHICS_RENDER_TARGET_HPP
#define UNIFIED_GRAPHICS_RENDER_TARGET_HPP

#include <unified/core/color.hpp>
#include <unified/core/math/point2.hpp>

UNIFIED_BEGIN_NAMESPACE

class Drawable;

class RenderTarget
{
public:

    RenderTarget();
    virtual ~RenderTarget() _UNIFIED_NOEXCEPT = default;

    void clear(Color const &color = Color(0, 0, 0, 255)) _UNIFIED_NOEXCEPT;

public:

    void draw(Drawable const &buffer) const;

};

UNIFIED_END_NAMESPACE

#endif
