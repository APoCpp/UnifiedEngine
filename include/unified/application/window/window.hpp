#include <unified/core/string.hpp>
#include <unified/core/size2.hpp>

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

        Size2i get_size() const;
        void set_size(Size2i size);

        Point2i get_position() const;
        void set_position(Point2i point);

    private:

        string _title;
        glfw_wrapper *_window;
        
        VideoMode _mode;

    };
};

#endif