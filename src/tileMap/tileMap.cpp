#include "../../include/tileMap/tileMap.hpp"
#include "../../include/tileMap/terrainGenerator.hpp"


TileMap::TileMap(sf::Vector2i size)
: tiles(size.x * size.y), tilesVertices(sf::Quads, size.x * size.y*4){


    fNoiseSeed2D = new float[size.x * size.y];
    fPerlinNoise2D = new float[size.x * size.y];

    for (int i = 0; i < size.x * size.y; i++)
        fNoiseSeed2D[i] = (float)rand() / (float)RAND_MAX;

    TerrainGenerator::generateTerrain(size.x, size.y, fNoiseSeed2D, 8, 1.2f, fPerlinNoise2D);

    textures.push_back(new sf::Texture);
    this->size = size;

    for(auto & tile : tiles) {
        tile = new GrassTile();
    }

    sf::Vector2f tSize = Tile::size;

    sf::Color tileColor;

    for(int y = 0; y < size.y*4; y += 4) {
        for(int x = 0; x < size.x*4; x += 4) {
            tilesVertices[x + y * size.x].position = sf::Vector2f(x*tSize.x/4, y*tSize.y/4);
            tilesVertices[x + y * size.x + 1].position = sf::Vector2f(x*tSize.x/4 + tSize.x, y*tSize.y/4);
            tilesVertices[x + y * size.x + 2].position = sf::Vector2f(x*tSize.x/4 + tSize.x, y*tSize.y/4 + tSize.y);
            tilesVertices[x + y * size.x + 3].position = sf::Vector2f(x*tSize.x/4, y*tSize.y/4 + tSize.y);


            if(fPerlinNoise2D[x/4 + y/4*size.y] < 0.5) {
                tileColor = sf::Color::Blue;
            }
            else if(fPerlinNoise2D[x/4 + y/4*size.y] < 0.6){
                tileColor = sf::Color::Yellow;
            }
            else if(fPerlinNoise2D[x/4 + y/4*size.y] < 0.7){
                tileColor = sf::Color::Green;
            }
            else if(fPerlinNoise2D[x/4 + y/4*size.y] <= 1){
                tileColor = sf::Color::White;
            }

            tilesVertices[x + y * size.x].color = tileColor;
            tilesVertices[x + y * size.x + 1].color = tileColor;
            tilesVertices[x + y * size.x + 2].color = tileColor;
            tilesVertices[x + y * size.x + 3].color = tileColor;

        }
    }
}

void TileMap::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.texture = textures[0];
    states.transform *= getTransform();
    target.draw(tilesVertices, states);
}

