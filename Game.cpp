#include "Game.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <chrono>

Game::Game(sf::RenderWindow& window) : window(window), player("player.png", 100, 100), isRunning(true), environment(128, enemyManager, projectileManager), ui(player), isPlayerDead(false)
{
	window.setFramerateLimit(60);
	enemyManager.addEnemy(sf::Vector2f(2 * 128, 2 * 128), projectileManager,100);
	enemyManager.addEnemy(sf::Vector2f(8 * 128, 4 * 128), projectileManager,100);
	enemyManager.addEnemy(sf::Vector2f(12 * 128, 6 * 128), projectileManager,100);
	enemyManager.addEnemy(sf::Vector2f(14 * 128, 6 * 128), projectileManager,100);
	enemyManager.addEnemy(sf::Vector2f(4 * 128, 4 * 128), projectileManager,100);
	enemyManager.addEnemy(sf::Vector2f(6 * 128, 2 * 128), projectileManager,100);
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

	player.input(environment, window, projectileManager);
	ui.load();
	if (projectileManager.checkPlayerCollision(player.getBounds()))
	{
		player.decreaseHealth(40);
	}
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
			player.decreaseHealth(1);
		}
	}
	player.update();
	enemyManager.update(player.getPosition());
	projectileManager.update();
}

void Game::render()
{
	window.clear();
	environment.draw(window);
	player.draw(window);
	enemyManager.draw(window);
	projectileManager.draw(window);
	ui.draw(window);
	if (player.isDead())
	{
		ui.drawDeathScreen(window);
	}
	window.display();
}

void Game::handlePlayerDeath()
{
	ui.drawDeathScreen(window);
}
