#pragma once

#include <array>
#include <algorithm>
#include <vector>
#include <optional>

#include "SFML/Graphics.hpp"

#include "Config.hpp"
#include "TileName.hpp"
#include "MapGen.hpp"

#include "Utility.hpp"
#include "Player.hpp"
#include "PerlinNoise.hpp"
#include "Blocks.hpp"
#include "Collisions.hpp"
#include "Rendering_Engine.hpp"


void gameLoop (sf::RenderWindow& window);
void handleTerrainStrains(std::vector<std::vector<TileName>>& map, int& playerX, int& playerY, bool& climbing, float& terrainStrain);
void resetPlayerPos(sf::Vector2<float>& playerPos);
