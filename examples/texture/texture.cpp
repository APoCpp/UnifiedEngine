#include <unified.hpp>

#include <unified/graphics/2d/drawable/texture.hpp>
#include <unified/graphics/2d/vertex.hpp>

using namespace Unified;

using namespace Graphics;
using namespace Graphics2D;

class TextureLayer : public Layer
{
public:

    Graphics2D::Texture texture;

public:

    TextureLayer() : Layer(), texture("image.png") {
        Vertex2d vertex[] = {
            { {  0.5,  0.5 }, { 1.0, 1.0 } },
            { {  0.5, -0.5 }, { 1.0, 0.0 } },
            { { -0.5, -0.5 }, { 0.0, 0.0 } },
            { { -0.5,  0.5 }, { 0.0, 1.0 } }
        };
        texture.write(vertex, sizeof(vertex));
    }

    virtual void OnUpdate(Time) override {
        application->draw(texture);
    }

};

class Template : public Application
{
public:

    Template() : Application("Unified", VideoMode(800, 600), Window::Resizable) {
        push_layer(new TextureLayer());
    }

    void window_resize_event(const WindowResizeEvent &event) {
        set_viewport(event.size);
    }

public:

    virtual bool OnUpdate(Time&) override {
        clear();
        update_layers();
        swap_buffers();
        return poll_events();
    }

    virtual void OnEvent(EventDispatcher &dispatcher) override {
        dispatcher.dispatch<WindowResizeEvent>(BIND_EVENT_FN(&Template::window_resize_event, this));
        layers_dispatch(dispatcher);
    }

};

Application *Unified::CreateApplication() {
    return new Template();
}
