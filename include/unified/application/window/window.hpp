#ifndef _UNIFIED_APPLICATION_WINDOW_HPP
#define _UNIFIED_APPLICATION_WINDOW_HPP

# include <unified/application/event/window_maximize.hpp>
# include <unified/application/event/window_resize.hpp>
# include <unified/application/event/window_close.hpp>
# include <unified/application/event/window_focus.hpp>
# include <unified/application/event/mouse_press.hpp>
# include <unified/application/event/window_move.hpp>
# include <unified/application/event/cursor_move.hpp>
# include <unified/application/event/key_press.hpp>

# include <functional>

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

    bool poll_events();

    UNIFIED_NODISCARD Point2i get_size() const;
    void set_size(Point2i size);

    UNIFIED_NODISCARD Point2i get_position() const;
    void set_position(Point2i point);

    UNIFIED_NODISCARD bool get_vsync() const;
    void set_vsync(bool enabled);

    void swap_buffers();

    Keyboard::Action get_key_action(Keyboard::Code code);
    Point2d get_cursor_position();

    void set_event_callback(const event_callback_fn &callback);

protected:

    string _title;
    glfw_wrapper *_window;
    event_callback_fn _event_callback;

    VideoMode _video_mode;
    bool _vsync;

};

UNIFIED_END_NAMESPACE

#endif
