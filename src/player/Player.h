#pragma once

class Player {
public:
    float x = 0;
    float y = 1.5f;
    float z = 0;

    void move(float right, float forward);
    void applyCamera();
};
