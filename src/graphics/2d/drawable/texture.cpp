#include <unified/graphics/2d/drawable/texture.hpp>
#include <unified/graphics/shader.hpp>
#include <glad/glad.h>

using namespace Unified::Graphics;

UNIFIED_BEGIN_NAMESPACE
UNIFIED_GRAPHICS_2D_BEGIN_NAMESPACE

Texture::Texture(string texture, bool flip, Graphics::Buffer::Usage usage) : Graphics::Texture(texture, flip), _buffer(usage) { }

void Texture::draw(const Graphics::RenderTarget&, const Graphics::Shader *shader) const {
    GLint buffer_size = _buffer.size();

    Buffer::ScopeBind buffer_bind(&_buffer);

    glVertexAttribPointer(0, 2, GL_DOUBLE, GL_FALSE,
        buffer_size / 4, (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_DOUBLE, GL_FALSE,
        buffer_size / 4, (void*)(sizeof(Point2d) + sizeof(Color)));
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

UNIFIED_GRAPHICS_2D_END_NAMESPACE
UNIFIED_END_NAMESPACE
