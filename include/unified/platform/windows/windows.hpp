#ifndef _UNIFIED_PLATFORM_WINDOWS_HPP
#define _UNIFIED_PLATFORM_WINDOWS_HPP

# include <unified/application/application.hpp>

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
    UNIFIED_NAMESPACE::Application *application = UNIFIED_NAMESPACE::CreateApplication();
    application->run();
    delete application;
    return 0;
}

#endif
