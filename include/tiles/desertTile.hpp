//
// Created by szymon on 28.08.22.
//

#ifndef CODEJAM_DESERTTILE_HPP
#define CODEJAM_DESERTTILE_HPP

#include "tile.hpp"

class DesertTile : public Tile {

public:
    DesertTile(eType tileType = DESERT);

    virtual void setStatus(eStatus status);
};


#endif //CODEJAM_DESERTTILE_HPP
