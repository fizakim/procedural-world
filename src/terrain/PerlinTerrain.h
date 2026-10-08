#pragma once
#include "ChunkedTerrain.h"

class PerlinTerrain : public ChunkedTerrain {
public:
    int seed = 1;
    float amplitude = 12.0f;
    float frequency = 0.02f;

    float heightAt(float x, float z) override;
};
