#include <unified.hpp>

#include <unified/graphics/2d/drawable/vertex_array.hpp>

#include <imgui_layer/imgui_layer.hpp>

using namespace Unified;
using namespace Unified::Graphics;

class TriangleLayer : public Layer
{
public:

    const Application *application;

    Graphics::Vertex2d *triangle;

    Graphics2D::VertexArray vertex_array;

    TriangleLayer(Application *application, Graphics::Vertex2d *triangle) : application(application), triangle(triangle), vertex_array(PrimitiveType::Triangles, 3) { }

    virtual void OnUpdate(Time) override {
        vertex_array.write(triangle, sizeof(Graphics::Vertex2d[3]));
        application->draw(vertex_array);
    }

};
class ImGuiLayer : public Modules::ImGuiLayer
{
public:

    Graphics::Vertex2d *triangle;

    ImGuiLayer(Application *application, Graphics::Vertex2d *triangle) : triangle(triangle) {
        Create(application);
    }

    virtual ~ImGuiLayer() {
        Destroy();
    }

    virtual void OnUpdate(Time) override {
        ImGui::Begin("ExampleInterfaces");
        ImGui::ColorEdit3("LD", (float*)(&triangle[0].color));
        ImGui::ColorEdit3("CU", (float*)(&triangle[1].color));
        ImGui::ColorEdit3("RD", (float*)(&triangle[2].color));
        ImGui::End();
    }

};

class ExampleInterfaces : public Application
{
public:

    Graphics::Vertex2d triangle[3] = 
    { { { -0.8, -0.8 }, { 1.f, 0.f, 0.f, 1.f } },
      { {  0.0,  0.8 }, { 1.f, 0.f, 0.f, 1.f } },
      { {  0.8, -0.8 }, { 1.f, 0.f, 0.f, 1.f } } };

    void window_resize_event(const WindowResizeEvent &event) {
        set_viewport(event.size);
    }

public:

    ExampleInterfaces() : Application("ExampleInterfaces") {
        push_layer<TriangleLayer>(this, triangle);
        push_layer<ImGuiLayer>(this, triangle);
        set_frame_limit(60);
    }

    virtual bool OnUpdate(Time) override {
        clear();
        update_layers();
        swap_buffers();
        return poll_events();
    }

    virtual void OnEvent(EventDispatcher &dispatcher) override {
        dispatcher.dispatch<WindowResizeEvent>(BIND_EVENT_FN(&ExampleInterfaces::window_resize_event, this));
    }

};

Application *UNIFIED_NAMESPACE::CreateApplication() {
    return new ExampleInterfaces();
}
