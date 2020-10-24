#include <unified.hpp>
#include <cstdio>

using namespace Unified;

class Example : public Application
{
public:

    virtual bool OnUpdate(Time elapsed) override {
        return poll_events();
    }

    virtual void OnEvent(Event &event) override {
        printf("%s\n", event.get_name().c_str());
    }

};

Application *Unified::CreateApplication() {
    return new Example();
}
