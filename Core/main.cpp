#include <SFML/Graphics.hpp>

#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

#include "Config.hpp"
#include "TileName.hpp"

#include "InitGame.hpp"
#include "Utility.hpp"
#include "Colors.hpp"
#include "Rendering_Engine.hpp"
#include "PerlinNoise.hpp"

#include "Collisions.hpp"
#include "Blocks.hpp"
#include "MapGen.hpp"

// CLASSES
#include "Player.hpp"



int main() {
	// INIT WINDOW

	sf::RenderWindow window(sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }), WINDOW_TITLE);
	window.setFramerateLimit(FPS);
	
	gameLoop(window);

	return 0;
}


