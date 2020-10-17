#include <unified/application/application.hpp>

#ifndef UNIFIED_PLATFORM_WINDOWS_HPP
#define UNIFIED_PLATFORM_WINDOWS_HPP

# if defined(_RELEASE_)
#  if defined(WINAPI)
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, INT nCmdShow)
#  else
int WinMain()
#  endif
# else
int main()
# endif
{
    Unified::Application *application = Unified::CreateApplication();
    application->run();
    delete application;
    return 0;
}

#endif