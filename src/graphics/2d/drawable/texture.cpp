#include <unified/graphics/2d/drawable/texture.hpp>
#include <unified/graphics/shader.hpp>
#include <glad/glad.h>

using namespace Unified::Graphics;

UNIFIED_BEGIN_NAMESPACE
UNIFIED_GRAPHICS_2D_BEGIN_NAMESPACE

Texture::Texture(string texture, Graphics::Buffer::Usage usage) : Graphics::Texture(texture), _buffer(usage) { }

void Texture::draw(const Graphics::RenderTarget&) const {
    Buffer::ScopeBind buffer_bind(&_buffer);

    GLint buffer_size = _buffer.size();

    glVertexAttribPointer(0, 2, GL_DOUBLE, GL_FALSE,
        buffer_size / 4, (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_DOUBLE, GL_FALSE,
        buffer_size / 4, (void*)(sizeof(Point2d) + sizeof(Color)));
    glEnableVertexAttribArray(1);

    static Shader shader(
        #include "vertex_texture.vert"
            ,
        #include "vertex_texture.frag"
    );

    Texture::ScopeBind texture_bind(this);
    Shader::ScopeBind shader_bind(&shader);
    glDrawArrays(static_cast<GLenum>(Graphics::PrimitiveType::Quads), 0, 4);

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}

UNIFIED_GRAPHICS_2D_END_NAMESPACE
UNIFIED_END_NAMESPACE
