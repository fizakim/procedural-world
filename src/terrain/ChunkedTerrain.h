#pragma once
#include "Terrain.h"
#include <map>
#include <vector>

struct Chunk {
    int x, z;
    std::vector<float> heights;
};

class ChunkedTerrain : public Terrain {
public:
    int chunkSize = 16;
    int viewDistance = 10;

    void update(float playerX, float playerZ) override;
    void draw() override;

private:
    std::map<std::pair<int, int>, Chunk> chunks;
    Chunk makeChunk(int cx, int cz);
};
