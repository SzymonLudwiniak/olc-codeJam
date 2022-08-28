//
// Created by szymon on 28.08.22.
//

#include "../../include/tiles/desertTile.hpp"


DesertTile::DesertTile(eType tileType) : Tile(tileType) {
    tileColor = sf::Color(255, 191, 0);
}

void DesertTile::setStatus(eStatus status) {
    switch(status) {
        case destroyed:
            tileColor = sf::Color::Black;
            break;
        default:
            break;
    }
}