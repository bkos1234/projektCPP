#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include "Environment.h"

class Player
{
public:
	Player(const std::string& filename, float x, float y);

	void move(float x, float y);
	void input(const Environment& environment);
	void update();
	void draw(sf::RenderWindow& window);
	bool checkCollision(const sf::FloatRect& obstacle) const;
	void revertToLastSafePosition(); // cofa do ostatniej bezpiecznej pozycji
	sf::FloatRect getBounds() const;
	void setLastSafePosition(const sf::Vector2f & newPosition);
	sf::Vector2f getPosition() const;
	sf::Vector2f getLastSafePosition() const;

private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f position;
	sf::Vector2f lastSafePosition;
	float speed = 2;
	sf::Vector2f pozycja0 = { 0,0 };
};