#pragma once
#include <SFML/Graphics.hpp>
class Player; // Forward declaration

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