#include "Player.h"
#include "../window/Window.h"
#include <cmath>

static const float DEG2RAD = 3.14159265f / 180.0f;

void Player::update(Window& window) {
    if (window.paused) return;

    look(window.mouse_dx, window.mouse_dy);

    float step = 0.25f;
    if (window.keyDown(GLFW_KEY_W)) move(0, step);
    if (window.keyDown(GLFW_KEY_S)) move(0, -step);
    if (window.keyDown(GLFW_KEY_A)) move(-step, 0);
    if (window.keyDown(GLFW_KEY_D)) move(step, 0);
}

void Player::look(float dx, float dy) {
    yaw += dx;
    pitch -= dy;
    if (pitch > 89.0f) pitch = 89.0f;
    if (pitch < -89.0f) pitch = -89.0f;
}

void Player::move(float right, float forward) {
    float yawRad = yaw * DEG2RAD;
    float pitchRad = pitch * DEG2RAD;

    x += std::sin(yawRad) * std::cos(pitchRad) * forward;
    y += std::sin(pitchRad) * forward;
    z -= std::cos(yawRad) * std::cos(pitchRad) * forward;

    x += std::cos(yawRad) * right;
    z += std::sin(yawRad) * right;
}

void Player::applyCamera() {
    glRotatef(-pitch, 1, 0, 0);
    glRotatef(yaw, 0, 1, 0);
    glTranslatef(-x, -y, -z);
}
