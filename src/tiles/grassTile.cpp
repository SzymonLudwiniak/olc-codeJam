#include "../../include/tiles/grassTile.hpp"


GrassTile::GrassTile(eType tileType) : Tile(tileType) {

}

eType GrassTile::getType() {
    return this->tileType;
}