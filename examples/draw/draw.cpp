#include <unified.hpp>

#include <unified/graphics/math/vertex2.hpp>
#include <unified/graphics/drawable/vertex_list.hpp>

#include <unified/core/system/sleep.hpp>

using namespace Unified;

class Draw : public Application
{
public:

    Graphics::VertexList vertex_list;
    Graphics::Vertex<double, 2> vertex_last;

    bool is_mouse_clip;

public:

    Draw() : Application("Unified", VideoMode(800, 600), Window::Resizable),
        vertex_list(Graphics::PrimitiveType::Polygon, 2), vertex_last({ 0.0, 0.0 }, { 0.1, 0.1, 0.1, 1.0 }), is_mouse_clip(false) {
        set_frame_limit(60);
        vertex_list.add(Graphics::Vertex<double, 2> {
            Point2d { 0.0, 0.0 },
            Graphics::Color { 0.1, 0.1, 0.1, 1.0 }
        });
    }

    void add_vertex(const Graphics::Vertex<double, 2> &vertex) {
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

            add_vertex(Graphics::Vertex<double, 2> {
                Point2d { -1.0 + (position.x * 2.0 / (double)size.x), 1.0 - (position.y * 2.0 / (double)size.y) },
                Graphics::Color { 0.18, 1.0, 0.0, 1.0 }
            });
        }

        draw(vertex_list);

        if (get_key_action(Keyboard::Code::Space) == Keyboard::Action::Press) {
            Graphics::Vertex<double, 2> *vertex = new Graphics::Vertex<double, 2>[vertex_list.size() / sizeof(Graphics::Vertex<double, 2>)];
            vertex_list.read(vertex, vertex_list.size());

            for (size_t i = 0; i < vertex_list.size() / sizeof(Graphics::Vertex<double, 2>); i++) {
                fmt::print(stdout, "{{ {}, {} }}\n", vertex[i].x, vertex[i].y);
            } fmt::print(stdout, "\n");

            delete[] vertex;
        }

        swap_buffers();
        return poll_events();
    }

    virtual void OnEvent(EventDispatcher &dispatcher) override {
        dispatcher.dispatch<WindowResizeEvent>(BIND_EVENT_FN(&Draw::window_resize_event, this));
        dispatcher.dispatch<MousePressEvent>(BIND_EVENT_FN(&Draw::mouse_press_event, this));
    }

};

Application *Unified::CreateApplication() {
    return new Draw();
}
