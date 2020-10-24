#include <unified/application/window/window.hpp>

#include <unified/core/exceptions.hpp>
#include <GLFW/glfw3.h>

UNIFIED_BEGIN_NAMESPACE

struct Window::glfw_wrapper {
    GLFWwindow *glfw_handle;
};

Window::Window(string title, VideoMode mode, u32 style) : _title(title), _window(new glfw_wrapper), _mode(mode), _vsync(false) {
    if (!glfwInit()) {
        throw UNIFIED_CORE_EXCEPTIONS_HPP("GLFW");
    }

    glfwWindowHint(GLFW_RESIZABLE, (style & Style::Resizable) == Style::Resizable);
    glfwWindowHint(GLFW_MAXIMIZED, (style & Style::Maximized) == Style::Maximized);
    glfwWindowHint(GLFW_FLOATING,  (style & Style::Floating)  == Style::Floating);

    _window->glfw_handle = glfwCreateWindow(mode.width, mode.height, title.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(_window->glfw_handle);

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

bool Window::poll_events() _OSL_NOEXCEPT {
    glfwPollEvents();
    return !glfwWindowShouldClose(_window->glfw_handle);
}

_OSL_NODISCARD Vector2i Window::get_size() const _OSL_NOEXCEPT {
    glfwGetWindowSize(_window->glfw_handle, (int*)&_mode.width, (int*)&_mode.height);
    return Vector2i(_mode.width, _mode.height);
}

void Window::set_size(Vector2i size) _OSL_NOEXCEPT {
    glfwSetWindowSize(_window->glfw_handle, size.x, size.y);
}

_OSL_NODISCARD Vector2i Window::get_position() const _OSL_NOEXCEPT {
    Vector2i point;
    glfwGetWindowPos(_window->glfw_handle, &point.x, &point.y);
    return point;
}

void Window::set_position(Vector2i point) _OSL_NOEXCEPT {
    glfwSetWindowPos(_window->glfw_handle, point.x, point.y);
}

_OSL_NODISCARD bool Window::get_vsync() const _OSL_NOEXCEPT {
    return _vsync;
}

void Window::set_vsync(bool enabled) _OSL_NOEXCEPT {
    glfwSwapInterval(_vsync = enabled);
}

void Window::set_event_callback(const event_callback_fn &callback) _OSL_NOEXCEPT {
    _event_callback = callback;
}

UNIFIED_END_NAMESPACE
