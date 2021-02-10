#include <unified.hpp>

#include <unified/core/math/point4.hpp>

#include <unified/graphics/2d/drawable/vertex_array.hpp>
#include <unified/graphics/shader.hpp>

#include <unified/core/system/sleep.hpp>

#include <imgui_layer/imgui_layer.hpp>

using namespace Unified;
using namespace Unified::Graphics;

class FluidLayer;
class ImGuiLayer;

class ExampleInterfaces : public Application
{
public:

    Time start_time;

    float wave_matrix[4] = { 0.9, 0.9, 0.9, -0.9 };

    Vertex2d quad[4] =
    { { { -1.0, -1.0 }, { 1.0, 0.0, 0.0, 1.0 } },
      { { -1.0,  1.0 }, { 0.0, 1.0, 0.0, 1.0 } },
      { {  1.0,  1.0 }, { 0.0, 0.0, 1.0, 1.0 } },
      { {  1.0, -1.0 }, { 1.0, 1.0, 0.0, 1.0 } } };

    void window_resize_event(const WindowResizeEvent &event) {
        set_viewport(event.size);
    }

public:

    ExampleInterfaces() : Application("ExampleFluid", VideoMode(800, 600), Application::Floating), start_time(get_current_time()) {
        push_layer<FluidLayer>(this);
        push_layer<ImGuiLayer>(this);
        set_frame_limit(60);
    }

    virtual bool OnUpdate(Time) override {
        clear();
        process_layers();
        swap_buffers();
        return poll_events();
    }

    virtual void OnEvent(EventDispatcher &dispatcher) override {
        dispatcher.dispatch<WindowResizeEvent>(BIND_EVENT_FN(&ExampleInterfaces::window_resize_event, this));
    }

};

class FluidLayer : public Layer
{
public:

    ExampleInterfaces *application;

    Graphics2D::VertexArray vertex_array;

    Shader shader;

    FluidLayer(ExampleInterfaces *application)
        : application(application), vertex_array(PrimitiveType::Polygon, 4), shader(
            #include "fluid.vert"
                ,
            #include "fluid.frag"
        ) { }

    virtual void OnUpdate(Time) override {
        shader.set_float("start_time", static_cast<float>(get_current_time().asSeconds() - application->start_time.asSeconds()));

        auto resolution = application->get_size();
        shader.set_float2("resolution", { static_cast<float>(resolution.x), static_cast<float>(resolution.y) });
        shader.set_float4("wave_matrix", application->wave_matrix);

        vertex_array.write(application->quad, sizeof(application->quad));
        application->draw(vertex_array, &shader);
    }

};

class ImGuiLayer : public Modules::ImGuiLayer
{
public:

    ExampleInterfaces *application;

    ImGuiLayer(ExampleInterfaces *application) : application(application) {
        Create(application);
    }

    virtual void OnUpdate(Time) override {
        ImGui::Begin("ExampleFluid");
        if (ImGui::CollapsingHeader("Waves")) {
            ImGui::InputFloat4("Wave Matrix", application->wave_matrix);
        }
        if (ImGui::CollapsingHeader("Background")) {
            ImGui::ColorEdit3("Down Left", (float*)&application->quad[0].color);
            ImGui::ColorEdit3("Down Right", (float*)&application->quad[3].color);
            ImGui::ColorEdit3("Up Left", (float*)&application->quad[1].color);
            ImGui::ColorEdit3("Up Right", (float*)&application->quad[2].color);
        }
        ImGui::End();
    }

    ~ImGuiLayer() {
        Destroy();
    }

};

Application *UNIFIED_NAMESPACE::CreateApplication() {
    return new ExampleInterfaces();
}
