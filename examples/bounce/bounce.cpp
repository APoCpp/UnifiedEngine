#include <unified.hpp>

#include <unified/graphics/2d/drawable/vertex_array.hpp>
#include <unified/graphics/camera.hpp>

#include <unified/core/math/point4.hpp>

#include <imgui_layer/imgui_layer.hpp>

using namespace Unified;
using namespace Unified::Graphics;

class CubeLayer;
class ImGuiLayer;

class ExampleBounce : public Application
{
public:

    Camera camera;

    Point2d position;
    Point4d velocity;

    Graphics::Vertex2d circle[32];
    const u32 circle_vertices_count = sizeof(circle) / sizeof(*circle);

    void window_resize_event(const WindowResizeEvent &event) {
        set_viewport(event.size);
    }

public:

    ExampleBounce() : Application("ExampleBounce", VideoMode(600, 600), !Window::Resizable) {
        Modules::ImGuiLayer::Create(this);
        push_layer<CubeLayer>(this);
        push_layer<ImGuiLayer>(this);
        set_frame_limit(60);
        for (u32 i = 0; i < circle_vertices_count; ++i) {
            circle[i].color = { 1.f, 0.f, 1.f, 1.f }; 
        }
    }

    virtual ~ExampleBounce() {
        Modules::ImGuiLayer::Destroy();
    }

    virtual bool OnUpdate(Time elapsed) override {
        clear();

        auto offset = camera.get_projection() * (velocity * static_cast<double>(elapsed.asMilliseconds()));
        auto estimate_position = position + Point2d(offset.x, offset.y);
        
        if (estimate_position.x >= 0.9 || estimate_position.x <= -0.9) {
            velocity.x = -(velocity.x / 2.0);
        } else if (estimate_position.y >= 0.9 || estimate_position.y <= -0.9) {
            velocity.y = -(velocity.y / 2.0);
        } else {            
            position = estimate_position;

            if (this->get_key_action(Keyboard::Code::W) == Keyboard::Action::Press)
                velocity.y += 0.0001;

            if (this->get_key_action(Keyboard::Code::S) == Keyboard::Action::Press)
                velocity.y -= 0.0001;

            if (this->get_key_action(Keyboard::Code::A) == Keyboard::Action::Press)
                velocity.x -= 0.0001;

            if (this->get_key_action(Keyboard::Code::D) == Keyboard::Action::Press)
                velocity.x += 0.0001;

            for (u32 i = 0; i < circle_vertices_count; ++i) {
                double theta = 2.0 * 3.14 * float(i) / circle_vertices_count;
                circle[i].point = { position.x + (0.1 * std::cos(theta)), position.y + (0.1 * std::sin(theta)) };
            }
        }

        process_layers();

        swap_buffers();
        return poll_events();
    }

    virtual void OnEvent(EventDispatcher &dispatcher) override {
        dispatcher.dispatch<WindowResizeEvent>(BIND_EVENT_FN(&ExampleBounce::window_resize_event, this));
    }

};

class CubeLayer : public Layer
{
public:

    ExampleBounce *application;

    Graphics2D::VertexArray vertex_array;

    CubeLayer(ExampleBounce *application) : application(application), vertex_array(PrimitiveType::Polygon, 32) { }

    virtual void OnUpdate(Time) override {
        vertex_array.write(application->circle, sizeof(application->circle));
        application->draw(vertex_array);
    }

};

class ImGuiLayer : public Modules::ImGuiLayer
{
public:

    ExampleBounce *application;

    ImGuiLayer(ExampleBounce *application) : application(application) { }

    virtual void OnUpdate(Time) override {
        ImGui::Begin("ExampleBounce");
        ImGui::End();
    }

};

Application *UNIFIED_NAMESPACE::CreateApplication() {
    return new ExampleBounce();
}
