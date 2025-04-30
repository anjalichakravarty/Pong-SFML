#include <iostream>
#include <SFML/Graphics.hpp>
#include "Header/Core/GameWindowManager.h"
#include "Header/Event/EventManager.h"
using namespace sf;
using namespace Event;
using namespace Core;

int main()
{
    //Create our window manager instance
    GameWindowManager gameWindowManager;
    EventManager eventManager; //Create an object of Event Manager

    //Initialize the window
    gameWindowManager.initialize();

    while (gameWindowManager.isGameRunning())
    {
        gameWindowManager.render();
    }

    while (gameWindowManager.isGameRunning())
    {
        // Check and Process Events
        eventManager.pollEvents(gameWindowManager.getGameWindow());
        gameWindowManager.render();
    }

    return 0;
}