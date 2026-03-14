#include "engine.h"
#include <chrono>
#include <iostream>

namespace RC7 {

bool Engine::Initialize() {
    std::cout << "[Engine] Initialising…\n";
    // TODO: add real initialization (window, graphics, hooks)
    return true;
}

void Engine::Shutdown() {
    std::cout << "[Engine] Shutting down.\n";
    // TODO: clean up resources
}

bool Engine::IsRunning() {
    static auto start = std::chrono::steady_clock::now();
    // Run for ~5 seconds as a demo placeholder
    return std::chrono::duration_cast<std::chrono::seconds>(
               std::chrono::steady_clock::now() - start).count() < 5;
}

void Engine::PollEvents() {
    // TODO: process Win32 messages or ImGui input
}

void Engine::Render() {
    // TODO: present frame (DirectX/OpenGL/Vulkan)
}

} // namespace RC7
