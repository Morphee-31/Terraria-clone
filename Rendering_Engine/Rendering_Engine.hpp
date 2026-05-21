#pragma once 

#include <vector>

#include "SFML/Graphics.hpp"
#include "TileName.hpp"
#include "Player.hpp"
#include "Config.hpp"

void rendering(sf::RenderWindow& window, Player& player, sf::RectangleShape& tileShape,
			std::vector<std::vector<TileName>>& map);