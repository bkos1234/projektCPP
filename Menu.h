#pragma once
#include <SFML/Graphics.hpp>

class Menu
{
public:
    Menu(sf::RenderWindow& window);
    void draw();
    bool isStartButtonPressed();
    bool isExitButtonPressed();
    void setStartButtonPressed(bool value);

private:
    sf::RenderWindow& window;
    sf::Texture startButtonTexture;
    sf::Texture settingsButtonTexture;
    sf::Texture exitButtonTexture;
    sf::Texture backgroundTexture;
    sf::Sprite startButton;
    sf::Sprite settingsButton;
    sf::Sprite exitButton;
    sf::Sprite background;
    bool startButtonPressed;
    bool exitButtonPressed;
    bool settingsButtonPressed;

    void load();
    void handleInput();
};