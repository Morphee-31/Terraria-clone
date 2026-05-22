#include "Blocks.hpp"


// PLACE BLOCKS
void placeBlocks(sf::RenderWindow& window, std::vector<std::vector<TileName>>& map, 
	sf::Vector2<float>& playerPos, TileName& selectedBlock, Player& player) {

	sf::Vector2<float> mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window), window.getView());
	sf::Vector2<float> deltaCursorPlayer = { mousePos.x - player.getCenteredPos().x , mousePos.y - player.getCenteredPos().y };
	float dist_Player_Mouse = sqrt(pow(deltaCursorPlayer.x, 2) + pow(deltaCursorPlayer.y, 2));

	int xMouse = static_cast<int>(mousePos.x / BLOCK_SIZE);
	int yMouse = static_cast<int>(mousePos.y / BLOCK_SIZE);

	if (dist_Player_Mouse > PLAYER_REACH) return;
	if (yMouse >= MAP_HEIGHT || yMouse < 0 || xMouse >= MAP_WIDTH || xMouse < 0) return;
	if (map[yMouse][xMouse] == TileName::BedRock) return;

	if (!isSolid(map[yMouse][xMouse])) {
		map[yMouse][xMouse] = selectedBlock;
	}
}

// BREAK BLOCKS
void breakBlocks(sf::RenderWindow& window, std::vector<std::vector<TileName>>& map, sf::Vector2<float>& playerPos, Player& player)
{
	sf::Vector2<float> mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window), window.getView());
	sf::Vector2<float> deltaCursorPlayer = { mousePos.x - player.getCenteredPos().x , mousePos.y - player.getCenteredPos().y };
	float dist_Player_Mouse = sqrt(pow(deltaCursorPlayer.x, 2) + pow(deltaCursorPlayer.y, 2));

	int xMouse = static_cast<int>(mousePos.x / BLOCK_SIZE);
	int yMouse = static_cast<int>(mousePos.y / BLOCK_SIZE);

	if (dist_Player_Mouse > PLAYER_REACH) return;
	if (yMouse >= MAP_HEIGHT || yMouse < 0 || xMouse >= MAP_WIDTH || xMouse < 0) return;
	if (map[yMouse][xMouse] == TileName::BedRock) return;

	if (isBreakable(map[yMouse][xMouse])) {
		map[yMouse][xMouse] = TileName::Air;
	}
}
