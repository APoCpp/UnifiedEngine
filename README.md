# UnifiedEngine
Simple open source game development kit.

## Example
```cpp
#include <unified.hpp>

using namespace Unified;

class Example : public Application
{
public:

    virtual bool OnUpdate(Time elapsed) override {
        return poll_events();
    }

};

Application *Unified::CreateApplication() {
    return new Example();
}
```