#include <unified/application/application.hpp>
#include <unified/core/system/sleep.hpp>
#include <GLFW/glfw3.h>

Unified::Application::Application(string title, VideoMode mode, u32 style) : Window(title, mode, style), _frame_limit(0), _frame_clock() { }

Unified::Application::~Application() { }

_OSL_NODISCARD u32 Unified::Application::get_frame_limit() const _OSL_NOEXCEPT {
    return _frame_limit;
}

void Unified::Application::set_frame_limit(u32 limit) _OSL_NOEXCEPT {
    if (limit != 0) {
        _frame_limit = limit;
        _frame_duration = seconds(1.0 / _frame_limit);
    }
}

void Unified::Application::run() {
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

void Unified::Application::OnCreate() { }
void Unified::Application::OnClose() { }