#include "../../include/tiles/grassTile.hpp"


GrassTile::GrassTile(eType tileType) : Tile(tileType) {
    tileColor = sf::Color(124,252,0);
}

void GrassTile::setStatus(eStatus status) {
    switch(status) {
        case destroyed:
            tileColor = sf::Color::Black;
            break;
        default:
            break;
    }
}