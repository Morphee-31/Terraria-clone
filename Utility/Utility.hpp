#pragma once
#include <SFML/Graphics.hpp>
#include "TileName.hpp"

using Key = sf::Keyboard::Key;

struct Controls
{
	Key left	 = Key::Q;
	Key right	 = Key::D;
	Key up		 = Key::Z;
	Key down	 = Key::S;
	Key interact = Key::E;
	Key jump	 = Key::Space;
};

constexpr bool isSolid(TileName tile) {
	return  tile == TileName::Sand ||
		tile == TileName::Stone ||
		tile == TileName::Dirt ||
		tile == TileName::BedRock;
}

constexpr bool isBreakable(TileName tile) {
	return tile == TileName::Sand ||
		   tile == TileName::Dirt ||
		   tile == TileName::Ladder ||
		   tile == TileName::Stone;
}
