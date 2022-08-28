//
// Created by szymon on 28.08.22.
//

#ifndef CODEJAM_FORESTTILE_HPP
#define CODEJAM_FORESTTILE_HPP

#include "tile.hpp"


class ForestTile  : public Tile{

public:
    ForestTile(eType tileType = FOREST);

    virtual void setStatus(eStatus status);
};


#endif //CODEJAM_FORESTTILE_HPP
