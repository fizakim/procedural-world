#pragma once
#include "TerrainPattern.h"
#include <memory>
#include <utility>

class Terrain {
public:
    virtual ~Terrain() = default;
    virtual float heightAt(float x, float z) = 0;
    virtual void update(float playerX, float playerZ) {}
    virtual void draw() = 0;

    void setPattern(std::unique_ptr<TerrainPattern> p) { pattern = std::move(p); }

protected:
    std::unique_ptr<TerrainPattern> pattern = std::make_unique<SolidPattern>();
};
