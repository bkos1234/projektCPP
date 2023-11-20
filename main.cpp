#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Game.h"
#include "Menu.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "gra");
	window.setFramerateLimit(60);

	Menu menu(window);
	Game game(window);

    while (window.isOpen()) {
        if (menu.isStartButtonPressed()) {
            game.run();
        }
        else if (menu.isExitButtonPressed()) {
            window.close();
        }
        else {
            menu.draw();
        }
    }
}