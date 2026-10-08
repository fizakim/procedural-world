#pragma once
#include "Object.h"

class Sphere : public Object {
public:
    float radius = 1;

    void draw() override;
};
