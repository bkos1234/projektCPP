#include "EnemyManager.h"
#include "Enemy.h"
#include "ProjectileManager.h"
#include <algorithm>
#include <fstream>

void EnemyManager::addEnemy(sf::Vector2f startPosition, ProjectileManager& projectileManager, int maxHealth, EnemyType type)
{
	enemies.emplace_back(startPosition, projectileManager, maxHealth, type);
}

void EnemyManager::update(sf::Vector2f playerPosition)
{
	for (auto& enemy : enemies)
	{
		enemy.update(playerPosition);
	}
}

void EnemyManager::draw(sf::RenderWindow& window)
{
	for (const auto& enemy : enemies)
	{
		enemy.draw(window);
	}
}

std::vector<Enemy>& EnemyManager::getEnemies() {
	return enemies;
}

void EnemyManager::displayEnemies()
{
	std::cout << "Liczba przeciwnikow wynosi: " << enemies.size();
}

void EnemyManager::loadEnemiesFromFile(const std::string& filename, ProjectileManager& projectileManager) // zdefiniuj tê metodê w pliku Ÿród³owym klasy
{
	std::ifstream file(filename);

	if (!file.is_open())
	{
		std::cerr << "Nie mo¿na otworzyæ pliku " << filename << std::endl;
		return;
	}

	// pomiñ siatkê obiektów w pliku
	for (int j = 0; j < 8; ++j)
	{
		for (int i = 0; i < 15; ++i)
		{
			char objectType;
			file >> objectType; // odczytaj i zignoruj typ obiektu z pliku
		}
	}

	// odczytaj siatkê przeciwników w pliku
	for (int j = 0; j < 8; ++j)
	{
		for (int i = 0; i < 15; ++i)
		{
			char enemyType;
			file >> enemyType; // odczytaj typ przeciwnika z pliku
			if (enemyType == '1') // jeœli na danej pozycji jest dinozaur
			{
				sf::Vector2f enemyPosition(i * 128 + 64, j * 128 + 64); // oblicz pozycjê przeciwnika na podstawie indeksów tablicy
				addEnemy(enemyPosition, projectileManager, 100, EnemyType::Dinosaur); // dodaj przeciwnika na obliczonej pozycji
			}
			else if (enemyType == '2') // jeœli na danej pozycji jest ¿o³nierz
			{
				sf::Vector2f enemyPosition(i * 128 + 64, j * 128 + 64); // oblicz pozycjê przeciwnika na podstawie indeksów tablicy
				addEnemy(enemyPosition, projectileManager, 100, EnemyType::Soldier); // dodaj przeciwnika na obliczonej pozycji
			}
		}
	}
	file.close();
}

void EnemyManager::reset()
{
	enemies.clear();
}
