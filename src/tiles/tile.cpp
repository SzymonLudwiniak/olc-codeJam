#include "../../include/tiles/tile.hpp"

const sf::Vector2f Tile::size = sf::Vector2f(32.f, 32.f);

Tile::Tile(eType tileType) {
    this->tileType = tileType;
}