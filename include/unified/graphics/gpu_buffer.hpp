#ifndef UNIFIED_GRAPHICS_GPU_BUFFER_HPP
#define UNIFIED_GRAPHICS_GPU_BUFFER_HPP

#include <unified/defines.hpp>

UNIFIED_BEGIN_NAMESPACE

class GPUBuffer
{
public:

    using HandleType = ui32;

    enum Usage
    {
        Stream,
        Dynamic,
        Static
    };

    GPUBuffer(Usage usage);

    virtual ~GPUBuffer() _UNIFIED_NOEXCEPT;

    virtual void write(void const *data, u32 size) _UNIFIED_NOEXCEPT;

    _UNIFIED_NODISCARD HandleType get_handle() const _UNIFIED_NOEXCEPT;

    void set_usage(Usage usage) _UNIFIED_NOEXCEPT;
    _UNIFIED_NODISCARD Usage get_usage() const _UNIFIED_NOEXCEPT;

    static void bind(GPUBuffer const *buffer) _UNIFIED_NOEXCEPT;

protected:

    Usage _usage;
    HandleType _id;
    u32 _size;

};

UNIFIED_END_NAMESPACE

#endif
