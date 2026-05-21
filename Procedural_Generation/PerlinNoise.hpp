#pragma once
#include "cmath"

float fade(float t);

float lerp(float a, float b, float t);

float randomGradient(int x);

float perlinNoise1D(float x);

float perlinOctaves(float x, int octaves, float persistence);