#include <unified.hpp>

using namespace Unified;

class Template : public Application
{
public:

    virtual bool OnUpdate(Time&) override {
        return poll_events();
    }

};

Application *UNIFIED_NAMESPACE::CreateApplication() {
    return new Template();
}
