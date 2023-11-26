#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Environment.h"
#include "UI.h"
#include "EnemyManager.h"
#include "ProjectileManager.h"

class Game
{
public:
	Game(sf::RenderWindow& window);
	void run();

private:
	sf::RenderWindow& window;
	Player player;
	bool isRunning;
	Environment environment;
	UI ui;
	EnemyManager enemyManager;
	ProjectileManager projectileManager;
	bool isPlayerDead;

	void processEvents();
	void update();
	void render();
	void handlePlayerDeath();
};