#ifndef UNIFIED_APPLICATION_WINDOW_HPP
#define UNIFIED_APPLICATION_WINDOW_HPP

#include <unified/defines.hpp>

#include <unified/application/event/window_maximize.hpp>
#include <unified/application/event/window_resize.hpp>
#include <unified/application/event/window_close.hpp>
#include <unified/application/event/window_focus.hpp>
#include <unified/application/event/mouse_press.hpp>
#include <unified/application/event/window_move.hpp>
#include <unified/application/event/cursor_move.hpp>
#include <unified/application/event/key_press.hpp>

#include <unified/core/math/point2.hpp>
#include <unified/core/string.hpp>

#include <functional>

UNIFIED_BEGIN_NAMESPACE

class Window
{
private:

    struct glfw_wrapper;

public:

    using event_callback_fn = std::function<void(EventDispatcher&)>;

    struct VideoMode
    {
        int width, height;
        VideoMode(int width, int height) : width(width), height(height) { }
    };

    enum Style : u32
    {
        Resizable = 1 << 0,
        Maximized = 1 << 1,
        Floating  = 1 << 2,
    };

public:

    Window(string title, VideoMode mode, u32 style);

    virtual ~Window() _UNIFIED_NOEXCEPT = default;

    bool poll_events() _UNIFIED_NOEXCEPT;

    _UNIFIED_NODISCARD Point2i get_size() const _UNIFIED_NOEXCEPT;
    void set_size(Point2i size) _UNIFIED_NOEXCEPT;

    _UNIFIED_NODISCARD Point2i get_position() const _UNIFIED_NOEXCEPT;
    void set_position(Point2i point) _UNIFIED_NOEXCEPT;

    _UNIFIED_NODISCARD bool get_vsync() const _UNIFIED_NOEXCEPT;
    void set_vsync(bool enabled) _UNIFIED_NOEXCEPT;

    void swap_buffers() _UNIFIED_NOEXCEPT;

    Keyboard::Action get_key_action(Keyboard::Code code);

    void set_event_callback(const event_callback_fn &callback) _UNIFIED_NOEXCEPT;

protected:

    string _title;
    glfw_wrapper *_window;
    event_callback_fn _event_callback;
        
    VideoMode _video_mode;
    bool _vsync;

};

UNIFIED_END_NAMESPACE

#endif
