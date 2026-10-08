#pragma once
#include "Sphere.h"
#include "../terrain/Terrain.h"
#include <map>
#include <vector>

class Player;

class SphereField {
public:
    int seed = 1;
    int chunkSize = 16;
    int viewDistance = 6;
    int maxSpheres = 2;

    void update(float playerX, float playerZ, Terrain& terrain);
    void collide(Player& player);
    void draw();

private:
    std::map<std::pair<int, int>, std::vector<Sphere>> chunks;
    std::vector<Sphere> makeChunk(int cx, int cz, Terrain& terrain);
};
