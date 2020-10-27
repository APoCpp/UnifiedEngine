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

#include <unified/core/math/vector2.hpp>
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

    virtual ~Window() _OSL_NOEXCEPT = default;

    bool poll_events() _OSL_NOEXCEPT;

    _OSL_NODISCARD Vector2i get_size() const _OSL_NOEXCEPT;
    void set_size(Vector2i size) _OSL_NOEXCEPT;

    _OSL_NODISCARD Vector2i get_position() const _OSL_NOEXCEPT;
    void set_position(Vector2i point) _OSL_NOEXCEPT;

    _OSL_NODISCARD bool get_vsync() const _OSL_NOEXCEPT;
    void set_vsync(bool enabled) _OSL_NOEXCEPT;

    void swap_buffers() _OSL_NOEXCEPT;

    void set_event_callback(const event_callback_fn &callback) _OSL_NOEXCEPT;

protected:

    string _title;
    glfw_wrapper *_window;
    event_callback_fn _event_callback;
        
    VideoMode _mode;
    bool _vsync;

};

UNIFIED_END_NAMESPACE

#endif
