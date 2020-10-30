#include <unified.hpp>

#include <unified/core/math/point2.hpp>
#include <unified/core/math/point3.hpp>

#include <unified/graphics/vertex_array.hpp>

using namespace Unified;

class Example : public Application
{
public:

    Point2f vertices[3] = {
        { -1.f, -1.f },
        {  0.f,  1.f },
        {  1.f, -1.f }
    };

    static _OSL_CONSTEXPR u32 vertex_dimension = sizeof(vertices[0]) / sizeof(float);
    static _OSL_CONSTEXPR u32 vertex_count = sizeof(vertices) / sizeof(vertices[0]);

public:

    VertexArray vertices_array;

    Example() : vertices_array(GPUBuffer::Usage::Static, vertex_dimension, vertex_count) { }

    virtual void OnCreate() override {
        vertices_array.write(vertices, sizeof(vertices));
    }

    virtual bool OnUpdate(Time) override {
        clear();
        draw(vertices_array);
        swap_buffers();
        return poll_events();
    }

};

Application *Unified::CreateApplication() {
    return new Example();
}
