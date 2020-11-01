#include <unified.hpp>

#include <unified/core/math/point3.hpp>
#include <unified/core/math/matrix.hpp>

#include <unified/graphics/vertex_array.hpp>
#include <unified/graphics/vars.hpp>

using namespace Unified;

class Example : public Application
{
public:

    VertexArray vertex_array;
    Point3d position;

    Matrix4x4d model_view;

public:

    Example() : Application("Unified", VideoMode(800, 600), Window::Resizable),
        vertex_array(GPUBuffer::Usage::Static, PrimitiveType::Quads, 3, 4), position(0.0) {
        model_view = get_modelview_matrix();
    }

    void render() {
        Point3d vertices[4] = {
            position + translate<double, 3>(model_view, { -0.3, -0.3, 0.0 }),
            position + translate<double, 3>(model_view, { -0.3,  0.3, 0.0 }),
            position + translate<double, 3>(model_view, {  0.3,  0.3, 0.0 }),
            position + translate<double, 3>(model_view, {  0.3, -0.3, 0.0 })
        };

        vertex_array.write(vertices, sizeof(vertices));
        draw(vertex_array);
    }

    void window_resize_event(WindowResizeEvent const &event) {
        set_viewport(event.size);
    }

    void input_handle(Keyboard::Code code) {
        Keyboard::Action action = get_key_action(code);
        if (action == Keyboard::Action::Press || action == Keyboard::Action::Repeat) {
            switch (code) {
                case (Keyboard::Code::W): { position += translate<double, 3>(model_view, {  0.0,  0.1, 0.0 }); break; }
                case (Keyboard::Code::A): { position += translate<double, 3>(model_view, { -0.1,  0.0, 0.0 }); break; }
                case (Keyboard::Code::S): { position += translate<double, 3>(model_view, {  0.0, -0.1, 0.0 }); break; }
                case (Keyboard::Code::D): { position += translate<double, 3>(model_view, {  0.1,  0.0, 0.0 }); break; }
                default: { }
            }
        }
    }

public:

    virtual void OnCreate() override {
        set_frame_limit(60);
    }

    virtual bool OnUpdate(Time) override {
        clear();

        input_handle(Keyboard::Code::W);
        input_handle(Keyboard::Code::A);
        input_handle(Keyboard::Code::S);
        input_handle(Keyboard::Code::D);

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
