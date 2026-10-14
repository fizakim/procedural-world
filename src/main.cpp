#include "window/Window.h"
#include "player/Player.h"
#include "object/SphereField.h"
#include "terrain/PerlinTerrain.h"

int main() {
    Window window(800, 600, "Game");
    Player player;
    PerlinTerrain terrain;
    terrain.setPattern(std::make_unique<CheckeredPattern>());
    terrain.seed = 1;
    terrain.chunkSize = 16;
    terrain.viewDistance = 2;
    terrain.showChunkBorders = true;

    SphereField spheres;
    spheres.seed = 1;

    while (window.isOpen()) {
        window.update();
        player.update(window);
        terrain.update(player.x, player.z);
        spheres.update(player.x, player.z, terrain);
        spheres.collide(player);
        player.keepAboveTerrain(terrain);

        window.begin3D();
        player.applyCamera();
        terrain.draw();
        spheres.draw();
        window.endFrame();
    }
}
