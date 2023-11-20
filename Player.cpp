#include "Player.h"
#include <string>
#include <iostream>
#include "Environment.h"

Player::Player(const std::string& filename, float x, float y)
{
	texture.loadFromFile(filename);
	sprite.setTexture(texture);
	position.x = x;
	position.y = y;
	sprite.setPosition(position);
	maxHealth = 100;
	health = maxHealth;
}

void Player::input(const Environment& environment)
{
	sf::Vector2f previousPosition = position;
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
	bool collision = false;
	for (const auto& treeBox : environment.treeCollisionBoxes) {
		if (checkCollision(treeBox)) {
			collision = true;
			break;
		}
	}
	for (const auto& rockBox : environment.stoneCollisionBoxes) {
		if (checkCollision(rockBox)) {
			collision = true;
			break;
		}
	}

	for (const auto& waterBox : environment.waterCollisionBoxes) {
		if (checkCollision(waterBox)) {
			collision = true;
			break;
		}
	}

	for (const auto& lavaBox : environment.lavaCollisionBoxes) {
		if (checkCollision(lavaBox)) {
			collision = true;
			break;
		}
	}

	// Jeœli nie, to zaktualizuj zmienn¹ lastSafePosition
	if (!collision) {
		lastSafePosition = previousPosition;
	}
}

void Player::revertToLastSafePosition() {
	position = lastSafePosition;
	sprite.setPosition(position);
}

void Player::update()
{
	sprite.setPosition(position);
}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(sprite);
}

bool Player::checkCollision(const sf::FloatRect& obstacle) const {
	return getBounds().intersects(obstacle);
}

sf::FloatRect Player::getBounds() const {
	return sprite.getGlobalBounds();
}

void Player::setLastSafePosition(const sf::Vector2f& newPosition) {
	lastSafePosition = newPosition;
}

sf::Vector2f Player::getPosition() const
{
	return position;
}

sf::Vector2f Player::getLastSafePosition() const
{
	return lastSafePosition;
}

void Player::decreaseHealth(int amount)
{
	health -= amount;
	if (health < 0) {
		health = 0;
	}
}

int Player::getHealth() const
{
	return health;
}

int Player::getMaxHealth() const
{
	return maxHealth;
}

bool Player::isDead() const
{
	return health == 0;
}

void Player::setHealth(int value)
{
	health = value;
}
