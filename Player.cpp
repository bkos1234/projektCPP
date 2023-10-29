#include "Player.h"
#include <string>

Player::Player(const std::string& filename, float x, float y)
{
	texture.loadFromFile(filename);
	sprite.setTexture(texture);
	position.x = x;
	position.y = y;
	sprite.setPosition(position);
}

void Player::input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		position.y -= speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		position.y += speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		position.x -= speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		position.x += speed;
	}
}

void Player::update()
{
	sprite.setPosition(position);
}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}
