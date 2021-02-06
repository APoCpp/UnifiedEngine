#ifndef _UNIFIED_GRAPHICS_SHADER_HPP
#define _UNIFIED_GRAPHICS_SHADER_HPP

# include <unified/core/string.hpp>

# include <unified/core/math/matrix_fwd.hpp>
# include <unified/core/math/point_fwd.hpp>

UNIFIED_BEGIN_NAMESPACE
UNIFIED_GRAPHICS_BEGIN_NAMESPACE

class Shader
{
public:

    using HandleType = u32;

    Shader();
    Shader(const char *vertex_shader, const char *fragment_shader);

    virtual ~Shader();

    void create(const char *vertex_shader, const char *fragment_shader);

    UNIFIED_NODISCARD HandleType handle() const;

    void set_int(const char *name, int value);

    void set_int2(const char *name, const int *value);
    void set_int3(const char *name, const int *value);
    void set_int4(const char *name, const int *value);

    void set_int2(const char *name, const Point<int, 2> &value);
    void set_int3(const char *name, const Point<int, 3> &value);
    void set_int4(const char *name, const Point<int, 4> &value);

    void set_float(const char *name, float value);

    void set_float2(const char *name, const float *value);
    void set_float3(const char *name, const float *value);
    void set_float4(const char *name, const float *value);

    void set_float2(const char *name, const Point<float, 2> &value);
    void set_float3(const char *name, const Point<float, 3> &value);
    void set_float4(const char *name, const Point<float, 4> &value);

    void set_double(const char *name, double value);

    void set_double2(const char *name, const double *value);
    void set_double3(const char *name, const double *value);
    void set_double4(const char *name, const double *value);

    void set_double2(const char *name, const Point<double, 2> &value);
    void set_double3(const char *name, const Point<double, 3> &value);
    void set_double4(const char *name, const Point<double, 4> &value);

    void set_float3x3(const char *name, float *value);
    void set_float4x4(const char *name, float *value);

    void set_float3x3(const char *name, const Matrix<float, 3, 3> &value);
    void set_float4x4(const char *name, const Matrix<float, 4, 4> &value);

    void set_double3x3(const char *name, const double *value);
    void set_double4x4(const char *name, const double *value);

    void set_double3x3(const char *name, const Matrix<double, 3, 3> &value);
    void set_double4x4(const char *name, const Matrix<double, 4, 4> &value);

    static void bind(const Shader *shader);
    static void unbind();

public:

    class ScopeBind
    {
    public:

        static Shader *current;

        ScopeBind(const Shader *shader);

        virtual ~ScopeBind();

    protected:

        Shader *_prev;

    };

protected:

    HandleType _id;

    void compile(const char *vertex_shader, const char *fragment_shader);
    void free();

    void throw_if_error(u32 id, u32 type);

};

UNIFIED_GRAPHICS_END_NAMESPACE
UNIFIED_END_NAMESPACE

#endif
