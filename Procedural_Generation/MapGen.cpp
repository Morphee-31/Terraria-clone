#include "MapGen.hpp"

void InitMap(std::vector<std::vector<TileName>>& map) {

	for (int x = 0; x < MAP_WIDTH; x++) {
		float noise = perlinOctaves(x, 5, 0.5f);

		int height = (noise + 1) * 0.5f * MAP_HEIGHT;

		for (int y = 0; y < MAP_HEIGHT; y++) {
			if (y > height) {
				map[y][x] = TileName::Dirt;
			}
			else {
				map[y][x] = TileName::Air;
			}
		}
	}
}
