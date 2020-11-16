#include <unified.hpp>

using namespace UNIFIED_NAMESPACE;

class Minimal : public Application
{
public:

    virtual bool OnUpdate(Time&) override {
        return poll_events();
    }

};

Application *UNIFIED_NAMESPACE::CreateApplication() {
    return new Minimal();
}
