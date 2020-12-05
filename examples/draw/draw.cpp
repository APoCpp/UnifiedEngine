#include <unified.hpp>

#include <unified/graphics/math/vertex2.hpp>
#include <unified/graphics/drawable/vertex_array.hpp>
#include <unified/graphics/shader.hpp>

using namespace UNIFIED_NAMESPACE;

class Draw : public Application
{
public:

    VertexArray vertex_array;

    bool calculate_state;

    Vertex<double, 2> segments[4] = {
        { { -1.0, -1.0 } },
        { { -1.0,  1.0 } },
        { {  1.0,  1.0 } },
        { {  1.0, -1.0 } }
    };

public:

    Draw() : Application("Unified", VideoMode(800, 600), Window::Resizable),
        vertex_array(PrimitiveType::Polygon, 2, 4), calculate_state(true) {
        set_frame_limit(60);
    }

    void calculate_colors(float elapsed) {
        if (calculate_state) {

            segments[0].color.r += 1.f * elapsed;
            segments[1].color.g += 1.f * elapsed;
            segments[2].color.b += 1.f * elapsed;
            segments[3].color.r += 1.f * elapsed;
            segments[3].color.b += 1.f * elapsed;

            if (segments[0].color.r >= 1.f)
                calculate_state = false;

        } else {

            segments[0].color.r -= 1.f * elapsed;
            segments[1].color.g -= 1.f * elapsed;
            segments[2].color.b -= 1.f * elapsed;
            segments[3].color.r -= 1.f * elapsed;
            segments[3].color.b -= 1.f * elapsed;

            if (segments[0].color.r <= 0.0f)
                calculate_state = true;

        }
    }

    void render() {
        vertex_array.write(segments, sizeof(segments));
        draw(vertex_array);
    }

    void window_resize_event(WindowResizeEvent const &event) {
        set_viewport(event.size);
    }

public:

    virtual bool OnUpdate(Time &elapsed) override {
        clear();

        calculate_colors((float)elapsed.asSeconds());
        render();

        swap_buffers();
        return poll_events();
    }

    virtual void OnEvent(EventDispatcher &dispatcher) override {
        dispatcher.dispatch<WindowResizeEvent>(BIND_EVENT_FN(&Draw::window_resize_event, this));
    }

};

Application *Unified::CreateApplication() {
    return new Draw();
}
