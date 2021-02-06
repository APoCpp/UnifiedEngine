#ifndef _UNIFIED_GRAPHICS_DRAWABLE_HPP
#define _UNIFIED_GRAPHICS_DRAWABLE_HPP

# include <unified/defines.hpp>

UNIFIED_BEGIN_NAMESPACE
UNIFIED_GRAPHICS_BEGIN_NAMESPACE

class RenderTarget;
class Shader;

class Drawable
{
protected:

    friend class RenderTarget;

    virtual ~Drawable();

    virtual void draw(RenderTarget const&, Shader const*) const = 0;

};

UNIFIED_GRAPHICS_END_NAMESPACE
UNIFIED_END_NAMESPACE

#endif
