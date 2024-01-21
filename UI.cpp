#include "UI.h"
#include "Player.h"

UI::UI(Player& player) : player(player)
{
	font.loadFromFile("roboto.ttf");
	enemiesCountText.setFont(font);
	enemiesCountText.setCharacterSize(24);
	enemiesCountText.setFillColor(sf::Color::White);
	enemiesCountText.setPosition(1600, 160);

	healthBar.setSize(sf::Vector2f(200, 20));
	healthBar.setFillColor(sf::Color::Green);
	healthBar.setPosition(1600, 60);

	healthBar.setOutlineColor(sf::Color::Black);
	healthBar.setOutlineThickness(5);

	enemiesCountText.setOutlineColor(sf::Color::Black);
	enemiesCountText.setOutlineThickness(2);

	healthText.setFont(font);
	healthText.setString("ZDROWIE:");
	healthText.setCharacterSize(24);
	healthText.setFillColor(sf::Color::White);
	healthText.setOutlineColor(sf::Color::Black);
	healthText.setOutlineThickness(2);
	healthText.setPosition(1600, 20);
}

void UI::draw(sf::RenderWindow& window)
{
	window.draw(healthText);
	window.draw(healthBar);
	window.draw(enemiesCountText);
}

void UI::load()
{
	updateHealthBar();
}

void UI::updateHealthBar()
{

	// healthRatio to stosunek aktualnego zdrowia do maksymalnego zdrowia (0-1)
	float healthRatio = static_cast<float>(player.getHealth()) / static_cast<float>(player.getMaxHealth());
	healthBar.setSize(sf::Vector2f(200 * healthRatio, 20));

	if (healthRatio > 0.75) // jeœli zdrowie jest wiêksze ni¿ 50%, kolor paska zdrowia zmienia siê na zielony
	{
		healthBar.setFillColor(sf::Color::Green);
	}
	else if (healthRatio > 0.4) // jeœli zdrowie jest wiêksze ni¿ 25%, kolor paska zdrowia zmienia siê na ¿ó³ty
	{
		healthBar.setFillColor(sf::Color::Yellow);
	}
	else
	{
		healthBar.setFillColor(sf::Color::Red);
	}
}

void UI::updateEnemiesCount(int deadEnemiesCount, int totalEnemiesCount)
{
	enemiesCountText.setString("Pokonani przeciwnicy: " + std::to_string(deadEnemiesCount) + "/" + std::to_string(totalEnemiesCount));
}