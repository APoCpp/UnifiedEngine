#include <unified/defines.hpp>

#ifndef UNIFIED_APPLICATION_HPP
#define UNIFIED_APPLICATION_HPP

#include <unified/application/window/window.hpp>
#include <unified/core/clock.hpp>

UNIFIED_BEGIN_NAMESPACE

#define BIND_EVENT_FN(method, object) std::bind(method, object, std::placeholders::_1)

class Application : public Window
{
public:

    Application(string title = "Unified", VideoMode mode = VideoMode(800, 600), u32 style = Window::Resizable);
    virtual ~Application();

    _OSL_NODISCARD u32 get_frame_limit() const _OSL_NOEXCEPT;
    void set_frame_limit(u32 limit) _OSL_NOEXCEPT;

    void run();

protected:

    virtual void OnCreate();
    virtual bool OnUpdate(Time elapsed) = 0;
    virtual void OnClose();
    
    virtual void OnEvent(EventDispatcher &event);

protected:

    u32 _frame_limit;

    Clock _frame_clock;
    Time _frame_duration;

};

Application *CreateApplication();

UNIFIED_END_NAMESPACE

#endif
