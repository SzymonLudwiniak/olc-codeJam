#include "../../include/tileMap/tileMap.hpp"
#include "../../include/tileMap/terrainGenerator.hpp"


TileMap::TileMap(sf::Vector2i size, sf::View & view)
: tiles(size.x * size.y), tilesVertices(nullptr),
  tileBuffer(sf::Quads, sf::VertexBuffer::Dynamic), view(view){


    fPerlinNoise2D = TerrainGenerator::generateTerrain(size, 8, 0.9f);

    this->size = size;

    float height;
    for(int y = 0; y < size.y; y++) {
        for(int x = 0; x < size.x; x++) {
            height = fPerlinNoise2D[x + y*size.x];
            if(height < 0.5) {
                tiles[x + y*size.x] = new WaterTile();
                continue;
            }
            if(height < 0.625) {
                tiles[x + y*size.x] = new GrassTile();
                continue;
            }
            if(height < 0.6875) {
                tiles[x + y*size.x] = new FieldTile();
                continue;
            }
            if(height < 0.75) {
                tiles[x + y*size.x] = new SwampTile();
                continue;
            }
            if(height < 0.8125) {
                tiles[x + y*size.x] = new ForestTile();
                continue;
            }
            if(height < 0.875) {
                tiles[x + y*size.x] = new DesertTile();
                continue;
            }
            if(height < 0.9375) {
                tiles[x + y*size.x] = new JungleTile();
                continue;
            }
            if(height <= 1) {
                tiles[x + y*size.x] = new IceTile();
                continue;
            }
        }
    }

    visibleMapSize = sf::Vector2i(0,0);

    prepareVisibleTiles();
}

void TileMap::prepareVisibleTiles() {

    delete[] tilesVertices;

    sf::Vector2f tSize = Tile::size;

    int across = (int)view.getSize().x / tSize.x + 3;
    int down = (int)view.getSize().y / tSize.y + 3;

    int startX = int(view.getCenter().x/tSize.x - across/2);
    int startY = int(view.getCenter().y/tSize.y - down/2);

    if(startX < 0) startX = 0;
    if(startY < 0) startY = 0;


    sf::Color tileColor;

    int yBound = startY + down > size.y ? size.y : startY + down;
    int xBound = startX + across > size.x ? size.x : startX + across;


    visibleMapSize = sf::Vector2i(xBound-startX, yBound-startY);

    int tileNum = visibleMapSize.x * visibleMapSize.y;

    tilesVertices = new sf::Vertex[tileNum*4];
    tileBuffer.create(tileNum*4);


    int vertexIndex = 0;
    for(int y = startY; y < yBound; y++) {
        for(int x = startX; x < xBound; x++) {
            tilesVertices[vertexIndex].position = sf::Vector2f(x*tSize.x, y*tSize.y);
            tilesVertices[vertexIndex + 1].position = sf::Vector2f(x*tSize.x + tSize.x, y*tSize.y);
            tilesVertices[vertexIndex + 2].position = sf::Vector2f(x*tSize.x + tSize.x, y*tSize.y + tSize.y);
            tilesVertices[vertexIndex + 3].position = sf::Vector2f(x*tSize.x, y*tSize.y + tSize.y);

            tileColor = tiles[x+y*size.x]->getColor();

            tilesVertices[vertexIndex].color = tileColor;
            tilesVertices[vertexIndex + 1].color = tileColor;
            tilesVertices[vertexIndex + 2].color = tileColor;
            tilesVertices[vertexIndex + 3].color = tileColor;

            vertexIndex+=4;
        }
    }
    tileBuffer.update(tilesVertices);
}

void TileMap::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    target.draw(tileBuffer, states);
}

