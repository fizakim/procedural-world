#include "ChunkedTerrain.h"
#include <GLFW/glfw3.h>
#include <cmath>
#include <cstdlib>

Chunk ChunkedTerrain::makeChunk(int cx, int cz) {
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

void ChunkedTerrain::update(float playerX, float playerZ) {
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
            std::pair<int, int> key(x, z);
            if (chunks.count(key) == 0) {
                chunks[key] = makeChunk(x, z);
            }
        }
    }
}

void ChunkedTerrain::draw() {
    int w = chunkSize + 1;

    glBegin(GL_QUADS);
    for (auto& entry : chunks) {
        Chunk& chunk = entry.second;
        for (int j = 0; j < chunkSize; j++) {
            for (int i = 0; i < chunkSize; i++) {
                float x = chunk.x * chunkSize + i;
                float z = chunk.z * chunkSize + j;

                float h1 = chunk.heights[j * w + i];
                float h2 = chunk.heights[(j + 1) * w + i];
                float h3 = chunk.heights[(j + 1) * w + i + 1];
                float h4 = chunk.heights[j * w + i + 1];

                Color c = pattern->colorAt(x + 0.5f, z + 0.5f);
                glColor3f(c.r, c.g, c.b);
                glVertex3f(x, h1, z);
                glVertex3f(x, h2, z + 1);
                glVertex3f(x + 1, h3, z + 1);
                glVertex3f(x + 1, h4, z);
            }
        }
    }
    glEnd();
}
