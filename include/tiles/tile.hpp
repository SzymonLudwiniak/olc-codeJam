#pragma once


#include <SFML/Graphics.hpp>


enum eType {
    WATER = 0,
    GRASS = 1,
    FIELD = 2,
    SWAMP = 3,
    FOREST = 4,
    DESERT = 5,
    JUNGLE = 6,
    ICE = 7,
    DEFAULT = 9,
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