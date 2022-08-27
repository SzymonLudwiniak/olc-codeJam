//
// Created by szymon on 27.08.22.
//

#ifndef CODEJAM_TERRAINGENERATOR_HPP
#define CODEJAM_TERRAINGENERATOR_HPP

class TerrainGenerator {
public:
    static void generateTerrain(int nWidth, int nHeight, float *fSeed, int nOctaves, float fBias, float *fOutput);
};

#endif //CODEJAM_TERRAINGENERATOR_HPP
