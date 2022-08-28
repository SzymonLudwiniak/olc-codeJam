//
// Created by szymon on 28.08.22.
//

#ifndef CODEJAM_WATERTILE_HPP
#define CODEJAM_WATERTILE_HPP

#include "tile.hpp"

class WaterTile : public Tile{

public:
    WaterTile(eType tileType = WATER);

    virtual void setStatus(eStatus status);
};


#endif //CODEJAM_WATERTILE_HPP
