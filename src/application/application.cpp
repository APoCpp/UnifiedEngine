#include <unified/application/application.hpp>

Unified::Application::~Application() { }

void Unified::Application::run() {
    OnCreate();
    while (OnUpdate());
    OnClose();
}

void Unified::Application::OnCreate() { }
void Unified::Application::OnClose() { }