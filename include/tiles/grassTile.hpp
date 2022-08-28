#pragma once


#include "tile.hpp"

class GrassTile : public Tile {
    
public:
    GrassTile(eType tileType = GRASS);

    virtual void setStatus(eStatus status);
};