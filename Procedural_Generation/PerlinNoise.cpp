#include "PerlinNoise.hpp"

// ==================
// PROCEDURAL GENERATION ALGORITHM
// ==================


// interpolation douce
float fade(float t) {
	return t * t * t * (t * (t * 6 - 15) + 10);
}


// interpolation linéaire
float lerp(float a, float b, float t) {
	return a + t * (b - a);
}


// pseudo-random déterministe
float randomGradient(int x) {
	x = (x << 13) ^ x;
	return 1.0f - ((x * (x * x * 15731 + 789221) + 1376312589) & 0x7fffffff) / 1073741824.0f;
}


float perlinNoise1D(float x) {
	int x0 = (int)floor(x);
	int x1 = x0 + 1;

	float sx = x - (float)x0;

	float n0 = randomGradient(x0) * (x - x0);
	float n1 = randomGradient(x1) * (x - x1);

	float u = fade(sx);

	return lerp(n0, n1, u);
}


float perlinOctaves(float x, int octaves, float persistence) {
	float total = 0;
	float frequency = 0.05f;
	float amplitude = 1;
	float maxValue = 0;

	for (int i = 0; i < octaves; i++) {
		total += perlinNoise1D(x * frequency) * amplitude;

		maxValue += amplitude;

		amplitude *= persistence;
		frequency *= 2;
	}

	return total / maxValue;
}
