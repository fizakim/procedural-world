#include "Sphere.h"
#include <GLFW/glfw3.h>
#include <math.h>

void Sphere::draw() {
    const int stacks = 16;
    const int slices = 32;
    const float pi = 3.14159265f;

    glPushMatrix();
    glTranslatef(x, y, z);

    for (int i = 0; i < stacks; i++) {
        float lat0 = pi * i / stacks - pi / 2;
        float lat1 = pi * (i + 1) / stacks - pi / 2;

        glBegin(GL_QUAD_STRIP);
        for (int j = 0; j <= slices; j++) {
            float lon = 2 * pi * j / slices;

            float x0 = cos(lat0) * cos(lon), y0 = sin(lat0), z0 = cos(lat0) * sin(lon);
            float x1 = cos(lat1) * cos(lon), y1 = sin(lat1), z1 = cos(lat1) * sin(lon);

            glColor3f(x0 * 0.5f + 0.5f, y0 * 0.5f + 0.5f, z0 * 0.5f + 0.5f);
            glVertex3f(x0 * radius, y0 * radius, z0 * radius);
            glColor3f(x1 * 0.5f + 0.5f, y1 * 0.5f + 0.5f, z1 * 0.5f + 0.5f);
            glVertex3f(x1 * radius, y1 * radius, z1 * radius);
        }
        glEnd();
    }

    glPopMatrix();
}
