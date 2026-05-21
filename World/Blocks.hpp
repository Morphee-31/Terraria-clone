#pragma once

#include <array>

#pragma once

#include "SFML/Graphics.hpp"

#include "Config.hpp"
#include "Utility.hpp"
#include "TileName.hpp"
#include "Player.hpp"


struct Block
{
	sf::Vector3<int> color;
	sf::Vector2<float> position;
	TileName name;
	float hardness;
};

void placeBlocks(sf::RenderWindow& window, std::vector<std::vector<TileName>>& map, sf::Vector2<float>& playerPos,
	TileName& selectedBlock, Player& player);

void breakBlocks(sf::RenderWindow& window, std::vector<std::vector<TileName>>& map,
	sf::Vector2<float>& playerPos, Player& player);
