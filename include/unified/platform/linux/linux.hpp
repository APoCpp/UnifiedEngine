#ifndef _UNIFIED_PLATFORM_LINUX_HPP
#define _UNIFIED_PLATFORM_LINUX_HPP

# include <unified/application/application.hpp>

int main() {
    UNIFIED_NAMESPACE::Application *application = UNIFIED_NAMESPACE::CreateApplication();
    application->run();
    delete application;
    return 0;
}

#endif
