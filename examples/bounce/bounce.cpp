#include <unified.hpp>

#include <unified/graphics/2d/camera.hpp>
#include <unified/graphics/2d/drawable/vertex_array.hpp>

#include <imgui_layer/imgui_layer.hpp>

using namespace Unified;
using namespace Unified::Graphics;

class CircleLayer;
class ImGuiLayer;

class ExampleBounce : public Application
{
public:

    Graphics2D::Camera camera;

    Color color;
    Point2d position, velocity;

    Graphics::Vertex2d circle[32];
    const u32 circle_vertices_count = sizeof(circle) / sizeof(*circle);

    void window_resize_event(const WindowResizeEvent &event) {
        set_viewport(event.size);
    }

    void keyboard_handle() {
        if (get_key_action(Keyboard::Code::W) == Keyboard::Action::Press)
            velocity.y += 0.05;

        if (get_key_action(Keyboard::Code::S) == Keyboard::Action::Press)
            velocity.y -= 0.05;

        if (get_key_action(Keyboard::Code::A) == Keyboard::Action::Press)
            velocity.x -= 0.05;

        if (get_key_action(Keyboard::Code::D) == Keyboard::Action::Press)
            velocity.x += 0.05;
    }

    void calculate_circle_position() {
        for (u32 i = 0; i < circle_vertices_count; ++i) {
            double theta = 6.28 * double(i) / circle_vertices_count;
            circle[i].point = { position.x + 0.1 * std::cos(theta), position.y + 0.1 * std::sin(theta) };
        }
    }

    void calculate_circle_color() {
        for (u32 i = 0; i < circle_vertices_count; ++i) {
            circle[i].color = color;
        }
    }

public:

    ExampleBounce() : Application("ExampleBounce", VideoMode(600, 600), !Window::Resizable) {
        push_layer<CircleLayer>(this);
        push_layer<ImGuiLayer>(this);
        set_frame_limit(60);
    }

    virtual bool OnUpdate(Time elapsed) override {
        clear();

        auto estimated_position = position + camera.get_projection() * velocity * elapsed.asSeconds();

        if (estimated_position.x >= 0.9 || estimated_position.x <= -0.9)
            velocity.x = -(velocity.x / 2.0);
        else if (estimated_position.y >= 0.9 || estimated_position.y <= -0.9)
            velocity.y = -(velocity.y / 2.0);
        else
            position = estimated_position, keyboard_handle(), calculate_circle_position();

        calculate_circle_color();

        process_layers();
        swap_buffers();
        return poll_events();
    }

    virtual void OnEvent(EventDispatcher &dispatcher) override {
        dispatcher.dispatch<WindowResizeEvent>(BIND_EVENT_FN(&ExampleBounce::window_resize_event, this));
    }

};

class CircleLayer : public Layer
{
public:

    ExampleBounce *application;

    Graphics2D::VertexArray vertex_array;

    CircleLayer(ExampleBounce *application) : application(application), vertex_array(PrimitiveType::Polygon, 32) {
        std::fill(application->circle, application->circle + 32, Vertex2d({ 1.f, 0.f, 1.f, 1.f }));
    }

    virtual void OnUpdate(Time) override {
        vertex_array.write(application->circle, sizeof(application->circle));
        application->draw(vertex_array);
    }

};

class ImGuiLayer : public Modules::ImGuiLayer
{
public:

    ExampleBounce *application;

    ImGuiLayer(ExampleBounce *application) : application(application) {
        Create(application);
    }

    virtual void OnUpdate(Time) override {
        ImGui::Begin("ExampleBounce");
        if (ImGui::CollapsingHeader("Info")) {
            ImGui::Text("Position: %lf, %lf", application->position.x, application->position.y);
            ImGui::Text("Velocity: %lf, %lf", application->velocity.x, application->velocity.y);
        }
        if (ImGui::CollapsingHeader("Properties")) {
            ImGui::ColorEdit3("Ball", (float*)&application->color);
        }
        ImGui::End();
    }

    ~ImGuiLayer() {
        Destroy();
    }

};

Application *UNIFIED_NAMESPACE::CreateApplication() {
    return new ExampleBounce();
}
