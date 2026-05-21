#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

#include "Config.hpp"
#include "TileName.hpp"
#include "Utility.hpp"
#include "InitGame.hpp"

void PlayerCollisions(const std::vector<std::vector<TileName>>& map,
		const sf::Vector2<float>& playerPos, sf::Vector2<float>& velocity, float& dt, bool& onGround);

