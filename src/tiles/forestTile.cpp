//
// Created by szymon on 28.08.22.
//

#include "../../include/tiles/forestTile.hpp"


ForestTile::ForestTile(eType tileType) : Tile(tileType) {
    tileColor = sf::Color::Green;
}

void ForestTile::setStatus(eStatus status) {
    switch(status) {
        case destroyed:
            tileColor = sf::Color::Black;
            break;
        default:
            break;
    }
}