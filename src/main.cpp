#include "window/Window.h"
#include "player/Player.h"
#include "object/SphereField.h"
#include "terrain/PerlinTerrain.h"

int main() {
    Window window(800, 600, "Game");
    Player player;
    PerlinTerrain terrain;
    terrain.setPattern(std::make_unique<CheckeredPattern>());

    SphereField spheres;

    while (window.isOpen()) {
        window.update();
        player.update(window);
        terrain.update(player.x, player.z);
        spheres.update(player.x, player.z, terrain);

        window.begin3D();
        player.applyCamera();
        terrain.draw();
        spheres.draw();
        window.endFrame();
    }
}
