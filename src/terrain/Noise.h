#pragma once
#include <cmath>

inline float lerp(float a, float b, float t) { return a + (b - a) * t; }

inline float fade(float t) { return t * t * t * (t * (t * 6 - 15) + 10); }

inline float grad(int x, int z, int seed, float dx, float dz) {
    unsigned int h = x * 374761393u + z * 668265263u + seed * 2246822519u;
    h = (h ^ (h >> 13)) * 1274126177u;
    h = h ^ (h >> 16);

    float angle = (h % 360) * 3.14159f / 180;
    return cos(angle) * dx + sin(angle) * dz;
}

inline float perlin(float x, float z, int seed) {
    int x0 = floor(x);
    int z0 = floor(z);
    float fx = x - x0;
    float fz = z - z0;

    float a = lerp(grad(x0, z0, seed, fx, fz), grad(x0 + 1, z0, seed, fx - 1, fz), fade(fx));
    float b = lerp(grad(x0, z0 + 1, seed, fx, fz - 1), grad(x0 + 1, z0 + 1, seed, fx - 1, fz - 1), fade(fx));

    return lerp(a, b, fade(fz)) * 0.7071f + 0.5f;
}
