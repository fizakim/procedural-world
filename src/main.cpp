#include <GLFW/glfw3.h>
#include <stdio.h>
#include "player/Player.h"
#include "object/Sphere.h"

int main() {
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 600, "Game", NULL, NULL);
    glfwMakeContextCurrent(window);
    glEnable(GL_DEPTH_TEST);

    Player player;

    Sphere sphere;
    sphere.y = 1.5f;
    sphere.z = -3;

    while (!glfwWindowShouldClose(window)) {
        float step_size = 0.5f;
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) player.move(0, 0.05f * step_size);
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) player.move(0, -0.05f * step_size);
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) player.move(-0.05f * step_size, 0);
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) player.move(0.05f * step_size, 0);
        printf("player x=%.2f z=%.2f\n", player.x, player.z); 

        glClearColor(0.5, 0.7, 0.9, 1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glFrustum(-0.08, 0.08, -0.06, 0.06, 0.1, 100);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        player.applyCamera();

        sphere.draw();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}
