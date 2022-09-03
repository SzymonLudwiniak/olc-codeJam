#pragma once

#include "logic/tileMapManager.hpp"
#include "god/weather/wind.hpp"
#include "god/weather/lightning.hpp"

#include "../include/entities/characters/king.hpp"
#include "../include/entities/banner.hpp"
#include "../include/entities/characters/orc.hpp"

class Game {
    friend class God;
    static Game* instance;

    Unit* king;
    Unit* follower;
    Entity* banner;
    Wind* wind;
    Lightning* lightning;

    std::vector<Entity *> entities;

    sf::RenderWindow*  window;
    sf::View view;
    float zoom;

    TileMap map;
    TileMapManager mapManager;

    float fps;
    float deltaTime;

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