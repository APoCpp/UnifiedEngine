#include <unified.hpp>

#include <imgui_layer/imgui_layer.hpp>

using namespace Unified;

class ImGuiLayer : public Modules::ImGuiLayer
{
public:

    ImGuiLayer(Application *application) {
        Modules::ImGuiLayer::Create(application);
    }

    virtual ~ImGuiLayer() {
        Modules::ImGuiLayer::Destroy();
    }

    virtual void OnUpdate(Time) override {
        ImGui::Begin("ExampleInterfaces");
        ImGui::Text("Hello World!");
        ImGui::End();
    }

};

class ExampleInterfaces : public Application
{
public:

    void window_resize_event(const WindowResizeEvent &event) {
        set_viewport(event.size);
    }

public:

    ExampleInterfaces() : Application("ExampleInterfaces") {
        push_layer<ImGuiLayer>(this);
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
