#pragma once
#include "Sphere.h"
#include "../terrain/ChunkedTerrain.h"
#include <map>
#include <vector>

class Player;

class SphereField {
public:
    int seed = 1;
    int maxSpheres = 2;

    void update(float playerX, float playerZ, ChunkedTerrain& terrain);
    void collide(Player& player);
    void draw();

private:
    std::map<std::pair<int, int>, std::vector<Sphere>> chunks;
    std::vector<Sphere> makeChunk(int cx, int cz, ChunkedTerrain& terrain);
};
