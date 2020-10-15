#ifndef UNIFIED_APPLICATION_HPP
#define UNIFIED_APPLICATION_HPP

namespace Unified
{
    class Application
    {
    public:

        virtual ~Application();

        void run();

    protected:

        virtual void OnCreate();
        virtual bool OnUpdate() = 0;
        virtual void OnClose();

    };

    Application *CreateApplication();
}

#endif