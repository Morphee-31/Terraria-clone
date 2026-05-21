#pragma once

#include "SFML/Graphics.hpp"

const struct Colors {
	sf::Vector3<int> Black = {0,0,0};
	sf::Vector3<int> White = { 255,255,255 };

	sf::Vector3<int> Red = { 255,0,0 };
	sf::Vector3<int> Green = { 0,255,255 };
	sf::Vector3<int> Blue = { 0,0,255 };

	sf::Vector3<int> LightGray = { 220,220,220 };
	sf::Vector3<int> Gray = { 125,125,125 };
	sf::Vector3<int> DarkGray = { 64,64,64 };

	sf::Vector3<int> Pink = { 255, 96, 208 };
	sf::Vector3<int> PalePink = { 255,208,160 };
	sf::Vector3<int> Purple = { 160,208,255 };
	sf::Vector3<int> LightBlue = { 80,208,255 };
	sf::Vector3<int> Yellow_Green = { 96,255,128 };
	sf::Vector3<int> Yellow = { 255,224, 32 };
	sf::Vector3<int> Orange = { 255,160,16 };
	sf::Vector3<int> Brown = { 160,128,96 };
};

//struct Colors {
//	unsigned char red;
//	unsigned char green;
//	unsigned char blue;
//  unsigned char opacity;
//};