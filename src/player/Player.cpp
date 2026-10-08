#include "Player.h"
#include "../window/Window.h"
#include "../terrain/Terrain.h"
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

void Player::keepAboveTerrain(Terrain& terrain) {
    float x0 = std::floor(x);
    float z0 = std::floor(z);
    float dx = x - x0;
    float dz = z - z0;

    float a = terrain.heightAt(x0, z0);
    float b = terrain.heightAt(x0 + 1, z0);
    float c = terrain.heightAt(x0, z0 + 1);
    float d = terrain.heightAt(x0 + 1, z0 + 1);

    float top = a + (b - a) * dx;
    float bottom = c + (d - c) * dx;
    float groundY = top + (bottom - top) * dz;

    if (y < groundY + 0.5f) y = groundY + 0.5f;
}

void Player::applyCamera() {
    glRotatef(-pitch, 1, 0, 0);
    glRotatef(yaw, 0, 1, 0);
    glTranslatef(-x, -y, -z);
}
