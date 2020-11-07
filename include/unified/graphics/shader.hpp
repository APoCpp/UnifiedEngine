#ifndef UNIFIED_GRAPHICS_SHADER_HPP
#define UNIFIED_GRAPHICS_SHADER_HPP

#include <unified/defines.hpp>
#include <unified/core/string.hpp>

#include <unified/core/math/matrix_fwd.hpp>
#include <unified/core/math/point_fwd.hpp>

UNIFIED_BEGIN_NAMESPACE

class Shader
{
public:

    using HandleType = ui32;

    Shader() _UNIFIED_NOEXCEPT;
    Shader(char const *vertex_shader, char const *fragment_shader);

    virtual ~Shader() _UNIFIED_NOEXCEPT;

    void create(char const *vertex_shader, char const *fragment_shader);
    void free();

    _UNIFIED_NODISCARD HandleType get_handle() const _UNIFIED_NOEXCEPT;

    void set_int(char const *name, int value);
    void set_int2(char const *name, Point<int, 2> const &value);
    void set_int3(char const *name, Point<int, 3> const &value);
    void set_int4(char const *name, Point<int, 4> const &value);

    void set_float(char const *name, float value);
    void set_float2(char const *name, Point<float, 2> const &value);
    void set_float3(char const *name, Point<float, 3> const &value);
    void set_float4(char const *name, Point<float, 4> const &value);

    void set_double(char const *name, double value);
    void set_double2(char const *name, Point<double, 2> const &value);
    void set_double3(char const *name, Point<double, 3> const &value);
    void set_double4(char const *name, Point<double, 4> const &value);

    void set_float3x3(char const *name, Matrix<float, 3, 3> const &value);
    void set_float4x4(char const *name, Matrix<float, 4, 4> const &value);

    void set_double3x3(char const *name, Matrix<double, 3, 3> const &value);
    void set_double4x4(char const *name, Matrix<double, 4, 4> const &value);

    static void bind(Shader const *shader) _UNIFIED_NOEXCEPT;

protected:

    ui32 _id;

    void compile(char const *vertex_shader, char const *fragment_shader);
    void throw_if_error(u32 id, u32 type);

};

UNIFIED_END_NAMESPACE

#endif
