#include "UI.h"
#include "Player.h"

UI::UI(Player& player) : player(player)
{
	deathScreenTexture.loadFromFile("deathScreen.png");
	deathScreen.setTexture(deathScreenTexture);
	deathScreen.setPosition(0, 0);
}

void UI::draw(sf::RenderWindow& window)
{
	window.draw(healthBar);
}

void UI::load()
{
	updateHealthBar();
}

void UI::updateHealthBar()
{
	healthBar.setSize(sf::Vector2f(200, 20));
	healthBar.setFillColor(sf::Color::Red);
	healthBar.setPosition(1600, 40);

	// healthRatio to stosunek aktualnego zdrowia do maksymalnego zdrowia (0-1)
	float healthRatio = static_cast<float>(player.getHealth()) / static_cast<float>(player.getMaxHealth());
	healthBar.setSize(sf::Vector2f(200 * healthRatio, 20));
}

void UI::drawDeathScreen(sf::RenderWindow& window)
{
	window.draw(deathScreen);
}