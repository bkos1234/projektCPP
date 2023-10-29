#include "Game.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

Game::Game() : window(sf::VideoMode(1920, 1080), "gra"), player("player.png", 100, 100), isRunning(true), environment(64)
{
	window.setFramerateLimit(60);
}

void Game::run()
{
	while (isRunning)
	{
		processEvents();
		update();
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			isRunning = false;
	}

	player.input();
}

void Game::update()
{
	player.update();
}

void Game::render()
{
	window.clear();
	environment.draw(window);
	player.draw(window);
	window.display();
}
