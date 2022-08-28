#pragma once

#include "logic/tileMapManager.hpp"

class Game {
    static Game* instance;


    sf::RenderWindow window;
    sf::View view;
    float zoom;

    TileMap map;
    TileMapManager mapManager;

    float fps;

    sf::Clock clock;
    sf::Time previousTime;
    sf::Time currentTime;

    sf::Text frames;
    sf::Font font;

    bool mouseButtonHold;

    Game();

    void handleEvents();
    void prepareFpsCounter();
    void updateFps();

public:
    static Game* getInstance();

    void run();
};