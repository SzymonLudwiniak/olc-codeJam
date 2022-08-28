//
// Created by szymon on 28.08.22.
//

#ifndef CODEJAM_TILEMAPMANAGER_HPP
#define CODEJAM_TILEMAPMANAGER_HPP

#include "../tileMap/tileMap.hpp"

class TileMapManager {

    TileMap* tileMap;
public:
    TileMapManager();

    void setTileMap(TileMap* tileMap);
    void breakTile(sf::Vector2i mousePosition);
};

#endif //CODEJAM_TILEMAPMANAGER_HPP
