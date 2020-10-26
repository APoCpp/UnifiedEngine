#include <unified.hpp>
#include <cstdio>

using namespace Unified;

class Example : public Application
{
public:

    void window_maximize_event(WindowMaximizeEvent& event) {
        printf(event.maximized ? "maximized\n" : "minimized\n");
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
        dispatcher.dispatch<WindowMaximizeEvent>(BIND_EVENT_FN(&Example::window_maximize_event, this));
    }

};

Application *Unified::CreateApplication() {
    return new Example();
}
