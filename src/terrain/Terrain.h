#pragma once

class Terrain {
public:
    virtual float heightAt(float x, float z) = 0;
    virtual void draw() = 0;
};
