#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player(const std::string& filename, float x, float y);

	void move(float x, float y);
	void input();
	void update();
	void draw(sf::RenderWindow& window);

private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f position;
	float speed = 5;
};