#include <unified.hpp>

#include <unified/core/math/point3.hpp>

#include <unified/graphics/2d/camera.hpp>
#include <unified/graphics/2d/drawable/vertex_array.hpp>

#include <imgui_layer/imgui_layer.hpp>

using namespace Unified;
using namespace Unified::Graphics;

class BallLayer;
class ImGuiLayer;

class ExampleBounce : public Application
{
public:

    Point2d camera_position = { 0.0, 0.0 };

    Point2d ball_position = { 0.0, 0.0 };
    Point2d ball_velocity = { 0.0, 0.0 };

    Color ball_color = { 0.8f, 0.8f, 0.8f };

    Vertex2d ball_vertices[64];
    u32 ball_vertices_count = sizeof(ball_vertices) / sizeof(*ball_vertices);

    Graphics2D::Camera camera;
    Graphics2D::VertexArray vertex_array;

public:

    void keyboard_handle() {
        if (get_key_action(Keyboard::Code::W) == Keyboard::Action::Press)
            ball_velocity.y += 0.01;

        if (get_key_action(Keyboard::Code::A) == Keyboard::Action::Press)
            ball_velocity.x -= 0.01;

        if (get_key_action(Keyboard::Code::S) == Keyboard::Action::Press)
            ball_velocity.y -= 0.01;

        if (get_key_action(Keyboard::Code::D) == Keyboard::Action::Press)
            ball_velocity.x += 0.01;

        if (get_key_action(Keyboard::Code::Up) == Keyboard::Action::Press)
            camera_position.y += 0.01;

        if (get_key_action(Keyboard::Code::Left) == Keyboard::Action::Press)
            camera_position.x -= 0.01;

        if (get_key_action(Keyboard::Code::Down) == Keyboard::Action::Press)
            camera_position.y -= 0.01;

        if (get_key_action(Keyboard::Code::Right) == Keyboard::Action::Press)
            camera_position.x += 0.01;
    }

    void calculate_ball_position() {
        for (u32 i = 0; i < ball_vertices_count; ++i) {
            double theta = 6.28 * double(i) / ball_vertices_count;
            ball_vertices[i].point = camera.get_projection() * Point3d(ball_position.x + 0.1 * std::cos(theta), ball_position.y + 0.1 * std::sin(theta), 1.0);
        }
    }

    void calculate_ball_color() {
        for (u32 i = 0; i < ball_vertices_count; ++i) {
            ball_vertices[i].color = ball_color;
        }
    }

    void window_resize_event(const WindowResizeEvent &event) {
        set_viewport(event.size);
    }

public:

    ExampleBounce() : Application("ExampleBounce", VideoMode(600, 600), !Window::Resizable), camera(camera_position),
        vertex_array(PrimitiveType::Polygon, 64) {
        push_layer<BallLayer>(this);
        push_layer<ImGuiLayer>(this);
        set_frame_limit(60);
    }

    virtual bool OnUpdate(Time elapsed) override {
        clear({ 0.15, 0.15, 0.15 });

        camera.set_position(camera_position);

        auto estimated_position = ball_position + ball_velocity * elapsed.asSeconds();

        if (estimated_position.x >= 0.9 || estimated_position.x <= -0.9)
            ball_velocity.x = -(ball_velocity.x / 2.0);
        else if (estimated_position.y >= 0.9 || estimated_position.y <= -0.9)
            ball_velocity.y = -(ball_velocity.y / 2.0);
        else
            ball_position = estimated_position, keyboard_handle(), calculate_ball_position();

        calculate_ball_color();
        keyboard_handle();

        process_layers();
        swap_buffers();
        return poll_events();
    }

    virtual void OnEvent(EventDispatcher &dispatcher) override {
        dispatcher.dispatch<WindowResizeEvent>(BIND_EVENT_FN(&ExampleBounce::window_resize_event, this));
    }

};

class BallLayer : public Layer
{
public:

    ExampleBounce *application;

    BallLayer(ExampleBounce *application) : application(application), _ball_polygon(PrimitiveType::Polygon, 64) { }

    virtual void OnUpdate(Time) override {
        _ball_polygon.write(application->ball_vertices, sizeof(application->ball_vertices));
        application->draw(_ball_polygon);
    }

protected:

    Graphics2D::VertexArray _ball_polygon;

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

        if (ImGui::CollapsingHeader("Camera")) {
            ImGui::Text("Camera position: { %lf, %lf }", application->camera_position.x, application->camera_position.y);
            if (ImGui::Button("Camera reset")) {
                application->camera_position = { 0.0, 0.0 };
            }
        }

        if (ImGui::CollapsingHeader("Ball")) {
            ImGui::Text("Ball position: { %lf, %lf }", application->ball_position.x, application->ball_position.y);
            ImGui::Text("Ball velocity: { %lf, %lf }", application->ball_velocity.x, application->ball_velocity.y);
            if (ImGui::Button("Ball reset")) {
                application->ball_position = { 0.0, 0.0 };
                application->ball_velocity = { 0.0, 0.0 };
            }
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
