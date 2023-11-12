#pragma once
#include <SFML/Graphics.hpp>

class Menu
{
public:
    Menu(sf::RenderWindow& window);
    void draw();
    bool isStartButtonPressed();

private:
    sf::RenderWindow& window;
    sf::Texture startButtonTexture;
    sf::Texture backgroundTexture;
    sf::Sprite startButton;
    sf::Sprite background;
    bool startButtonPressed;

    void load();
    void handleInput();
};