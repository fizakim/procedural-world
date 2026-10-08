#include "window/Window.h"
#include "player/Player.h"
#include "object/Sphere.h"
#include "terrain/FlatTerrain.h"

int main() {
    Window window(800, 600, "Game");
    Player player;
    FlatTerrain terrain;

    Sphere sphere;
    sphere.y = 1.5f;
    sphere.z = -3;

    while (window.isOpen()) {
        window.update();
        player.update(window);
        terrain.update(player.x, player.z);

        window.begin3D();
        player.applyCamera();
        terrain.draw();
        sphere.draw();
        window.endFrame();
    }
}
