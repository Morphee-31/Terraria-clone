#include "InitGame.hpp"


void gameLoop(sf::RenderWindow& window)
{
	// INITMAP
	std::vector<std::vector<TileName>> map(MAP_HEIGHT, std::vector<TileName>(MAP_WIDTH, TileName::Air));

	InitMap(map);

	// INIT PLAYER
	sf::Vector2<float> playerPos{ STARTING_X, STARTING_Y };
	Player player(playerPos, PLAYER_WIDTH, PLAYER_HEIGHT);
	sf::Vector2<float> velocity{ 0.0f , 0.0f };

	int playerX = static_cast<int>(playerPos.x / BLOCK_SIZE);
	int playerY = static_cast<int>(playerPos.y / BLOCK_SIZE);

	TileName selectedBlock = TileName::Dirt;

	// INIT VIEW
	sf::Vector2<float> cameraPos = playerPos;
	sf::View playerView({ cameraPos, { WINDOW_WIDTH, WINDOW_HEIGHT }});
	window.setView(playerView);

	// INIT BLOCKS SHAPE
	sf::RectangleShape tileShape;
	
	tileShape.setSize({ BLOCK_SIZE - BLOCK_OUTLINE_THICKNESS, BLOCK_SIZE - BLOCK_OUTLINE_THICKNESS });
	tileShape.setOutlineThickness(BLOCK_OUTLINE_THICKNESS);
	tileShape.setOutlineColor(sf::Color::Black);
	tileShape.setSize({ BLOCK_SIZE, BLOCK_SIZE });


	// INIT TIME
	sf::Clock clock;
	clock.start();

	// CONTROLS
	const Controls controls;

	bool onGround = false;
	bool jump = false;
	bool climbing = false;
	float terrainStrain = 1.0;

	while (window.isOpen()) {
		// ===== TIME =====
		float dt = clock.restart().asSeconds();
		bool buttonPressed = false;
		jump = false;

		// =========================
		// ===== EVENTS ======
		// =========================
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window.close();
			}

			else if (event->getIf<sf::Event::KeyPressed>()) {
				const auto* keyPressed = event->getIf<sf::Event::KeyPressed>();
				switch (keyPressed->code) {

				case Key::Tab:
					std::cout << "\nPosition joueur : " << playerPos.y << '\t' << playerPos.x << '\n';
					std::cout << "Position tile : " << playerY << '\t' << playerX << '\n';
					break;
				case Key::Enter:
					player.setPosition({ WINDOW_WIDTH / 2.0f, 20 });
					velocity.y = 0;
					break;
				case Key::Space:
					jump = true;
					break;

				case Key::Num1:		selectedBlock = TileName::Dirt;		break;
				case Key::Num2:		selectedBlock = TileName::Sand;		break;
				case Key::Num3:		selectedBlock = TileName::Lava;		break;
				case Key::Num4:		selectedBlock = TileName::Water;	break;
				case Key::Num5:		selectedBlock = TileName::Ladder;	break;
				case Key::Num6:		selectedBlock = TileName::Stone;	break;
					//default:			selectedBlock = TileName::Nothing;	break;
				}
			}
		}

		// ==========================
		// ======   UPDATE   ======
		// ==========================


		//-----------------------
		// PLACE & BREAK BLOCKS
		//-----------------------
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) {
			placeBlocks(window, map, playerPos, selectedBlock, player);
		}
		else if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			breakBlocks(window, map, playerPos, player);
		}

		// ============================
		// ========= INPUT =========
		// ============================

		// RESET VELOCITY UNDER CERTAIN CONDITIONS

		velocity.x = 0;
		if (climbing) {
			velocity.y = 0;
		}

		// X MOVEMENT
		if (sf::Keyboard::isKeyPressed(controls.right))		velocity.x += PLAYER_SPEED;
		if (sf::Keyboard::isKeyPressed(controls.left))		velocity.x -= PLAYER_SPEED;

		// Y MOVEMENT
		if ((sf::Keyboard::isKeyPressed(controls.up) || sf::Keyboard::isKeyPressed(controls.jump)) && climbing) {
			velocity.y = -PLAYER_SPEED;
		}		
		if (sf::Keyboard::isKeyPressed(controls.down) && climbing)	velocity.y = +PLAYER_SPEED;
		if (jump && onGround)	velocity.y = -PLAYER_SPEED * 10;

		// =========================
		// ====== PHYSICS ======
		// =========================

		if (!climbing)	velocity.y += GRAVITY * GRAVITY * dt * 10;	// GRAVITY

		// COLLISIONS
		handleTerrainStrains(map, playerX, playerY, climbing, terrainStrain);
		PlayerCollisions(map, playerPos, velocity, dt, onGround);

		// MOUVEMENT
		player.setPosition(playerPos);

		playerX = static_cast<int>(playerPos.x / BLOCK_SIZE);
		playerY = static_cast<int>(playerPos.y / BLOCK_SIZE);

		// ==== SETTING VIEW ====

		cameraPos = playerPos;
		cameraPos.x = std::clamp(cameraPos.x, WINDOW_HALF_WIDTH, MAP_PIXEL_WIDTH - WINDOW_HALF_WIDTH);
		cameraPos.y = std::clamp(cameraPos.y, WINDOW_HALF_HEIGHT, MAP_PIXEL_HEIGHT - WINDOW_HALF_HEIGHT);

		playerView.setCenter(cameraPos);
		window.setView(playerView);
		
		rendering(window, player, tileShape, map);
	}
}

void handleTerrainStrains(std::vector<std::vector<TileName>>& map, int& playerX, int& playerY, bool& climbing, float& terrainStrain) {

	terrainStrain = 1.0f;
	climbing = false;
	int bottom = playerY - 1;

	// HANDLING ERRORS
	if (playerX < 0 || playerX >= MAP_WIDTH || playerY >= MAP_HEIGHT) {
		return;		
	}

	if (playerY <= 0) {
		switch (map[playerY][playerX]) {
		case TileName::Water:	terrainStrain = 0.4f;	break;
		case TileName::Lava:    terrainStrain = 0.3f;	break;
		}
	}
	else if (bottom <= 0) {
		switch (map[bottom][playerX]) {
		case TileName::Dirt:	terrainStrain = 1.0f;	break;
		case TileName::Sand:	terrainStrain = 0.9f;	break;
		case TileName::Ladder:	terrainStrain = 0.5f;	climbing = true;	break;
		default:				terrainStrain = 1.0f;	break;
		}
	}
}

void resetPlayerPos(sf::Vector2<float>& playerPos)
{
	playerPos = { STARTING_X, STARTING_Y };
}
