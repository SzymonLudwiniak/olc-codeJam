//
// Created by szymon on 31.08.22.
//

#ifndef CODEJAM_GOD_HPP
#define CODEJAM_GOD_HPP

#include "../tileMap/tileMap.hpp"
//#include "../entities/unit.hpp"

#include <vector>

class God {
    TileMap * map;
    //std::vector<Unit*> * entities;

public:
    void blowWind();
};


#endif //CODEJAM_GOD_HPP
