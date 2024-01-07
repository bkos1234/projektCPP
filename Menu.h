#pragma once
#include <SFML/Graphics.hpp>

class Menu
{
public:
    Menu(sf::RenderWindow& window);
    void draw();
    void drawPauseMenu();
    void drawLevelSelectionMenu();
    bool isStartButtonPressed();
    bool isExitButtonPressed();
    bool isResumeButtonPressed();
    bool isExitToMainButtonPressed();
    bool isLevel1ButtonPressed();
    bool isLevel2ButtonPressed();
    bool isGenerateLevelButtonPressed();
    void setStartButtonPressed(bool value);
    void setResumeButtonPressed(bool value);
    void setExitToMainButtonPressed(bool value);
    void setLevel1ButtonPressed(bool value);
    void setLevel2ButtonPressed(bool value);
    void setGenerateLevelButtonPressed(bool value);
    void handleInput(sf::Event& event);
    void handleLevelSelectionInput(sf::Event& event);
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

    sf::Texture level1ButtonTexture;
    sf::Texture level2ButtonTexture;
    sf::Texture generateLevelButtonTexture;

    sf::Sprite startButton;
    sf::Sprite settingsButton;
    sf::Sprite exitButton;
    sf::Sprite background;
    sf::Sprite level1Button;
    sf::Sprite level2Button;
    sf::Sprite generateLevelButton;

    sf::Sprite pauseText;

    sf::Sprite resumeButton;
    sf::Sprite exitToMainButton;

    bool startButtonPressed;
    bool exitButtonPressed;
    bool settingsButtonPressed;

    bool resumeButtonPressed;
    bool exitToMainButtonPressed;

    bool level1ButtonPressed;
    bool level2ButtonPressed;
    bool generateLevelButtonPressed;

    void load();
};