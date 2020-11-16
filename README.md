# UnifiedEngine v0.0.1
Simple open source game development kit.

## Minimal Example
```cpp
#include <unified.hpp>

using namespace Unified;

class Example : public Application
{
public:

    virtual bool OnUpdate(Time) override {
        return poll_events();
    }

};

Application *Unified::CreateApplication() {
    return new Example();
}
```

## Dependencies
* [fmt](https://github.com/fmtlib/fmt)
* [glfw](https://github.com/glfw/glfw)
* [glad](https://glad.dav1d.de)
