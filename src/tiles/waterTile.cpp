//
// Created by szymon on 28.08.22.
//

#include "../../include/tiles/waterTile.hpp"


WaterTile::WaterTile(eType tileType) : Tile(tileType) {
    tileColor = sf::Color::Blue;
}

void WaterTile::setStatus(eStatus status) {
    switch(status) {
        case destroyed:
            tileColor = sf::Color::Red;
            break;
        default:
            break;
    }
}