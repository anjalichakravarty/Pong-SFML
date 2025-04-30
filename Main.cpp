#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../Header/Core/GameLoop.h"
using namespace sf;
using namespace Event;
using namespace Core;

int main()
{
    //Step 1: Create the game loop object
    GameLoop* gameLoopManager = new GameLoop();

    //Step 2: Initialize the game environment
    gameLoopManager->initialize();

    //Step 3: Run the game loop
    while (gameLoopManager->isGameRunning())
    {
        gameLoopManager->pollEvent();
        gameLoopManager->update();
        gameLoopManager->render();
    }

    return 0;
}