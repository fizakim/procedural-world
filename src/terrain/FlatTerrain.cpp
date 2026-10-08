#include "FlatTerrain.h"
#include <GLFW/glfw3.h>
#include <cmath>
#include <cstdlib>

float FlatTerrain::heightAt(float x, float z) {
    return height;
}

Chunk FlatTerrain::makeChunk(int cx, int cz) {
    Chunk chunk;
    chunk.x = cx;
    chunk.z = cz;
    for (int j = 0; j <= chunkSize; j++) {
        for (int i = 0; i <= chunkSize; i++) {
            chunk.heights.push_back(heightAt(cx * chunkSize + i, cz * chunkSize + j));
        }
    }
    return chunk;
}

void FlatTerrain::update(float playerX, float playerZ) {
    int px = floor(playerX / chunkSize);
    int pz = floor(playerZ / chunkSize);

    for (auto it = chunks.begin(); it != chunks.end();) {
        if (abs(it->second.x - px) > viewDistance || abs(it->second.z - pz) > viewDistance) {
            it = chunks.erase(it);
        } else {
            it++;
        }
    }

    for (int x = px - viewDistance; x <= px + viewDistance; x++) {
        for (int z = pz - viewDistance; z <= pz + viewDistance; z++) {
            if (chunks.find({x, z}) == chunks.end()) {
                chunks[{x, z}] = makeChunk(x, z);
            }
        }
    }
}

void FlatTerrain::draw() {
    int w = chunkSize + 1;

    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.6f, 0.3f);
    for (auto& [pos, chunk] : chunks) {
        for (int j = 0; j < chunkSize; j++) {
            for (int i = 0; i < chunkSize; i++) {
                float x = chunk.x * chunkSize + i;
                float z = chunk.z * chunkSize + j;
                glVertex3f(x, chunk.heights[j * w + i], z);
                glVertex3f(x, chunk.heights[(j + 1) * w + i], z + 1);
                glVertex3f(x + 1, chunk.heights[(j + 1) * w + i + 1], z + 1);
                glVertex3f(x + 1, chunk.heights[j * w + i + 1], z);
            }
        }
    }
    glEnd();
}
