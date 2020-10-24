#include <unified/application/application.hpp>

#ifndef UNIFIED_PLATFORM_LINUX_HPP
#define UNIFIED_PLATFORM_LINUX_HPP

int main() {
    Unified::Application *application = Unified::CreateApplication();
    application->run();
    delete application;
    return 0;
}

#endif
