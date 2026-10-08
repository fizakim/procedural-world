#pragma once

class Terrain {
public:
    virtual ~Terrain() = default;
    virtual float heightAt(float x, float z) = 0;
    virtual void update(float playerX, float playerZ) {}
    virtual void draw() = 0;
};
