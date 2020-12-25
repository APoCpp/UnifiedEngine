#include <unified.hpp>

#include <unified/graphics/2d/drawable/vertex_list.hpp>
#include <unified/graphics/2d/vertex.hpp>
#include <unified/application/layer.hpp>

using namespace Unified;

using namespace Graphics;
using namespace Graphics2D;

class ConvexShapeLayer : public Layer
{
protected:

    VertexList vertex_list;
    Vertex2d vertex_cache;

    bool is_mouse_clip;

public:

    ConvexShapeLayer()
        : Layer(), vertex_list(PrimitiveType::Polygon), vertex_cache({ 0.0, 0.0 }, { 0.1, 0.1, 0.1, 1.0 }), is_mouse_clip(false) {
        vertex_list.add(Vertex2d { { 0.0, 0.0 }, { 0.1, 0.1, 0.1, 1.0 } });
    }

    void mouse_press_event(const MousePressEvent &event) {
        if (event.code == Mouse::Code::ButtonLeft && event.action == Mouse::Action::Press)
            is_mouse_clip = true;
        else
            is_mouse_clip = false;
    }

    void add_vertex(const Vertex2d &vertex) {
        if (vertex_cache == vertex)
            return;

        vertex_list.add(vertex_cache = vertex);
    }

    virtual void OnUpdate(Time) override {
        if (is_mouse_clip) {
            Point2i size = application->get_size();
            Point2d position = application->get_cursor_position();
            add_vertex(Vertex2d {
                { -1.0 + (position.x * 2.0 / static_cast<double>(size.x)), 1.0 - (position.y * 2.0 / static_cast<double>(size.y)) },
                { 0.18, 1.0, 0.0, 1.0 }
            });
        }

        application->draw(vertex_list);
    }

    virtual void OnEvent(EventDispatcher &dispatcher) override {
        dispatcher.dispatch<MousePressEvent>(BIND_EVENT_FN(&ConvexShapeLayer::mouse_press_event, this));
    }

};

class Template : public Application
{
public:

    Template() : Application("Unified", VideoMode(800, 600), Window::Resizable) {
        set_frame_limit(60);
        push_layer(new ConvexShapeLayer());
    }

public:

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
