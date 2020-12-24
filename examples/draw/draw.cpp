#include <unified.hpp>

#include <unified/graphics/2d/drawable/vertex_list.hpp>
#include <unified/graphics/2d/vertex.hpp>

using namespace Unified;

using namespace Graphics;
using namespace Graphics2D;

class Template : public Application
{
public:

    VertexList vertex_list;
    Vertex2d vertex_last;

    bool is_mouse_clip;

public:

    Template() : Application("Unified", VideoMode(800, 600), Window::Resizable),
        vertex_list(PrimitiveType::Polygon), vertex_last({ 0.0, 0.0 }, { 0.1, 0.1, 0.1, 1.0 }), is_mouse_clip(false) {
        set_frame_limit(60);
        vertex_list.add(Vertex2d { { 0.0, 0.0 }, { 0.1, 0.1, 0.1, 1.0 } });
    }

    void add_vertex(const Vertex2d &vertex) {
        if (vertex_last == vertex)
            return;

        vertex_list.add(vertex_last = vertex);
    }

    void window_resize_event(const WindowResizeEvent &event) {
        set_viewport(event.size);
    }

    void mouse_press_event(const MousePressEvent &event) {
        if (event.code == Mouse::Code::ButtonLeft && event.action == Mouse::Action::Press)
            is_mouse_clip = true;
        else
            is_mouse_clip = false;
    }

public:

    virtual bool OnUpdate(Time&) override {
        clear();

        if (is_mouse_clip) {
            Point2i size = get_size();
            Point2d position = get_cursor_position();
            add_vertex(Vertex2d {
                { -1.0 + (position.x * 2.0 / (double)size.x), 1.0 - (position.y * 2.0 / (double)size.y) },
                { 0.18, 1.0, 0.0, 1.0 }
            });
        }

        draw(vertex_list);

        swap_buffers();
        return poll_events();
    }

    virtual void OnEvent(EventDispatcher &dispatcher) override {
        dispatcher.dispatch<WindowResizeEvent>(BIND_EVENT_FN(&Template::window_resize_event, this));
        dispatcher.dispatch<MousePressEvent>(BIND_EVENT_FN(&Template::mouse_press_event, this));
    }

};

Application *Unified::CreateApplication() {
    return new Template();
}
