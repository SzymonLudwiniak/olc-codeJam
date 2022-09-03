#pragma once

#include <vector>

#include "../tiles/tilesIncluder.hpp"

class TileMap : public sf::Drawable, public sf::Transformable
{
    friend class TileMapManager;

    sf::Vector2i size;
    sf::Vector2i visibleMapSize;

    sf::Texture tileSetTexture;
    std::vector<Tile *> tiles;
    sf::Vertex * tilesVertices;
    sf::VertexBuffer tileBuffer;

    sf::View & view;
    float *fPerlinNoise2D;


public:

    TileMap(sf::Vector2i size, sf::View & view);

    void prepareVisibleTiles();

    sf::Vector2i getSize();
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void smartDraw(sf::RenderTarget &target);
};