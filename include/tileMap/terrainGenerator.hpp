//
// Created by szymon on 27.08.22.
//

#ifndef CODEJAM_TERRAINGENERATOR_HPP
#define CODEJAM_TERRAINGENERATOR_HPP

#include <SFML/Graphics.hpp>

class TerrainGenerator {
public:
    static float* generateTerrain(const sf::Vector2i& size, int nOctaves, float fBias);
};

#endif //CODEJAM_TERRAINGENERATOR_HPP
