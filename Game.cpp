#include "Game.h"

Game::Game(sf::RenderWindow& window) : window(window), menu(window), player("player.png", 100, 100), isRunning(true), environment(128), ui(player), isPlayerDead(false), currentState(GameState::MainMenu)
{
	window.setFramerateLimit(60);
}

void Game::run()
{
	while (isRunning)
	{
		processEvents();
		if (currentState == GameState::Playing)
		{
			update();
		}
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
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Escape) {
				if (currentState == GameState::Playing) {
					currentState = GameState::Paused;
				}
				else if (currentState == GameState::Paused) {
					currentState = GameState::Playing;
				}
			}
		}
		else if (currentState == GameState::MainMenu)
		{
			menu.handleInput(event);
		}
		else if (currentState == GameState::LevelSelection)
		{
			menu.handleLevelSelectionInput(event);
			if (menu.isLevel1ButtonPressed())
			{
				loadMapFromFile("level1.txt");
			}
			else if (menu.isLevel2ButtonPressed())
			{
				loadMapFromFile("level2.txt");
			}
			else if (menu.isGenerateLevelButtonPressed())
			{
				environment.generateMapData();
			}
		}
		else if (currentState == GameState::Paused)
		{
			menu.handlePauseInput(event);
		}
	}

	switch (currentState)
	{
	case GameState::MainMenu:
		if (menu.isStartButtonPressed()) {
			std::cout << "Kliknieto start";
			changeState(GameState::LevelSelection);
			menu.setStartButtonPressed(false);
		}
		else if (menu.isExitButtonPressed()) {
			isRunning = false;
		}
		break;
	case GameState::LevelSelection:
		if (menu.isLevel1ButtonPressed()) {
			changeState(GameState::Playing);
			menu.setLevel1ButtonPressed(false);
		}
		else if (menu.isLevel2ButtonPressed()) {
			changeState(GameState::Playing);
			menu.setLevel2ButtonPressed(false);
		}
		else if (menu.isGenerateLevelButtonPressed()) {
			changeState(GameState::Playing);
			menu.setGenerateLevelButtonPressed(false);
		}
		break;
	case GameState::Playing:
		player.input(environment, window, projectileManager);
		ui.load();
		if (projectileManager.checkPlayerCollision(player.getBounds()))
		{
			player.decreaseHealth(40);
		}
		break;
	case GameState::Paused:
		if (menu.isResumeButtonPressed()) {
			changeState(GameState::Playing);
		}
		else if (menu.isExitToMainButtonPressed()) {
			changeState(GameState::MainMenu);
			reset();
		}
	}
}

void Game::update()
{
	switch (currentState)
	{
	case GameState::Playing:
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
		projectileManager.checkCollisions(environment); // sprawdza kolizje pociskow z obiektami i usuwa pociski ktore maja kolizje
		std::vector<Enemy>& enemies = enemyManager.getEnemies();
		projectileManager.checkEnemyCollisions(enemies);
		break;
	}
}

void Game::render()
{
	window.clear();
	switch (currentState)
	{
	case GameState::MainMenu:
		menu.draw();
		std::cout << "Menu";
		break;
	case GameState::LevelSelection:
		menu.drawLevelSelectionMenu();
		break;
	case GameState::Playing:
			environment.draw(window);
			player.draw(window);
			enemyManager.draw(window);
			projectileManager.draw(window);
			ui.draw(window);
			if (player.isDead())
			{
				ui.drawDeathScreen(window);
			}
			break;
	case GameState::Paused:
		environment.draw(window);
		player.draw(window);
		enemyManager.draw(window);
		projectileManager.draw(window);
		menu.drawPauseMenu();
		break;
	}
	window.display();
}

void Game::handlePlayerDeath()
{
	ui.drawDeathScreen(window);
}

void Game::changeState(GameState newState)
{
	currentState = newState;
}

void Game::reset()
{
	environment.reset();
	player.reset();
}

void Game::loadMapFromFile(const std::string& filename) {
	environment.loadMapFromFile(filename); // wczytaj mapê z pliku
	enemyManager.loadEnemiesFromFile(filename, projectileManager); // wczytaj przeciwników z tego samego pliku
}