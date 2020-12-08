#define UNIFIED_LIBRARY_MODE

#include <unified.hpp>

using namespace Unified;

class Template : public Application
{
public:

    using Application::Application;

    virtual bool OnUpdate(Time&) override {
        return poll_events();
    }

};

int main() {
    Template application("Template");
    application.run();
    return 0;
}
