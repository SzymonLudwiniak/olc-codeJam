#include "../../include/tileMap/tileMap.hpp"
#include "../../include/tileMap/terrainGenerator.hpp"

#include <iostream>


TileMap::TileMap(sf::Vector2i size, sf::View & view)
: tiles(size.x * size.y), tilesVertices(nullptr),
  tileBuffer(sf::Quads, sf::VertexBuffer::Stream), view(view){

    fPerlinNoise2D = TerrainGenerator::generateTerrain(size, 8, 0.9f);

    this->size = size;

    float height;
    for(int y = 0; y < size.y; y++) {
        for(int x = 0; x < size.x; x++) {
            height = fPerlinNoise2D[x + y*size.x];
            if(height < 0.25) {
                tiles[x + y*size.x] = new WaterTile();
                continue;
            }
            if(height < 0.325) {
                tiles[x + y*size.x] = new DesertTile();
                continue;
            }
            if(height < 0.5) {
                tiles[x + y*size.x] = new GrassTile();
                continue;
            }
            if(height < 0.625) {
                tiles[x + y*size.x] = new SwampTile();
                continue;
            }
            if(height < 0.750) {
                tiles[x + y*size.x] = new ForestTile();
                continue;
            }
            if(height < 0.825) {
                tiles[x + y*size.x] = new FieldTile();
                continue;
            }
            if(height < 0.9) {
                tiles[x + y*size.x] = new JungleTile();
                continue;
            }
            if(height <= 1) {
                tiles[x + y*size.x] = new IceTile();
                continue;
            }
        }
    }

    int across = (int)view.getSize().x / Tile::size.x + 3;
    int down = (int)view.getSize().y / Tile::size.y + 3;


    visibleMapSize = sf::Vector2i(across*2, down*2);


    tilesVertices = new sf::Vertex[visibleMapSize.x * visibleMapSize.y];
    tileBuffer.create(visibleMapSize.x * visibleMapSize.y);

    if(!tileSetTexture.loadFromFile("./textures/tileSet2.png")) {
        std::cout << "whoops!\n";
    }

    visibleMapSize = sf::Vector2i(0,0);

    prepareVisibleTiles();
}

void TileMap::prepareVisibleTiles() {

    sf::Vector2f tSize = Tile::size;

    int across = (int)view.getSize().x / tSize.x + 3;
    int down = (int)view.getSize().y / tSize.y + 3;

    int startX = int(view.getCenter().x/tSize.x - across/2 + 1);
    int startY = int(view.getCenter().y/tSize.y - down/2 + 1);

    int yBound = startY + down;
    int xBound = startX + across;


    auto setTexture = [&] (int vertexIndex, eType tileType, bool downEdge = false) -> void {
        if(!downEdge) {
            tilesVertices[vertexIndex].texCoords = sf::Vector2f(tileType * tSize.x, 0.f);
            tilesVertices[vertexIndex+1].texCoords = sf::Vector2f(tileType * tSize.x + tSize.x, 0.f);
            tilesVertices[vertexIndex+2].texCoords = sf::Vector2f(tileType * tSize.x + tSize.x, tSize.y);
            tilesVertices[vertexIndex+3].texCoords = sf::Vector2f(tileType * tSize.x, tSize.y);
            return;
        }
        tilesVertices[vertexIndex].texCoords = sf::Vector2f(tileType * tSize.x, tSize.y);
        tilesVertices[vertexIndex+1].texCoords = sf::Vector2f(tileType * tSize.x + tSize.x, tSize.y);
        tilesVertices[vertexIndex+2].texCoords = sf::Vector2f(tileType * tSize.x + tSize.x, 2*tSize.y);
        tilesVertices[vertexIndex+3].texCoords = sf::Vector2f(tileType * tSize.x, 2*tSize.y);
    };


    int vertexIndex = 0;
    for(int y = startY; y < yBound; y++) {
        for(int x = startX; x < xBound; x++) {
            tilesVertices[vertexIndex].position = sf::Vector2f(x*tSize.x, y*tSize.y);
            tilesVertices[vertexIndex + 1].position = sf::Vector2f(x*tSize.x + tSize.x, y*tSize.y);
            tilesVertices[vertexIndex + 2].position = sf::Vector2f(x*tSize.x + tSize.x, y*tSize.y + tSize.y);
            tilesVertices[vertexIndex + 3].position = sf::Vector2f(x*tSize.x, y*tSize.y + tSize.y);


            eType tileType = tiles[x+y*size.x]->getType();

            (y < yBound-1 && tileType != tiles[x+(y+1)*size.x]->getType())
            ? setTexture(vertexIndex, tileType, true) : setTexture(vertexIndex, tileType);


            vertexIndex+=4;
        }
    }
    tileBuffer.update(tilesVertices);
}

sf::Vector2i TileMap::getSize() {
    return size;
}

void TileMap::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    states.texture = &tileSetTexture;
    target.draw(tileBuffer, states);
}

void TileMap::smartDraw(sf::RenderTarget &target) {
    //states.transform *= getTransform();
    prepareVisibleTiles();
    target.draw(tileBuffer);
}