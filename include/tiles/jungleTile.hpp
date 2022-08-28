//
// Created by szymon on 28.08.22.
//

#ifndef CODEJAM_JUNGLETILE_HPP
#define CODEJAM_JUNGLETILE_HPP

#include "tile.hpp"


class JungleTile  : public Tile{

public:
    JungleTile(eType tileType = JUNGLE);

    virtual void setStatus(eStatus status);
};


#endif //CODEJAM_JUNGLETILE_HPP
