#include <unified/graphics/3d/drawable/texture.hpp>
#include <unified/graphics/shader.hpp>
#include <glad/glad.h>

using namespace Unified::Graphics;

UNIFIED_BEGIN_NAMESPACE
UNIFIED_GRAPHICS_3D_BEGIN_NAMESPACE

Texture::Texture(string texture, bool flip, Graphics::Buffer::Usage usage) : Graphics::Texture(texture, flip), _buffer(usage) { }

void Texture::draw(const Graphics::RenderTarget&, const Graphics::Shader *shader) const {
    Buffer::ScopeBind buffer_bind(&_buffer);

    GLint buffer_size = _buffer.size();

    glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE,
        buffer_size / 4, (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_DOUBLE, GL_FALSE,
        buffer_size / 4, (void*)(sizeof(Point3d) + sizeof(Color)));
    glEnableVertexAttribArray(1);

    static Shader static_shader(
        #include "vertex_texture.vert"
            ,
        #include "vertex_texture.frag"
    );

    if (shader)
        Shader::ScopeBind shader_bind(shader);
    else
        Shader::ScopeBind shader_bind(&static_shader);

    Texture::ScopeBind texture_bind(this);

    glDrawArrays(static_cast<GLenum>(Graphics::PrimitiveType::Quads), 0, 4);

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}

UNIFIED_GRAPHICS_3D_END_NAMESPACE
UNIFIED_END_NAMESPACE
