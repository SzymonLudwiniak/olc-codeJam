#include "../../include/tiles/tile.hpp"
#include "../../include/defines.hpp"

const sf::Vector2f Tile::size = sf::Vector2f(TILEWIDTH, TILEHEIGHT);

Tile::Tile(eType tileType) {
    this->tileType = tileType;
    this->status = good;
}

eType Tile::getType() {
    return tileType;
}

sf::Color Tile::getColor() {
    return tileColor;
}

void Tile::setStatus(eStatus status) {
    this->status = status;
}

