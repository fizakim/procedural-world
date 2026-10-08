#include "PerlinTerrain.h"
#include "Noise.h"

float PerlinTerrain::heightAt(float x, float z) {
    float sum = 0;
    float max = 0;
    float amp = 1;
    float freq = frequency;

    for (int i = 0; i < 5; i++) {
        sum += perlin(x * freq, z * freq, seed + i) * amp;
        max += amp;
        amp /= 2;
        freq *= 2;
    }

    return sum / max * amplitude - amplitude;
}
