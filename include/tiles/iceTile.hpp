//
// Created by szymon on 28.08.22.
//

#ifndef CODEJAM_ICETILE_HPP
#define CODEJAM_ICETILE_HPP

#include "tile.hpp"


class IceTile  : public Tile{

public:
    IceTile(eType tileType = ICE);

    virtual void setStatus(eStatus status);
};


#endif //CODEJAM_ICETILE_HPP
