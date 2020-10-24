#include <unified.hpp>

using namespace Unified;

class Example : public Application
{
public:

    virtual bool OnUpdate(Time) override {
        return poll_events();
    }

};

Application *Unified::CreateApplication() {
    return new Example();
}
