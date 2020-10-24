#include <unified.hpp>
#include <cstdio>

using namespace Unified;

class Example : public Application
{
public:

    void key_press_event(KeyPressEvent& event) {
        printf("key: %i, action: %i\n", event.key, event.action);
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
        dispatcher.dispatch<KeyPressEvent>(BIND_EVENT_FN(&Example::key_press_event, this));
    }

};

Application *Unified::CreateApplication() {
    return new Example();
}
