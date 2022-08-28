//
// Created by szymon on 28.08.22.
//

#include "../../include/tiles/fieldTile.hpp"


FieldTile::FieldTile(eType tileType) : Tile(tileType) {
    tileColor = sf::Color::Yellow;
}

void FieldTile::setStatus(eStatus status) {
    switch(status) {
        case destroyed:
            tileColor = sf::Color::Black;
            break;
        default:
            break;
    }
}