#include "Window.h"

Window::Window(int width, int height, const char* title) {
    glfwInit();
    window = glfwCreateWindow(width, height, title, NULL, NULL);
    glfwMakeContextCurrent(window);
    glEnable(GL_DEPTH_TEST);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwGetCursorPos(window, &last_x, &last_y);
}

Window::~Window() {
    glfwTerminate();
}

bool Window::isOpen() {
    return !glfwWindowShouldClose(window);
}

bool Window::keyDown(int key) {
    return glfwGetKey(window, key) == GLFW_PRESS;
}

void Window::update() {
    bool f11_down = keyDown(GLFW_KEY_F11);
    if (f11_down && !f11_was_down) {
        if (glfwGetWindowMonitor(window)) {
            glfwSetWindowMonitor(window, NULL, win_x, win_y, win_w, win_h, 0);
        } else {
            glfwGetWindowPos(window, &win_x, &win_y);
            glfwGetWindowSize(window, &win_w, &win_h);
            GLFWmonitor* monitor = glfwGetPrimaryMonitor();
            const GLFWvidmode* mode = glfwGetVideoMode(monitor);
            glfwSetWindowMonitor(window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
        }
        glfwGetCursorPos(window, &last_x, &last_y);
    }
    f11_was_down = f11_down;

    bool esc_down = keyDown(GLFW_KEY_ESCAPE);
    if (esc_down && !esc_was_down) {
        paused = !paused;
        glfwSetInputMode(window, GLFW_CURSOR, paused ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_DISABLED);
        glfwGetCursorPos(window, &last_x, &last_y);
    }
    esc_was_down = esc_down;

    double x, y;
    glfwGetCursorPos(window, &x, &y);
    mouse_dx = (float)(x - last_x) * 0.1f;
    mouse_dy = (float)(y - last_y) * 0.1f;
    last_x = x;
    last_y = y;
}

void Window::begin3D() {
    int w, h;
    glfwGetFramebufferSize(window, &w, &h);
    if (h == 0) h = 1;
    glViewport(0, 0, w, h);

    glClearColor(0.5, 0.7, 0.9, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    double half_h = 0.06;
    double half_w = half_h * w / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-half_w, half_w, -half_h, half_h, 0.1, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Window::endFrame() {
    glfwSwapBuffers(window);
    glfwPollEvents();
}
