#pragma once
#include <SFML/Graphics.hpp>

class Menu
{
public:
    Menu(sf::RenderWindow& window);
    void draw();
    void drawPauseMenu();
    bool isStartButtonPressed();
    bool isExitButtonPressed();
    bool isResumeButtonPressed();
    bool isExitToMainButtonPressed();
    void setStartButtonPressed(bool value);
    void setResumeButtonPressed(bool value);
    void setExitToMainButtonPressed(bool value);
    void handleInput(sf::Event& event);
    void handlePauseInput(sf::Event& event);

private:
    sf::RenderWindow& window;
    sf::Texture startButtonTexture;
    sf::Texture settingsButtonTexture;
    sf::Texture exitButtonTexture;
    sf::Texture backgroundTexture;

    sf::Texture resumeButtonTexture;
    sf::Texture exitToMainButtonTexture;

    sf::Texture pauseTextTexture;

    sf::Sprite startButton;
    sf::Sprite settingsButton;
    sf::Sprite exitButton;
    sf::Sprite background;

    sf::Sprite pauseText;

    sf::Sprite resumeButton;
    sf::Sprite exitToMainButton;

    bool startButtonPressed;
    bool exitButtonPressed;
    bool settingsButtonPressed;

    bool resumeButtonPressed;
    bool exitToMainButtonPressed;

    void load();
};