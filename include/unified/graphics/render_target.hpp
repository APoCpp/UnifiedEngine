#ifndef _UNIFIED_GRAPHICS_RENDER_TARGET_HPP
#define _UNIFIED_GRAPHICS_RENDER_TARGET_HPP

# include <unified/graphics/drawable.hpp>
# include <unified/graphics/color.hpp>

UNIFIED_BEGIN_NAMESPACE
UNIFIED_GRAPHICS_BEGIN_NAMESPACE

class RenderTarget
{
public:

    RenderTarget();

    void clear(const Color &color = Color(0, 0, 0, 1.f));

    void draw(const Drawable &object) const;

};

UNIFIED_GRAPHICS_END_NAMESPACE
UNIFIED_END_NAMESPACE

#endif
