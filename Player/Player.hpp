#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Config.hpp"


class Player {
protected:
	sf::RectangleShape player;
public:
	// VARIABLES 
	float maxHealth = 100.0f;
	float health = maxHealth;

	// FONCTIONS	
	Player(const sf::Vector2<float>& startingPos, const float& playerWidth, const float& playerHeight);
	void update();

public:		// MOVING PLAYER FUNCTIONS
	void move(sf::Vector2<float> speed);
	void setPosition( sf::Vector2<float> );

public: 	// INFORMATIONS RETURNING FUNCTIONS
	sf::Vector2<float> getPosition();
	sf::Vector2<float> getCenteredPos();
	sf::Rect<float>	getGlobalBounds();

public:		// DO NOT TOUCH
	void draw(sf::RenderWindow& window);
};