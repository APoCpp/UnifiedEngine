#include <unified/application/application.hpp>

Unified::Application::Application(string title, VideoMode mode, u32 style) : Window(title, mode, style) { }
Unified::Application::~Application() { }

void Unified::Application::run() {
    OnCreate();
    while (OnUpdate());
    OnClose();
}

void Unified::Application::OnCreate() { }
void Unified::Application::OnClose() { }