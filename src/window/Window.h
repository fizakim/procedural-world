#pragma once
#include <GLFW/glfw3.h>

class Window {
public:
    bool paused = false;
    float mouse_dx = 0;
    float mouse_dy = 0;

    Window(int width, int height, const char* title);
    ~Window();

    bool isOpen();
    bool keyDown(int key);
    void update();
    void begin3D();
    void endFrame();

private:
    GLFWwindow* window;
    double last_x, last_y;
    bool esc_was_down = false;
    bool f11_was_down = false;
    int win_x = 100, win_y = 100, win_w = 800, win_h = 600;
};
