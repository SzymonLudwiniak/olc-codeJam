//
// Created by szymon on 28.08.22.
//

#include "../../include/tiles/iceTile.hpp"


IceTile::IceTile(eType tileType) : Tile(tileType) {
    tileColor = sf::Color::White;
}

void IceTile::setStatus(eStatus status) {
    switch(status) {
        case destroyed:
            tileColor = sf::Color::Black;
            break;
        default:
            break;
    }
}