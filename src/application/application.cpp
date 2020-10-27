#include <unified/application/application.hpp>
#include <unified/core/system/sleep.hpp>
#include <GLFW/glfw3.h>

UNIFIED_BEGIN_NAMESPACE

Application::Application(string title, VideoMode mode, u32 style) : Window(title, mode, style), _frame_limit(0), _frame_clock() {
    set_event_callback(BIND_EVENT_FN(&Application::OnEvent, this));
}

Application::~Application() _OSL_NOEXCEPT { }

_OSL_NODISCARD u32 Application::get_frame_limit() const _OSL_NOEXCEPT {
    return _frame_limit;
}

void Application::set_frame_limit(u32 limit) _OSL_NOEXCEPT {
    if (limit != 0) {
        _frame_limit = limit;
        _frame_duration = seconds(1.0 / _frame_limit);
    }
}

void Application::run() {
    OnCreate();

    Time elapsed;
    while (OnUpdate(elapsed)) {
        elapsed = _frame_clock.get_elapsed_time(); 
        _frame_clock.restart();
        if (_frame_duration > elapsed) {
            sleep(_frame_duration - elapsed);
        }
    }

    OnClose();
}

void Application::OnCreate() { }
void Application::OnClose() { }

void Application::OnEvent(EventDispatcher&) { }

UNIFIED_END_NAMESPACE
