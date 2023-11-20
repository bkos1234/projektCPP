#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

class UI
{
public:
	UI(Player& player);
	void draw(sf::RenderWindow& window);
	void load();
	void updateHealthBar();
	void drawDeathScreen(sf::RenderWindow& window);

private:
	Player& player;
	sf::Font font;
	sf::Text healthText;
	sf::RectangleShape healthBar;
	sf::Texture deathScreenTexture;
	sf::Sprite deathScreen;
};