#include "engine.h"
#include "game.h"
#include <iostream>

int main()
{
    if (!RC7::Engine::Initialize()) {
        std::cerr << "Engine init failed.\n";
        return -1;
    }

    RC7::Game game;
    if (!game.Init()) {
        std::cerr << "Game init failed.\n";
        RC7::Engine::Shutdown();
        return -1;
    }

    while (RC7::Engine::IsRunning()) {
        RC7::Engine::PollEvents();
        game.Update();
        RC7::Engine::Render();
    }

    game.Shutdown();
    RC7::Engine::Shutdown();
    return 0;
}
