#include <unified.hpp>

#include <unified/core/math/point3.hpp>
#include <unified/core/math/matrix.hpp>

#include <unified/graphics/math/transform.hpp>
#include <unified/graphics/math/vertex2.hpp>
#include <unified/graphics/vertex_array.hpp>
#include <unified/graphics/shader.hpp>

#include <glad/glad.h>

using namespace Unified;

class Example : public Application
{
public:

    VertexArray vertex_array;

    bool calculate_state;
    Vertex2d segments[4] = {
        { { -1.0, -1.0 } },
        { { -1.0,  1.0 } },
        { {  1.0,  1.0 } },
        { {  1.0, -1.0 } }
    };

public:

    Example() : Application("Unified", VideoMode(800, 600), Window::Resizable),
        vertex_array(PrimitiveType::Polygon, 2, 4), calculate_state(true) {
    }

    void calculate_colors() {
        if (calculate_state) {

            segments[0].color.r += 0.01f;
            segments[1].color.g += 0.01f;
            segments[2].color.b += 0.01f;
            segments[3].color.r += 0.01f;
            segments[3].color.b += 0.01f;

            if (segments[0].color.r >= 1.f)
                calculate_state = false;

        } else {

            segments[0].color.r -= 0.01f;
            segments[1].color.g -= 0.01f;
            segments[2].color.b -= 0.01f;
            segments[3].color.r -= 0.01f;
            segments[3].color.b -= 0.01f;

            if (segments[0].color.r < 0.02f)
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

    virtual void OnCreate() override {
        set_frame_limit(60);
    }

    virtual bool OnUpdate(Time) override {
        clear();

        calculate_colors();
        render();

        swap_buffers();
        return poll_events();
    }

    virtual void OnEvent(EventDispatcher &dispatcher) override {
        dispatcher.dispatch<WindowResizeEvent>(BIND_EVENT_FN(&Example::window_resize_event, this));
    }

};

Application *Unified::CreateApplication() {
    return new Example();
}
