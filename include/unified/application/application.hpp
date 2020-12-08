#ifndef _UNIFIED_APPLICATION_HPP
#define _UNIFIED_APPLICATION_HPP

# include <unified/application/window/window.hpp>
# include <unified/graphics/render_target.hpp>
# include <unified/core/clock.hpp>

# define BIND_EVENT_FN(method, object) std::bind(method, object, std::placeholders::_1)

UNIFIED_BEGIN_NAMESPACE

class Application : public Window, public UNIFIED_GRAPHICS_NAMESPACE::RenderTarget
{
public:

    Application(string title = "Unified", VideoMode video_mode = VideoMode(800, 600), u32 style = Window::Resizable);

    void run();

public:

    void set_viewport(Point2i size);

    UNIFIED_NODISCARD u32 get_frame_limit() const;
    void set_frame_limit(u32);

protected:

    virtual bool OnUpdate(Time&) = 0;
    virtual void OnEvent(EventDispatcher &event);

protected:

    u32 _frame_limit;

    Clock _frame_clock;
    Time _frame_duration;

};

Application *CreateApplication();

UNIFIED_END_NAMESPACE

#endif
