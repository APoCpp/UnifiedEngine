#include <unified/application/window/window.hpp>
#include <unified/core/clock.hpp>

#ifndef UNIFIED_APPLICATION_HPP
#define UNIFIED_APPLICATION_HPP

namespace Unified
{
    class Application : public Window
    {
    public:

        Application(string title = "Unified", VideoMode mode = VideoMode(800, 600), u32 style = Window::Floating);
        virtual ~Application();

        _OSL_NODISCARD u32 get_frame_limit() const _OSL_NOEXCEPT;
        void set_frame_limit(u32 limit) _OSL_NOEXCEPT;

        void run();

    protected:

        virtual void OnCreate();
        virtual bool OnUpdate(Time elapsed) = 0; // @note: elapsed in seconds
        virtual void OnClose();

    protected:

        Clock _frame_clock;

        u32 _frame_limit;
        Time _frame_duration;        

    };

    Application *CreateApplication();
}

#endif