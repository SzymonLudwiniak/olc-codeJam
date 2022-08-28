//
// Created by szymon on 28.08.22.
//

#ifndef CODEJAM_SWAMPTILE_HPP
#define CODEJAM_SWAMPTILE_HPP

#include "tile.hpp"


class SwampTile  : public Tile{

public:
    SwampTile(eType tileType = SWAMP);

    virtual void setStatus(eStatus status);
};


#endif //CODEJAM_SWAMPTILE_HPP
