#pragma once

#include <SFML/Graphics.hpp>

struct Tile {
	int ground;
	int object;
};

class Environment
{
public:

	Environment(int tileSize);
	void draw(sf::RenderWindow& window);
	void load(Tile mapData[15][8]);
	void addCollisionBox(int objectType, int i, int j, int tileSize, int treeWidth, int treeHeight);
	std::vector<sf::FloatRect> waterCollisionBoxes;
	std::vector<sf::FloatRect> treeCollisionBoxes;
	std::vector<sf::FloatRect> stoneCollisionBoxes;
	std::vector<sf::FloatRect> lavaCollisionBoxes;
	int getObjectWidth(int objectType); // funkcja zwracaj¹ca szerokoœæ obiektu
	int getObjectHeight(int objectType); // funkcja zwracaj¹ca wysokoœæ obiektu

private:

	sf::Texture grassTexture;
	sf::Texture treeTexture;
	sf::Texture sandTexture;
	sf::Texture waterTexture;
	sf::Texture rockTexture;
	sf::Texture lavaTexture;
	sf::Texture flowerTexture;
	sf::Sprite groundSprites[15][8];
	sf::Sprite objectSprites[15][8];
	void generateMapData();
	Tile mapData[15][8];
};