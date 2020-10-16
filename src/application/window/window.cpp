#include <unified/application/window/window.hpp>

#include <unified/core/exceptions.hpp>
#include <GLFW/glfw3.h>

struct Unified::Window::glfw_wrapper {
    GLFWwindow *glfw_handle;
};

Unified::Window::Window(string title, VideoMode mode, u32 style) : _title(title), _mode(mode), _window(new glfw_wrapper) {
    if (!glfwInit()) {
        throw EXCEPTION_INITIALIZATION_FAILED("GLFW");
    }

    glfwWindowHint(GLFW_RESIZABLE, (style & Style::Resizable) == Style::Resizable);
    glfwWindowHint(GLFW_MAXIMIZED, (style & Style::Maximized) == Style::Maximized);
    glfwWindowHint(GLFW_FLOATING,  (style & Style::Floating)  == Style::Floating);

    _window->glfw_handle = glfwCreateWindow(mode.width, mode.height, title.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(_window->glfw_handle);   
}

bool Unified::Window::poll_events() {
    glfwPollEvents();
    return !glfwWindowShouldClose(_window->glfw_handle);
}

Unified::Size2i Unified::Window::get_size() const {
    glfwGetWindowSize(_window->glfw_handle, (int*)&_mode.width, (int*)&_mode.height);
    return Size2i(_mode.width, _mode.height);
}

void Unified::Window::set_size(Size2i size) {
    glfwSetWindowSize(_window->glfw_handle, size.x, size.y);
}

Unified::Point2i Unified::Window::get_position() const {
    Point2i point;
    glfwGetWindowPos(_window->glfw_handle, (int*)&point.x, (int*)&point.y);
    return point;
}

void Unified::Window::set_position(Point2i point) {
    glfwSetWindowPos(_window->glfw_handle, point.x, point.y);
}