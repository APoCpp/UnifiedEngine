#ifndef _UNIFIED_GRAPHICS_TEXTURE_HPP
#define _UNIFIED_GRAPHICS_TEXTURE_HPP

# include <unified/defines.hpp>
# include <unified/core/string.hpp>
# include <unified/core/int_types.hpp>

UNIFIED_BEGIN_NAMESPACE
UNIFIED_GRAPHICS_BEGIN_NAMESPACE

class Texture
{
public:

    using HandleType = u32;
    using SlotType = u32;

    Texture(string image);
    Texture(u8 *data, u32 size);

    virtual ~Texture();

    HandleType handle() const;

    static void bind(const Texture *texture, SlotType slot = 0);
    static void unbind();

public:

    class ScopeBind
    {
    public:

        static Texture *current;

        ScopeBind(const Texture *texture);

        virtual ~ScopeBind();

    protected:

        Texture *_prev;

    };

protected:

    HandleType _id;

    int _width, _height, _channels;

};

UNIFIED_GRAPHICS_END_NAMESPACE
UNIFIED_END_NAMESPACE

#endif
