#pragma once
#include "Terrain.h"

class FlatTerrain : public Terrain {
public:
    float height = 0;
    float size = 50;

    float heightAt(float x, float z) override;
    void draw() override;
};
