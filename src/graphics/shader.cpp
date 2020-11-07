#include <unified/graphics/shader.hpp>
#include <unified/core/exceptions.hpp>

#include <unified/core/math/matrix.hpp>
#include <unified/core/math/point2.hpp>
#include <unified/core/math/point3.hpp>
#include <unified/core/math/point4.hpp>

#include <glad/glad.h>

UNIFIED_BEGIN_NAMESPACE

Shader::Shader() _UNIFIED_NOEXCEPT : _id(0) { }

Shader::Shader(char const *vertex_shader, char const *fragment_shader) {
    compile(vertex_shader, fragment_shader);
}

Shader::~Shader() _UNIFIED_NOEXCEPT {
    if (_id)
        free();
}

void Shader::create(char const *vertex_shader, char const *fragment_shader) {
    compile(vertex_shader, fragment_shader);
}

void Shader::free()  {
    glDeleteProgram(_id);
}

Shader::HandleType Shader::get_handle() const _UNIFIED_NOEXCEPT {
    return _id;
}

void Shader::set_int(char const *name, int value) {
    glUniform1i(glGetUniformLocation(_id, name), value);
}

void Shader::set_int2(char const *name, Point<int, 2> const &value) {
    glUniform2i(glGetUniformLocation(_id, name), value.x, value.y);
}

void Shader::set_int3(char const *name, Point<int, 3> const &value) {
    glUniform3i(glGetUniformLocation(_id, name), value.x, value.y, value.z);
}

void Shader::set_int4(char const *name, Point<int, 4> const &value) {
    glUniform4i(glGetUniformLocation(_id, name), value.x, value.y, value.z, value.w);
}

void Shader::set_float(char const *name, float value) {
    glUniform1f(glGetUniformLocation(_id, name), value);
}

void Shader::set_float2(char const *name, Point<float, 2> const &value) {
    glUniform2f(glGetUniformLocation(_id, name), value.x, value.y);
}

void Shader::set_float3(char const *name, Point<float, 3> const &value) {
    glUniform3f(glGetUniformLocation(_id, name), value.x, value.y, value.z);
}

void Shader::set_float4(char const *name, Point<float, 4> const &value) {
    glUniform4f(glGetUniformLocation(_id, name), value.x, value.y, value.z, value.w);
}

void Shader::set_double(char const *name, double value) {
    glUniform1d(glGetUniformLocation(_id, name), value);
}

void Shader::set_double2(char const *name, Point<double, 2> const &value) {
    glUniform2d(glGetUniformLocation(_id, name), value.x, value.y);
}

void Shader::set_double3(char const *name, Point<double, 3> const &value) {
    glUniform3d(glGetUniformLocation(_id, name), value.x, value.y, value.z);
}

void Shader::set_double4(char const *name, Point<double, 4> const &value) {
    glUniform4d(glGetUniformLocation(_id, name), value.x, value.y, value.z, value.w);
}

void Shader::set_float3x3(char const *name, Matrix<float, 3, 3> const &value) {
    glUniformMatrix3fv(glGetUniformLocation(_id, name), 1, GL_FALSE, value.data());
}

void Shader::set_float4x4(char const *name, Matrix<float, 4, 4> const &value) {
    glUniformMatrix4fv(glGetUniformLocation(_id, name), 1, GL_FALSE, value.data());
}

void Shader::set_double3x3(char const *name, Matrix<double, 3, 3> const &value) {
    glUniformMatrix3dv(glGetUniformLocation(_id, name), 1, GL_FALSE, value.data());
}

void Shader::set_double4x4(char const *name, Matrix<double, 4, 4> const &value) {
    glUniformMatrix4dv(glGetUniformLocation(_id, name), 1, GL_FALSE, value.data());
}

void Shader::bind(Shader const *shader) _UNIFIED_NOEXCEPT {
    glUseProgram(shader ? shader->get_handle() : 0);
}

void Shader::compile(char const *vertex_shader, char const *fragment_shader) {
    GLuint vertex_shader_id = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader_id, 1, &vertex_shader, 0);
    glCompileShader(vertex_shader_id);
    throw_if_error(vertex_shader_id, GL_COMPILE_STATUS);

    GLuint fragment_shader_id = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader_id, 1, &fragment_shader, 0);
    glCompileShader(fragment_shader_id);
    throw_if_error(fragment_shader_id, GL_COMPILE_STATUS);

    _id = glCreateProgram();
    glAttachShader(_id, vertex_shader_id);
    glAttachShader(_id, fragment_shader_id);
    glLinkProgram(_id);
    throw_if_error(_id, GL_LINK_STATUS);
}

void Shader::throw_if_error(u32 id, u32 type) {
    GLint ok = 0;
    switch (type) {
        case(GL_LINK_STATUS): {
            glGetProgramiv(id, GL_LINK_STATUS, &ok);
            if (ok == GL_FALSE) {
                GLint size;
                glGetProgramiv(_id, GL_INFO_LOG_LENGTH, &size);

                string error;
                error.resize(size);

                glGetProgramInfoLog(_id, size, 0, error.data());
                throw EXCEPTION_INITIALIZATION_FAILED(error.c_str());
            }
            break;
        }

        default: {
            glGetShaderiv(id, type, &ok);
            if (ok == GL_FALSE) {
                GLint size;
                glGetShaderiv(_id, GL_INFO_LOG_LENGTH, &size);

                string error;
                error.resize(size);

                glGetShaderInfoLog(_id, size, 0, error.data());
                throw EXCEPTION_INITIALIZATION_FAILED(error.c_str());
            }
            break;
        }
    }
}

UNIFIED_END_NAMESPACE
