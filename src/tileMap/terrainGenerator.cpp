#include "../../include/tileMap/terrainGenerator.hpp"

// love javid <3

float* TerrainGenerator::generateTerrain(const sf::Vector2i& size, int nOctaves, float fBias) {

    float *fSeed = new float[size.x * size.y];
    float *fOutput = new float[size.x * size.y];

    for (int i = 0; i < size.x * size.y; i++)
        fSeed[i] = (float)rand() / (float)RAND_MAX;

    for (int x = 0; x < size.x; x++)
        for (int y = 0; y < size.y; y++)
        {
            float fNoise = 0.0f;
            float fScaleAcc = 0.0f;
            float fScale = 1.0f;

            for (int o = 0; o < nOctaves; o++)
            {
                int nPitch = size.x >> o;
                int nSampleX1 = (x / nPitch) * nPitch;
                int nSampleY1 = (y / nPitch) * nPitch;

                int nSampleX2 = (nSampleX1 + nPitch) % size.x;
                int nSampleY2 = (nSampleY1 + nPitch) % size.x;

                float fBlendX = (float)(x - nSampleX1) / (float)nPitch;
                float fBlendY = (float)(y - nSampleY1) / (float)nPitch;

                float fSampleT = (1.0f - fBlendX) * fSeed[nSampleY1 * size.x + nSampleX1] + fBlendX * fSeed[nSampleY1 * size.x + nSampleX2];
                float fSampleB = (1.0f - fBlendX) * fSeed[nSampleY2 * size.x + nSampleX1] + fBlendX * fSeed[nSampleY2 * size.x + nSampleX2];

                fScaleAcc += fScale;
                fNoise += (fBlendY * (fSampleB - fSampleT) + fSampleT) * fScale;
                fScale = fScale / fBias;
            }

            // Scale to seed range
            fOutput[y * size.x + x] = fNoise / fScaleAcc;
        }

    delete[] fSeed;
    return fOutput;
}
