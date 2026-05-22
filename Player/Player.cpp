#include "Player.hpp"

Player::Player(const sf::Vector2<float>& startingPos, const float& playerWidth, const float& playerHeight)
{
	player.setSize({ playerWidth, playerHeight});
	player.setFillColor(sf::Color::Magenta);	
	player.setPosition(startingPos);
}
//------------------------------------------------
void Player::update() 
{

}
//------------------------------------------------
sf::Vector2<float> Player::getPosition()
{
	return player.getPosition();
}
//------------------------------------------------
sf::Vector2<float> Player::getCenteredPos()
{
	return {player.getPosition().x + PLAYER_WIDTH / 2, player.getPosition().y + PLAYER_HEIGHT / 2};
}
//------------------------------------------------
void Player::move( sf::Vector2<float> speed )
{
	player.move(speed);
}
//------------------------------------------------
void Player::setPosition( sf::Vector2<float> playerPos )
{
	player.setPosition(playerPos);
}
//------------------------------------------------
sf::Rect<float> Player::getGlobalBounds()
{
	return player.getGlobalBounds();
}
//------------------------------------------------
void Player::draw(sf::RenderWindow& window)
{
	window.draw(player);
}
//------------------------------------------------
