//
// Created by szymon on 28.08.22.
//

#ifndef CODEJAM_FIELDTILE_HPP
#define CODEJAM_FIELDTILE_HPP

#include "tile.hpp"


class FieldTile  : public Tile{

public:
    FieldTile(eType tileType = FIELD);

    virtual void setStatus(eStatus status);
};


#endif //CODEJAM_FIELDTILE_HPP
