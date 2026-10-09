# Game

A 3D game in C++ and OpenGL set in an infinite, procedurally generated world. Prototype for a larger upcoming VR project.

![image1](https://markdownviewer.pages.dev/api/image/0Dg1bGV-seXNeByXWxNmZQxQ)

Terrain height comes from 2D Perlin noise. The world is split into chunks that load ahead of the camera and unload behind it. Spheres are seeded by chunk coordinates, so a chunk regenerates identically when revisited. The camera flies freely, collides with spheres, and stays above the terrain.

## Controls

`W` `A` `S` `D` move · Mouse look · `Esc` pause / release mouse

## Build

Requires CMake, GLFW and OpenGL.

```
cmake -S . -B build     # configure
cmake --build build     # compile
./build/game            # run 
```
