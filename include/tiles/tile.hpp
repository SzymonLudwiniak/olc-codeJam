#pragma once


#include <SFML/Graphics.hpp>


enum eType {
    DEFAULT = 0,
    GRASS = 1,
};


class Tile {

protected:
    
    sf::Vector2f position;
    eType tileType;

public:
    static const sf::Vector2f size;
    
    explicit Tile(eType tileType = DEFAULT);

    virtual eType getType() = 0;
};