#pragma once

class Player {
public:
    float x = 0;
    float y = 1.5f;
    float z = 0;

    float yaw = 0;
    float pitch = 0;

    void look(float dx, float dy);
    void move(float right, float forward);
    void applyCamera();
};
