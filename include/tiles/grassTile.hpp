#pragma once


#include "tile.hpp"

class GrassTile : public Tile {
    
public:
    virtual eType getType();
    GrassTile(eType tileType = GRASS);
};