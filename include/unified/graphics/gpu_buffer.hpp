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
    virtual ~GPUBuffer() _OSL_NOEXCEPT;

    void write(void const *data, u32 size);

    _OSL_NODISCARD HandleType get_handle() const _OSL_NOEXCEPT;

    void set_usage(Usage usage) _OSL_NOEXCEPT;
    _OSL_NODISCARD Usage get_usage() const _OSL_NOEXCEPT;

protected:

    static void bind(GPUBuffer const *buffer) _OSL_NOEXCEPT;

    Usage _usage;
    HandleType _buffer;
    u32 _size;

};

UNIFIED_END_NAMESPACE

#endif
