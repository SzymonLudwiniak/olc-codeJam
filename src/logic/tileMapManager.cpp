//
// Created by szymon on 28.08.22.
//

#include "../../include/logic/tileMapManager.hpp"


TileMapManager::TileMapManager() {}

void TileMapManager::setTileMap(TileMap *tileMap) {
    this->tileMap = tileMap;
}

void TileMapManager::breakTile(sf::Vector2i mousePosition) {


    sf::Vector2i tileCoords = sf::Vector2i(mousePosition.x/Tile::size.x,
                                           mousePosition.y/Tile::size.y);

    int across = (int)tileMap->view.getSize().x / Tile::size.x + 3;
    int down = (int)tileMap->view.getSize().y / Tile::size.y + 3;

    sf::Vector2i offset = sf::Vector2i(int(tileMap->view.getCenter().x/Tile::size.x - across/2 + 1),
                                       int(tileMap->view.getCenter().y/Tile::size.y - down/2 + 1));


    int index = (tileCoords.x + offset.x) + (tileCoords.y + offset.y) * tileMap->size.x;

    tileMap->tiles[index]->setStatus(eStatus::destroyed);
    tileMap->prepareVisibleTiles();
}