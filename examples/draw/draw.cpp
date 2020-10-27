#include <unified.hpp>

#include <glad/glad.h>

#include <unified/graphics/vertex_buffer.hpp>

using namespace Unified;

class Example : public Application
{
public:

    virtual bool OnUpdate(Time) override {
        clear();
        reset_gl_states();

        swap_buffers();
        return poll_events();
    }

};

Application *Unified::CreateApplication() {
    return new Example();
}
