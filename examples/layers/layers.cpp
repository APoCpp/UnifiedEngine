#include <unified.hpp>

#include <unified/graphics/2d/drawable/vertex_array.hpp>
#include <unified/graphics/2d/vertex.hpp>

using namespace Unified;
using namespace Unified::Graphics;

class ExampleLayer1 : public Layer
{
public:

    const Application *application;

    Graphics2D::VertexArray quad;

    ExampleLayer1(Application *application) : application(application), quad(PrimitiveType::Quads, 4)  {
        Graphics::Vertex2d quad_vertices[] =
        { { { -0.8, -0.8 }, { 1.f, 0.f, 0.f, 1.f } },
          { { -0.8,  0.8 }, { 1.f, 0.f, 0.f, 1.f } },
          { {  0.8,  0.8 }, { 1.f, 0.f, 0.f, 1.f } },
          { {  0.8, -0.8 }, { 1.f, 0.f, 0.f, 1.f } } };
        quad.write(quad_vertices, sizeof(quad_vertices));
    }

    virtual void OnUpdate(Time) override {
        application->draw(quad);
    }

};

class ExampleLayer2 : public Layer
{
public:

    const Application *application;

    Graphics2D::VertexArray quad;

    ExampleLayer2(Application *application) : application(application), quad(PrimitiveType::Quads, 4)  {
        Graphics::Vertex2d quad_vertices[] =
        { { { 0.7, -0.3 }, { 0.f, 1.f, 0.f, 1.f } },
          { { 0.7,  0.3 }, { 0.f, 1.f, 0.f, 1.f } },
          { { 0.1,  0.3 }, { 0.f, 1.f, 0.f, 1.f } },
          { { 0.1, -0.3 }, { 0.f, 1.f, 0.f, 1.f } } };
        quad.write(quad_vertices, sizeof(quad_vertices));
    }

    virtual void OnUpdate(Time) override {
        application->draw(quad);
    }

};

class ExampleLayer3 : public Layer
{
public:

    const Application *application;

    Graphics2D::VertexArray quad;

    ExampleLayer3(Application *application) : application(application), quad(PrimitiveType::Quads, 4)  {
        Graphics::Vertex2d quad_vertices[] =
        { { { 0.6, -0.15 }, { 1.f, 1.f, 0.f, 1.f } },
          { { 0.6,  0.15 }, { 1.f, 1.f, 0.f, 1.f } },
          { { 0.3,  0.15 }, { 1.f, 1.f, 0.f, 1.f } },
          { { 0.3, -0.15 }, { 1.f, 1.f, 0.f, 1.f } } };
        quad.write(quad_vertices, sizeof(quad_vertices));
    }

    virtual void OnUpdate(Time) override {
        application->draw(quad);
    }

};


class ExampleLayers : public Application
{
public:

    void window_resize_event(const WindowResizeEvent &event) {
        set_viewport(event.size);
    }

public:

    ExampleLayers() : Application("ExampleLayers") {
        push_layer<ExampleLayer1>(this);
        push_layer<ExampleLayer2>(this);
        push_layer<ExampleLayer3>(this);
        set_frame_limit(60);
    }

    virtual bool OnUpdate(Time) override {
        clear();
        update_layers();
        swap_buffers();
        return poll_events();
    }

    virtual void OnEvent(EventDispatcher &dispatcher) override {
        dispatcher.dispatch<WindowResizeEvent>(BIND_EVENT_FN(&ExampleLayers::window_resize_event, this));
    }

};

Application *UNIFIED_NAMESPACE::CreateApplication() {
    return new ExampleLayers();
}
