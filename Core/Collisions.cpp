#include "Collisions.hpp"

void PlayerCollisions (const std::vector<std::vector<TileName>>& map,
	sf::Vector2<float>& playerPos, sf::Vector2<float>& velocity,
	float& dt, bool& onGround) 
{
	sf::Vector2<float> oldPos = playerPos;
	sf::Vector2<float> newPos = playerPos;

	onGround = false;


	// =====================
	// ===== X ============
	// =====================
	newPos.x += velocity.x * dt;

	int left   = static_cast<int>((newPos.x - PLAYER_WIDTH) / BLOCK_SIZE);
	int right  = static_cast<int>((newPos.x + PLAYER_WIDTH) / BLOCK_SIZE);
	int top	   = static_cast<int>((oldPos.y - PLAYER_HEIGHT) / BLOCK_SIZE);
	int bottom = static_cast<int>((oldPos.y + PLAYER_HEIGHT) / BLOCK_SIZE);

	if ( velocity.x > 0 ) {
		if (right < MAP_WIDTH) {
			for (int y = top; y <= bottom; y++) { // goes from top, middle, bottom and should stop at bottom
				if (isSolid(map[y][right])) {
					newPos.x = right * BLOCK_SIZE - PLAYER_WIDTH;
					velocity.x = 0;
				}
			}
		}
		else {
			resetPlayerPos(playerPos);
		}
	}
	else if ( velocity.x < 0 ) {
		if (left >= 0) {
			for (int y = top; y <= bottom; y++) {
				if (isSolid(map[y][left])) {
					newPos.x = left * BLOCK_SIZE + PLAYER_WIDTH;
					velocity.x = 0;
				}
			}
		}
		else {
			resetPlayerPos(playerPos);
		}
	}

	// =====================
	// ===== Y ============
	// =====================
	newPos.y += velocity.y * dt;

	left   = static_cast<int>((newPos.x - PLAYER_WIDTH) / BLOCK_SIZE);
	right  = static_cast<int>((newPos.x + PLAYER_WIDTH) / BLOCK_SIZE);
	top	   = static_cast<int>((newPos.y - PLAYER_HEIGHT) / BLOCK_SIZE);
	bottom = static_cast<int>((newPos.y + PLAYER_HEIGHT) / BLOCK_SIZE);

	if (velocity.y > 0) {
		if (bottom < MAP_HEIGHT) {
			for (int x = left; x <= right; x++) { // goes from top, middle, bottom and should stop at bottom
				if (isSolid(map[bottom][x])) {
					newPos.y = bottom * BLOCK_SIZE - PLAYER_HEIGHT;
					velocity.y = 0;
					onGround = true;
				}
			}
		}
		else {
			resetPlayerPos(playerPos);
		}
	}
	else if (velocity.y < 0) {
		if (top >= 0) {
			for (int x = left; x <= right; x++) { // goes from top, middle, bottom and should stop at bottom
				if (isSolid(map[top][x])) {
					newPos.y = top * BLOCK_SIZE + PLAYER_HEIGHT;
					velocity.y = 0;
				}
			}
		}
		else {
			resetPlayerPos(playerPos);
		}
	}
	playerPos = newPos;
}
