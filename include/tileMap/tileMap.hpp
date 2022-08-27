#pragma once

#include <vector>

#include "../tiles/tilesIncluder.hpp"

class TileMap : public sf::Drawable, public sf::Transformable
{
    sf::Vector2i size;

    std::vector<sf::Texture *> textures;
    std::vector<Tile *> tiles;
    sf::VertexArray tilesVertices;

    float *fNoiseSeed2D;
    float *fPerlinNoise2D;
public:

    explicit TileMap(sf::Vector2i size);

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};