#pragma once

class Object {
public:
    float x = 0;
    float y = 0;
    float z = 0;

    virtual void draw() = 0;
};
