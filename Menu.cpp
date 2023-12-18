#include "Menu.h"
#include <iostream>

Menu::Menu(sf::RenderWindow& window) : window(window), startButtonPressed(false), exitButtonPressed(false)
{
	load();
}

void Menu::load()
{
	// odstêp miêdzy przyciskami
	const float buttonSpacing = 50.0;

	// przycisk start
	if (!startButtonTexture.loadFromFile("startButton.png")) {
		std::cout << "B³¹d podczas ³adowania przycisku startu";
	}

	startButton.setTexture(startButtonTexture);
	startButton.setPosition(window.getSize().x / 2 - startButton.getGlobalBounds().width / 2, window.getSize().y / 2 - startButton.getGlobalBounds().height / 2 - 100);

	// przycisk ustawienia
	if (!settingsButtonTexture.loadFromFile("settingsButton.png")) {
		std::cout << "B³¹d podczas ³adowania przycisku ustawieñ";
	}

	settingsButton.setTexture(settingsButtonTexture);
	settingsButton.setPosition(window.getSize().x / 2 - settingsButton.getGlobalBounds().width / 2, startButton.getPosition().y + startButton.getGlobalBounds().height + buttonSpacing);

	// przycisk zakoñcz
	if (!exitButtonTexture.loadFromFile("exitButton.png")) {
		std::cout << "B³¹d podczas ³adowania przycisku zamykania gry";
	}

	exitButton.setTexture(exitButtonTexture);
	exitButton.setPosition(window.getSize().x / 2 - exitButton.getGlobalBounds().width / 2, settingsButton.getPosition().y + settingsButton.getGlobalBounds().height + buttonSpacing);

	// przycisk wznów
	if (!resumeButtonTexture.loadFromFile("resumeButton.png")) {
		std::cout << "B³¹d podczas ³adowania przycisku wznawiania";
	}

	resumeButton.setTexture(resumeButtonTexture);
	resumeButton.setPosition(window.getSize().x / 2 - resumeButton.getGlobalBounds().width / 2, window.getSize().y / 2 - resumeButton.getGlobalBounds().height / 2 - 100);

	// przycisk wyjdŸ do menu g³ównego
	if (!exitToMainButtonTexture.loadFromFile("exitToMainButton.png")) {
		std::cout << "B³¹d podczas ³adowania przycisku powrotu do menu g³ównego";
	}

	exitToMainButton.setTexture(exitToMainButtonTexture);
	exitToMainButton.setPosition(window.getSize().x / 2 - exitToMainButton.getGlobalBounds().width / 2, resumeButton.getPosition().y + resumeButton.getGlobalBounds().height + buttonSpacing);

	// napis pauza
	if (!pauseTextTexture.loadFromFile("pauseText.png")) {
		std::cout << "B³¹d podczas ³adowania napisu pauzy";
	}

	pauseText.setTexture(pauseTextTexture);
	pauseText.setPosition(window.getSize().x / 2 - exitToMainButton.getGlobalBounds().width / 2, resumeButton.getPosition().y + resumeButton.getGlobalBounds().height + buttonSpacing - 300);

	// t³o
	if (!backgroundTexture.loadFromFile("background.png")) {
		std::cout << "B³¹d podczas ³adowania t³a";
	}

	background.setTexture(backgroundTexture);
	background.setPosition(0, 0);

	if (!level1ButtonTexture.loadFromFile("level1.png")) {
		std::cout << "B³¹d";
	}

	level1Button.setTexture(level1ButtonTexture);
	level1Button.setPosition(window.getSize().x / 2 - level1Button.getGlobalBounds().width / 2, window.getSize().y / 2 - level1Button.getGlobalBounds().height / 2 - 100);

	if (!generateLevelButtonTexture.loadFromFile("generateLevel.png")) {
		std::cout << "B³¹d";
	}

	generateLevelButton.setTexture(generateLevelButtonTexture);
	generateLevelButton.setPosition(window.getSize().x / 2 - generateLevelButton.getGlobalBounds().width / 2, level1Button.getPosition().y + level1Button.getGlobalBounds().height + buttonSpacing);
}

void Menu::draw() {
	window.draw(background);
	window.draw(startButton);
	window.draw(settingsButton);
	window.draw(exitButton);
}

void Menu::drawPauseMenu()
{
	window.draw(pauseText);
	window.draw(resumeButton);
	window.draw(exitToMainButton);
}

void Menu::drawLevelSelectionMenu()
{
	window.draw(background);
	window.draw(level1Button);
	window.draw(generateLevelButton);
}

bool Menu::isStartButtonPressed() {
	return startButtonPressed;
}

void Menu::handleInput(sf::Event& event) {
	exitButtonPressed = false;
	startButtonPressed = false;
	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.mouseButton.button == sf::Mouse::Left) {
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			if (startButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
				startButtonPressed = true;
			else if (exitButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
				exitButtonPressed = true;
		}
	}
}

void Menu::handleLevelSelectionInput(sf::Event& event) {
	level1ButtonPressed = false;
	generateLevelButtonPressed = false;
	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.mouseButton.button == sf::Mouse::Left) {
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			if (level1Button.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
				level1ButtonPressed = true;
			else if (generateLevelButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
				generateLevelButtonPressed = true;
		}
	}
}

void Menu::handlePauseInput(sf::Event& event) {
	resumeButtonPressed = false;
	exitToMainButtonPressed = false;
	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.mouseButton.button == sf::Mouse::Left) {
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			if (resumeButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
				resumeButtonPressed = true;
			else if (exitToMainButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
				exitToMainButtonPressed = true;
		}
	}
}

bool Menu::isExitButtonPressed() {
	return exitButtonPressed;
}

bool Menu::isResumeButtonPressed() {
	if (resumeButtonPressed == true)
	std::cout << "Wcisnieto wznow";
	return resumeButtonPressed;
}

bool Menu::isExitToMainButtonPressed()
{
	if (exitToMainButtonPressed == true)
	std::cout << "Wcisnieto wroc do menu glownego";
	return exitToMainButtonPressed;
}

bool Menu::isLevel1ButtonPressed()
{
	return level1ButtonPressed;
}

bool Menu::isGenerateLevelButtonPressed()
{
	return generateLevelButtonPressed;
}

void Menu::setStartButtonPressed(bool value)
{
	startButtonPressed = value;
}

void Menu::setResumeButtonPressed(bool value)
{
	resumeButtonPressed = value;
}

void Menu::setExitToMainButtonPressed(bool value)
{
	exitToMainButtonPressed = value;
}

void Menu::setLevel1ButtonPressed(bool value)
{
	level1ButtonPressed = value;
}

void Menu::setGenerateLevelButtonPressed(bool value)
{
	generateLevelButtonPressed = value;
}
