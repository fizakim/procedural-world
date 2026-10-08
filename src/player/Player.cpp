#include "Player.h"
#include <GLFW/glfw3.h>

void Player::move(float right, float forward) {
    x += right;
    z -= forward;
}

void Player::applyCamera() {
    glTranslatef(-x, -y, -z);
}
