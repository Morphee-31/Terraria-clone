#pragma once

// Window
constexpr unsigned short WINDOW_WIDTH = 1280;
constexpr unsigned short WINDOW_HEIGHT = 720;

constexpr float WINDOW_HALF_WIDTH = static_cast<float>(WINDOW_WIDTH) / 2;
constexpr float WINDOW_HALF_HEIGHT = static_cast<float>(WINDOW_HEIGHT) / 2;

constexpr unsigned short FPS = 100;
constexpr const char* WINDOW_TITLE = "My Game";

// UNIVERSAL
constexpr float GRAVITY = 10.0f;
constexpr float EPSILON = 0.005f;

// World Size
constexpr float	BLOCK_SIZE = 20.0f;
constexpr float BLOCK_OUTLINE_THICKNESS = 0.0f;

constexpr int	SCALING_FACTOR = 2;
constexpr int	MAP_HEIGHT = (WINDOW_HEIGHT / BLOCK_SIZE) * SCALING_FACTOR;
constexpr int	MAP_WIDTH = (WINDOW_WIDTH / BLOCK_SIZE) * SCALING_FACTOR;

constexpr float MAP_PIXEL_WIDTH = MAP_WIDTH * BLOCK_SIZE;
constexpr float MAP_PIXEL_HEIGHT = MAP_HEIGHT * BLOCK_SIZE;

// Player
// SHOULD REMOVE THE PLAYER_RADIUS THING, IS REALLY ABSTACTING A LOT BECAUSE -> CIRCLE WHILE POLYGON
constexpr float PLAYER_HEIGHT = 18.0f;
constexpr float PLAYER_WIDTH = 9.0f;

constexpr float PLAYER_SPEED = 150.0f;
constexpr int   PLAYER_REACH = 5 * BLOCK_SIZE;
constexpr float SLIDE = 1.5f;

// MIGHT ADD A LITLLE ALGORITHM TO FIND THE HIGHEST DIRT BLOCK IN THE MIDDLE OF THE SCREEN WIDTH
constexpr float STARTING_X = WINDOW_WIDTH / 2.0f;
constexpr float STARTING_Y = 20.0f;



