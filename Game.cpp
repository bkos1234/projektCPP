#include "Game.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Game::Game(sf::RenderWindow& window) : window(window), player("player.png", 100, 100), isRunning(true), environment(128)
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
		{
			isRunning = false;
			window.close();
		}
	}

	player.input(environment);
}

void Game::update()
{
	for (const auto& treeBox : environment.treeCollisionBoxes) {
		if (player.checkCollision(treeBox)) {
			player.revertToLastSafePosition();
		}
	}

	for (const auto& rockBox : environment.stoneCollisionBoxes) {
		if (player.checkCollision(rockBox)) {
			player.revertToLastSafePosition();
		}
	}

	for (const auto& waterBox : environment.waterCollisionBoxes) {
		if (player.checkCollision(waterBox)) {
			player.revertToLastSafePosition();
		}
	}

	for (const auto& lavaBox : environment.lavaCollisionBoxes) {
		if (player.checkCollision(lavaBox)) {
			player.setLastSafePosition({0,0});
			player.revertToLastSafePosition();
		}
	}
	player.update();
}

void Game::render()
{
	window.clear();
	environment.draw(window);
	player.draw(window);
	window.display();
}
