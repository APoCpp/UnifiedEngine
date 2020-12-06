#include <unified/application/window/window.hpp>

#include <unified/core/exceptions.hpp>
#include <GLFW/glfw3.h>

UNIFIED_BEGIN_NAMESPACE

struct Window::glfw_wrapper {
    GLFWwindow *glfw_handle;
};

Window::Window(string title, VideoMode video_mode, u32 style) : _title(title), _window(new glfw_wrapper), _video_mode(video_mode), _vsync(false) {
    if (!glfwInit())
        throw EXCEPTION_INITIALIZATION_FAILED("failed to initialize glfw");

    glfwWindowHint(GLFW_RESIZABLE, (style & Style::Resizable) == Style::Resizable);
    glfwWindowHint(GLFW_MAXIMIZED, (style & Style::Maximized) == Style::Maximized);
    glfwWindowHint(GLFW_FLOATING,  (style & Style::Floating)  == Style::Floating);

    _window->glfw_handle = glfwCreateWindow(video_mode.width, video_mode.height, title.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(_window->glfw_handle);

    set_vsync(_vsync);

    glfwSetWindowUserPointer(_window->glfw_handle, &_event_callback);
    glfwSetWindowCloseCallback(_window->glfw_handle, [](GLFWwindow *window) -> void {
        event_callback_fn &dispatch_function = *reinterpret_cast<event_callback_fn*>(glfwGetWindowUserPointer(window));
        WindowCloseEvent window_close;
        EventDispatcher event(window_close);
        dispatch_function(event);
    });

    glfwSetWindowPosCallback(_window->glfw_handle, [](GLFWwindow *window, int x, int y) -> void {
        event_callback_fn &dispatch_function = *reinterpret_cast<event_callback_fn*>(glfwGetWindowUserPointer(window));
        WindowMoveEvent window_move_event(x, y);
        EventDispatcher event(window_move_event);
        dispatch_function(event);
    });

    glfwSetWindowFocusCallback(_window->glfw_handle, [](GLFWwindow *window, int focused) -> void {
        event_callback_fn &dispatch_function = *reinterpret_cast<event_callback_fn*>(glfwGetWindowUserPointer(window));
        WindowFocusEvent window_focus_event(focused);
        EventDispatcher event(window_focus_event);
        dispatch_function(event);
    });

    glfwSetWindowSizeCallback(_window->glfw_handle, [](GLFWwindow *window, int horizontal, int vertical) -> void {
        event_callback_fn &dispatch_function = *reinterpret_cast<event_callback_fn*>(glfwGetWindowUserPointer(window));
        WindowResizeEvent window_resize_event(horizontal, vertical);
        EventDispatcher event(window_resize_event);
        dispatch_function(event);
    });

    glfwSetKeyCallback(_window->glfw_handle, [](GLFWwindow *window, int key, int, int action, int) -> void {
        event_callback_fn &dispatch_function = *reinterpret_cast<event_callback_fn*>(glfwGetWindowUserPointer(window));
        KeyPressEvent key_press_event(key, action);
        EventDispatcher event(key_press_event);
        dispatch_function(event);
    });

    glfwSetCursorPosCallback(_window->glfw_handle, [](GLFWwindow *window, double x, double y) -> void {
        event_callback_fn &dispatch_function = *reinterpret_cast<event_callback_fn*>(glfwGetWindowUserPointer(window));
        CursorMoveEvent cursor_move_event(x, y);
        EventDispatcher event(cursor_move_event);
        dispatch_function(event);
    });

    glfwSetMouseButtonCallback(_window->glfw_handle, [](GLFWwindow *window, int button, int action, int) -> void {
        event_callback_fn &dispatch_function = *reinterpret_cast<event_callback_fn*>(glfwGetWindowUserPointer(window));
        MousePressEvent mouse_press_event(button, action);
        EventDispatcher event(mouse_press_event);
        dispatch_function(event);
    });

    glfwSetWindowMaximizeCallback(_window->glfw_handle, [](GLFWwindow *window, int maximized) -> void {
        event_callback_fn &dispatch_function = *reinterpret_cast<event_callback_fn*>(glfwGetWindowUserPointer(window));
        WindowMaximizeEvent window_maximize_event(maximized);
        EventDispatcher event(window_maximize_event);
        dispatch_function(event);
    });
}

bool Window::poll_events() {
    glfwPollEvents();
    return !glfwWindowShouldClose(_window->glfw_handle);
}

UNIFIED_NODISCARD Point2i Window::get_size() const {
    glfwGetWindowSize(_window->glfw_handle, (int*)&_video_mode.width, (int*)&_video_mode.height);
    return Point2i(_video_mode.width, _video_mode.height);
}

void Window::set_size(Point2i size) {
    glfwSetWindowSize(_window->glfw_handle, size.x, size.y);
}

UNIFIED_NODISCARD Point2i Window::get_position() const {
    Point2i point;
    glfwGetWindowPos(_window->glfw_handle, &point.x, &point.y);
    return point;
}

void Window::set_position(Point2i point) {
    glfwSetWindowPos(_window->glfw_handle, point.x, point.y);
}

UNIFIED_NODISCARD bool Window::get_vsync() const {
    return _vsync;
}

void Window::set_vsync(bool enabled) {
    glfwSwapInterval(_vsync = enabled);
}

void Window::swap_buffers() {
    glfwSwapBuffers(_window->glfw_handle);
}

Keyboard::Action Window::get_key_action(Keyboard::Code code) {
    return (Keyboard::Action)glfwGetKey(_window->glfw_handle, (int)code);
}

void Window::set_event_callback(const event_callback_fn &callback) {
    _event_callback = callback;
}

UNIFIED_END_NAMESPACE
