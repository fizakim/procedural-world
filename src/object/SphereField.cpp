#include "SphereField.h"
#include "../player/Player.h"
#include <cmath>
#include <cstdlib>

float randomFloat() {
    return rand() / (float)RAND_MAX;
}

std::vector<Sphere> SphereField::makeChunk(int cx, int cz, Terrain& terrain) {
    srand(cx * 7919 + cz * 104729 + seed);

    std::vector<Sphere> spheres;
    int count = rand() % (maxSpheres + 1);
    for (int i = 0; i < count; i++) {
        Sphere sphere;
        sphere.radius = 0.5f + randomFloat() * 1.5f;
        sphere.x = (cx + randomFloat()) * chunkSize;
        sphere.z = (cz + randomFloat()) * chunkSize;
        sphere.y = terrain.heightAt(sphere.x, sphere.z) + sphere.radius;
        spheres.push_back(sphere);
    }
    return spheres;
}

void SphereField::update(float playerX, float playerZ, Terrain& terrain) {
    int px = floor(playerX / chunkSize);
    int pz = floor(playerZ / chunkSize);

    for (auto it = chunks.begin(); it != chunks.end();) {
        if (abs(it->first.first - px) > viewDistance || abs(it->first.second - pz) > viewDistance) {
            it = chunks.erase(it);
        } else {
            it++;
        }
    }

    for (int x = px - viewDistance; x <= px + viewDistance; x++) {
        for (int z = pz - viewDistance; z <= pz + viewDistance; z++) {
            std::pair<int, int> key(x, z);
            if (chunks.count(key) == 0) {
                chunks[key] = makeChunk(x, z, terrain);
            }
        }
    }
}

void SphereField::collide(Player& player) {
    const float playerRadius = 0.5f;

    for (auto& entry : chunks) {
        for (Sphere& sphere : entry.second) {
            float dx = player.x - sphere.x;
            float dy = player.y - sphere.y;
            float dz = player.z - sphere.z;
            float minDist = sphere.radius + playerRadius;
            float distSq = dx * dx + dy * dy + dz * dz;

            if (distSq >= minDist * minDist) continue;

            if (distSq < 1e-6f) {
                player.y = sphere.y + minDist;
                continue;
            }

            float dist = std::sqrt(distSq);
            float push = (minDist - dist) / dist;
            player.x += dx * push;
            player.y += dy * push;
            player.z += dz * push;
        }
    }
}

void SphereField::draw() {
    for (auto& entry : chunks) {
        for (Sphere& sphere : entry.second) {
            sphere.draw();
        }
    }
}
