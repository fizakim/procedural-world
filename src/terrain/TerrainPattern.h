#pragma once
#include <cmath>

struct Color {
    float r, g, b;
};

class TerrainPattern {
public:
    virtual ~TerrainPattern() = default;
    virtual Color colorAt(float x, float z) const = 0;
};

class SolidPattern : public TerrainPattern {
public:
    Color color;

    SolidPattern(Color color = {0.3f, 0.6f, 0.3f}) : color(color) {}

    Color colorAt(float x, float z) const override { return color; }
};

class CheckeredPattern : public TerrainPattern {
public:
    Color a;
    Color b;
    float tileSize;

    CheckeredPattern(Color a = {0.3f, 0.6f, 0.3f}, Color b = {0.2f, 0.45f, 0.2f}, float tileSize = 1.0f)
        : a(a), b(b), tileSize(tileSize) {}

    Color colorAt(float x, float z) const override {
        int tx = (int)std::floor(x / tileSize);
        int tz = (int)std::floor(z / tileSize);
        return ((tx + tz) & 1) == 0 ? a : b;
    }
};
