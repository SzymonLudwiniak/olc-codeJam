#pragma once


#include <SFML/Graphics.hpp>


enum eType {
    DEFAULT = 0,
    WATER = 1,
    GRASS = 2,
    FIELD = 3,
    SWAMP = 4,
    FOREST = 5,
    DESERT = 6,
    JUNGLE = 7,
    ICE = 6,
};

enum eStatus {
    good = 0,
    destroyed = 1,
};


class Tile {

protected:

    sf::Color tileColor;

    sf::Vector2f position;
    eType tileType;

    eStatus status;

public:
    static const sf::Vector2f size;

    explicit Tile(eType tileType = DEFAULT);

    eType getType();
    eStatus getStatus();
    sf::Color getColor();

    virtual void setStatus(eStatus status);
};