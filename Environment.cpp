#include "Environment.h"
#include <ctime>

Environment::Environment(int tileSize)
{
	grassTexture.loadFromFile("grass.png");
	treeTexture.loadFromFile("tree.png");

	generateMapData();
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			tileSprites[i][j].setPosition(i * tileSize, j * tileSize);
			treeSprites[i][j].setPosition(i * tileSize, j * tileSize);
		}
	}
}

void Environment::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			window.draw(tileSprites[i][j]);
			if (mapData[i][j] == 1)
			{
				window.draw(treeSprites[i][j]);
			}
		}
	}
}

void Environment::load(int mapData[30][16])
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			tileSprites[i][j].setTexture(grassTexture);
			if (mapData[i][j] == 1)
			{
				treeSprites[i][j].setTexture(treeTexture);
			}
		}
	}
}

void Environment::generateMapData()
{
	std::srand(std::time(0));

	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 16; j++) {
			int randomValue = std::rand() % 10;
			mapData[i][j] = randomValue;
		}
	}

	load(mapData);
}
