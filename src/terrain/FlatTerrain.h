#pragma once
#include "ChunkedTerrain.h"

class FlatTerrain : public ChunkedTerrain {
public:
    float height = 0;

    float heightAt(float x, float z) override { return height; }
};
