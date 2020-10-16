#include <unified/application/window/window.hpp>

#include <unified/core/exceptions.hpp>
#include <GLFW/glfw3.h>

struct Unified::Window::glfw_wrapper {
    GLFWwindow *glfw_handle;
};

Unified::Window::Window(string title, VideoMode mode, u32 style) : _title(title), _mode(mode), _window(new glfw_wrapper) {
    if (!glfwInit()) {
        throw URE_INITIALIZATION_FAILED("GLFW");
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