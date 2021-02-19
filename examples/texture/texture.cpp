#include <unified.hpp>

#include <unified/graphics/2d/drawable/texture.hpp>

using namespace Unified;
using namespace Unified::Graphics;

class TextureLayer : public Layer
{
public:

    const Application *application;

    Graphics2D::Texture texture;

    Graphics::Vertex2d quad_vertices[4] =
    { { { -0.8, -0.8 }, { 1.0, 1.0 } },
      { { -0.8,  0.8 }, { 1.0, 0.0 } },
      { {  0.8,  0.8 }, { 0.0, 0.0 } },
      { {  0.8, -0.8 }, { 0.0, 1.0 } } };

    TextureLayer(Application *application) : application(application), texture("image.png")  {
        texture.write(quad_vertices, sizeof(quad_vertices));
    }

    virtual void OnUpdate(Time) override {
        application->draw(texture);
    }

};

class ExampleLayers : public Application
{
public:

    void window_resize_event(const WindowResizeEvent &event) {
        set_viewport(event.size);
    }

public:

    ExampleLayers() : Application("ExampleTexture") {
        push_layer<TextureLayer>(this);
        set_frame_limit(60);
    }

    virtual bool OnUpdate(Time) override {
        clear({ 0.15, 0.15, 0.15 });
        process_layers();
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
