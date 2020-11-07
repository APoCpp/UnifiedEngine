#ifndef UNIFIED_APPLICATION_HPP
#define UNIFIED_APPLICATION_HPP

#include <unified/defines.hpp>

#include <unified/application/window/window.hpp>
#include <unified/graphics/render_target.hpp>

#include <unified/core/clock.hpp>

UNIFIED_BEGIN_NAMESPACE

#define BIND_EVENT_FN(method, object) std::bind(method, object, std::placeholders::_1)

class Application : public Window, public RenderTarget
{
public:

    Application(string title = "Unified", VideoMode video_mode = VideoMode(800, 600), u32 style = Window::Resizable);
    virtual ~Application() _UNIFIED_NOEXCEPT;

    void run();

public:

    _UNIFIED_NODISCARD u32 get_frame_limit() const _UNIFIED_NOEXCEPT;
    void set_frame_limit(u32 limit) _UNIFIED_NOEXCEPT;

    void set_viewport(Point2i size) _UNIFIED_NOEXCEPT;

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
