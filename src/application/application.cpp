#include <unified/application/application.hpp>
#include <unified/core/system/sleep.hpp>
#include <glad/glad.h>

UNIFIED_BEGIN_NAMESPACE

Application::Application(string title, VideoMode video_mode, u32 style)
    : Window(title, video_mode, style), _frame_limit(0), _frame_clock(), _frame_duration(0), _layers() {
    set_event_callback(BIND_EVENT_FN(&Application::OnEvent, this));
}

void Application::run() {
    Time elapsed;
    while (OnUpdate(elapsed)) {
        elapsed = _frame_clock.get_elapsed_time();
        _frame_clock.restart();
        if (_frame_duration > elapsed) {
            sleep(_frame_duration - elapsed);
        }
    }
}

void Application::set_viewport(Point2i size) {
    glViewport(0, 0, _video_mode.width = size.x, _video_mode.height = size.y);
}

UNIFIED_NODISCARD u32 Application::get_frame_limit() const {
    return _frame_limit;
}

void Application::set_frame_limit(u32 limit) {
    if (limit != 0) {
        _frame_limit = limit;
        _frame_duration = seconds(1.0 / _frame_limit);
    } else {
        _frame_duration = microseconds(0);
    }
}

void Application::update_layers() {
    for (auto it = _layers.begin(); it != _layers.end(); ++it) {
        (*it)->OnPreUpdate();
        (*it)->OnUpdate(_frame_clock.get_elapsed_time());
        (*it)->OnPostUpdate();
    }
}

void Application::pop_layer() {
    delete _layers.front();
    _layers.pop_front();
}

void Application::dispatch_layers(EventDispatcher &dispatcher) {
    for (auto it = _layers.begin(); it != _layers.end(); ++it)
        (*it)->OnEvent(dispatcher);
}

void Application::OnEvent(EventDispatcher &dispatcher) {
    dispatch_layers(dispatcher);
}

UNIFIED_END_NAMESPACE
