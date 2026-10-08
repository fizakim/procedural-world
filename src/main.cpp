#include <GLFW/glfw3.h>
#include "player/Player.h"

int main() {
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 600, "Game", NULL, NULL);
    glfwMakeContextCurrent(window);

    Player player;

    while (!glfwWindowShouldClose(window)) {
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) player.move(0, 0.05f);
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) player.move(0, -0.05f);
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) player.move(-0.05f, 0);
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) player.move(0.05f, 0);

        glClearColor(0.5, 0.7, 0.9, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glFrustum(-0.08, 0.08, -0.06, 0.06, 0.1, 100);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        player.applyCamera();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}
