#include "Rendering_Engine.hpp"

void rendering (sf::RenderWindow &window, Player &player, sf::RectangleShape &tileShape,
			std::vector<std::vector<TileName>>& map) {

	// CLEARING
	window.clear({200,120,50});

	// DRAWING
	for (int y = 0; y < MAP_HEIGHT; y++) {
		for (int x = 0; x < MAP_WIDTH; x++) {
			switch (map[y][x]) {
			case TileName::Sand:	tileShape.setFillColor(sf::Color::Yellow);		break;
			case TileName::Water:	tileShape.setFillColor(sf::Color::Blue);		break;
			case TileName::Dirt:	tileShape.setFillColor(sf::Color::Green);		break;
			case TileName::Ladder:	tileShape.setFillColor(sf::Color::White);		break;
			case TileName::Stone:	tileShape.setFillColor(sf::Color::Black);		break;
			case TileName::Lava:	tileShape.setFillColor(sf::Color::Red);			break;
			case TileName::Air:		tileShape.setFillColor(sf::Color::Cyan);		break;
			default:				tileShape.setFillColor(sf::Color::White);		break;
			}
			tileShape.setPosition({ x * BLOCK_SIZE, y * BLOCK_SIZE });
			window.draw(tileShape);
		}
	}

	player.draw(window);

	window.display();
}
