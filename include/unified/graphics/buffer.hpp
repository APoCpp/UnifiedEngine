#ifndef _UNIFIED_GRAPHICS_BUFFER_HPP
#define _UNIFIED_GRAPHICS_BUFFER_HPP

# include <unified/core/int_types.hpp>

UNIFIED_BEGIN_NAMESPACE
UNIFIED_GRAPHICS_BEGIN_NAMESPACE

class Buffer
{
public:

    using HandleType = u32;

    enum Usage
    {
        Stream,
        Dynamic,
        Static
    };

    Buffer(Usage usage = Usage::Static);
    virtual ~Buffer();

    void allocate(u32 size);
    void reallocate(u32 size);

    void write(const void *data, u32 size, u32 offset = 0);
    void read(void *data, u32 size, u32 offset = 0);

    UNIFIED_NODISCARD HandleType handle() const;

    void set_usage(Usage usage);
    UNIFIED_NODISCARD Usage usage() const;

    UNIFIED_NODISCARD u32 size() const;

public:

    class ScopeBind
    {
    public:

        static ScopeBind *current;

        ScopeBind(const Buffer *buffer);

        virtual ~ScopeBind();

        HandleType binded() const;

    protected:

        ScopeBind *_prev;
        HandleType _binded;

    };

protected:

    HandleType _id;
    Usage _usage;

};

UNIFIED_GRAPHICS_END_NAMESPACE
UNIFIED_END_NAMESPACE

#endif
