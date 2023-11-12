#include "Menu.h"
#include <iostream>

Menu::Menu(sf::RenderWindow& window) : window(window), startButtonPressed(false)
{
	load();
}

void Menu::load()
{
	if (!startButtonTexture.loadFromFile("startButton.png")) {
		std::cout << "B³¹d podczas ³adowania przycisku";
	}

	startButton.setTexture(startButtonTexture);
	startButton.setPosition(window.getSize().x / 2 - startButton.getGlobalBounds().width / 2, window.getSize().y / 2 - startButton.getGlobalBounds().height / 2);

	if (!backgroundTexture.loadFromFile("background.png")) {
		std::cout << "B³¹d podczas ³adowania t³a";
	}

	background.setTexture(backgroundTexture);
	background.setPosition(0, 0);
}

void Menu::draw() {
	window.clear();
	window.draw(background);
	window.draw(startButton);
	window.display();
	handleInput();
}

bool Menu::isStartButtonPressed() {
	return startButtonPressed;
}

void Menu::handleInput() {
    sf::Event event;
    while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed)
		{
			window.close();
			break;
		}
		else if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(window);
				if (startButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
					startButtonPressed = true;
			}
		}
    }
}