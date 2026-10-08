#include "FlatTerrain.h"
#include <GLFW/glfw3.h>

float FlatTerrain::heightAt(float x, float z) {
    return height;
}

void FlatTerrain::draw() {
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.6f, 0.3f);
    glVertex3f(-size, height, -size);
    glVertex3f(-size, height, size);
    glVertex3f(size, height, size);
    glVertex3f(size, height, -size);
    glEnd();
}
