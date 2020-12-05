#ifndef _UNIFIED_GRAPHICS_BUFFER_HPP
#define _UNIFIED_GRAPHICS_BUFFER_HPP

# include <unified/core/int_types.hpp>

UNIFIED_BEGIN_NAMESPACE

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
    void write(const void *data, u32 size);

    UNIFIED_NODISCARD HandleType get_handle() const;

    void set_usage(Usage usage);
    UNIFIED_NODISCARD Usage get_usage() const;

    UNIFIED_NODISCARD u32 get_size() const;

    static void bind(const Buffer *buffer);

protected:

    HandleType _id;
    Usage _usage;

};

UNIFIED_END_NAMESPACE

#endif
