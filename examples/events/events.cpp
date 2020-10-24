#include <unified.hpp>
#include <cstdio>

using namespace Unified;

class Example : public Application
{
public:

    void window_resize_event(WindowResizeEvent& event) {
        printf("horizontal: %i, vertical: %i\n", event.size.x, event.size.y);
    }

public:

    virtual void OnCreate() override {
        printf("window created\n");
    }

    virtual bool OnUpdate(Time) override {
        return poll_events();
    }

    virtual void OnClose() override {
        printf("window closed\n");
    }

    virtual void OnEvent(EventDispatcher &dispatcher) override {
        dispatcher.dispatch<WindowResizeEvent>(BIND_EVENT_FN(&Example::window_resize_event, this));
    }

};

Application *Unified::CreateApplication() {
    return new Example();
}
