#pragma once

#include <SFML/Graphics.hpp>

class Environment
{
public:

	Environment(int tileSize);
	void draw(sf::RenderWindow& window);
	void load(int mapData[30][16]);

private:

	sf::Texture grassTexture;
	sf::Texture treeTexture;
	sf::Sprite tileSprites[30][16];
	sf::Sprite treeSprites[30][16];
	int mapData[30][16];
	void generateMapData();
};