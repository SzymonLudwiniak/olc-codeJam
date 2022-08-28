//
// Created by szymon on 28.08.22.
//

#include "../../include/tiles/jungleTile.hpp"


JungleTile::JungleTile(eType tileType) : Tile(tileType) {
    tileColor = sf::Color(3, 75, 3);
}

void JungleTile::setStatus(eStatus status) {
    switch(status) {
        case destroyed:
            tileColor = sf::Color::Black;
            break;
        default:
            break;
    }
}