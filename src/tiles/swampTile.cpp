//
// Created by szymon on 28.08.22.
//

#include "../../include/tiles/swampTile.hpp"


SwampTile::SwampTile(eType tileType) : Tile(tileType) {
    tileColor = sf::Color(255,248,220);
}

void SwampTile::setStatus(eStatus status) {
    switch(status) {
        case destroyed:
            tileColor = sf::Color::Black;
            break;
        default:
            break;
    }
}