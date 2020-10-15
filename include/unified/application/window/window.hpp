#include <unified/core/string.hpp>

#ifndef UNIFIED_WINDOW_HPP
#define UNIFIED_WINDOW_HPP

namespace Unified
{
    class Window
    {
    private:

        struct glfw_wrapper;

    public:

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

    private:

        string _title;
        glfw_wrapper *_window;
        
        VideoMode _mode;

    };
};

#endif