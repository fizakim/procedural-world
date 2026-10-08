#include <GLFW/glfw3.h>
#include <stdio.h>
#include "player/Player.h"
#include "object/Sphere.h"
#include "terrain/FlatTerrain.h"

int main() {
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 600, "Game", NULL, NULL);
    glfwMakeContextCurrent(window);
    glEnable(GL_DEPTH_TEST);

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    Player player;

    FlatTerrain terrain;

    Sphere sphere;
    sphere.y = 1.5f;
    sphere.z = -3;

    const float mouse_sensitivity = 0.1f;
    double last_mouse_x, last_mouse_y;
    glfwGetCursorPos(window, &last_mouse_x, &last_mouse_y);

    while (!glfwWindowShouldClose(window)) {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) glfwSetWindowShouldClose(window, GLFW_TRUE);

        double mouse_x, mouse_y;
        glfwGetCursorPos(window, &mouse_x, &mouse_y);
        player.look((float)(mouse_x - last_mouse_x) * mouse_sensitivity,
                    (float)(mouse_y - last_mouse_y) * mouse_sensitivity);
        last_mouse_x = mouse_x;
        last_mouse_y = mouse_y;

        float step_size = 0.5f;
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) player.move(0, 0.05f * step_size);
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) player.move(0, -0.05f * step_size);
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) player.move(-0.05f * step_size, 0);
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) player.move(0.05f * step_size, 0);
        printf("player x=%.2f y=%.2f z=%.2f\n", player.x, player.y, player.z);

        glClearColor(0.5, 0.7, 0.9, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glFrustum(-0.08, 0.08, -0.06, 0.06, 0.1, 100);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        player.applyCamera();

        terrain.draw();
        sphere.draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}
