#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Environment.h"

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

	void processEvents();
	void update();
	void render();
};