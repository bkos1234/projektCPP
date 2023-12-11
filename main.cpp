#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "gra");
	window.setFramerateLimit(60);

	Game game(window);

	game.run();
}