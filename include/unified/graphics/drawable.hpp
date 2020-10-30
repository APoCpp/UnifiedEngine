#ifndef UNIFIED_GRAPHICS_DRAWABLE_HPP
#define UNIFIED_GRAPHICS_DRAWABLE_HPP

#include <unified/graphics/render_target.hpp>

UNIFIED_BEGIN_NAMESPACE

class Drawable
{
public:

    virtual ~Drawable() = default;

protected:

    friend class RenderTarget;

    virtual void draw(RenderTarget const&) const = 0;

};

UNIFIED_END_NAMESPACE

#endif
