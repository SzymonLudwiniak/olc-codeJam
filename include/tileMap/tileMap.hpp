#pragma once

#include <vector>

#include "../tiles/tilesIncluder.hpp"

class TileMap : public sf::Drawable, public sf::Transformable
{
    friend class TileMapManager;

    sf::Vector2i size;
    sf::Vector2i visibleMapSize;

    std::vector<sf::Texture *> textures;
    std::vector<Tile *> tiles;
    sf::Vertex * tilesVertices;
    sf::VertexBuffer tileBuffer;

    sf::View & view;
    float *fPerlinNoise2D;


public:

    TileMap(sf::Vector2i size, sf::View & view);

    void prepareVisibleTiles();
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};