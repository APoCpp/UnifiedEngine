#ifndef _UNIFIED_APPLICATION_HPP
#define _UNIFIED_APPLICATION_HPP

# include <unified/application/window/window.hpp>
# include <unified/graphics/render_target.hpp>
# include <unified/application/layer.hpp>
# include <unified/core/clock.hpp>

# include <utility>
# include <deque>

# define BIND_EVENT_FN(method, object) std::bind(method, object, std::placeholders::_1)

UNIFIED_BEGIN_NAMESPACE

class Application : public Window, public UNIFIED_GRAPHICS_NAMESPACE::RenderTarget
{
public:

    using layers_t = std::deque<Layer*>;

    Application(string title = "Unified", VideoMode video_mode = VideoMode(800, 600), u32 style = Window::Resizable);

    virtual ~Application() { }

    void run();

public:

    void set_viewport(Point2i size);

    UNIFIED_NODISCARD u32 get_frame_limit() const;
    void set_frame_limit(u32);

public:

    UNIFIED_NODISCARD const layers_t &layers() const;

    template <class _layer, class... _args>
    _layer *push_layer(_args&&... args) {
        _layer *new_layer = new _layer(std::forward<_args>(args)...);
        _layers.push_back(dynamic_cast<Layer*>(new_layer));
        return new_layer;
    }

protected:

    UNIFIED_NODISCARD layers_t &layers();

    void process_layer(Layer *layer);
    void process_layers();

    void dispatch_layers(EventDispatcher &dispatcher);

    virtual bool OnUpdate(Time) = 0;
    virtual void OnEvent(EventDispatcher &dispatcher);

private:

    u32 _frame_limit;

    Clock _frame_clock;
    Time _frame_duration;

    layers_t _layers;

};

Application *CreateApplication();

UNIFIED_END_NAMESPACE

#endif
