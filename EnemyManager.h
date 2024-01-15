#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Enemy.h"
#include "Environment.h"
class ProjectileManager; // Forward declaration
class EnemyManager
{
public:
	void addEnemy(sf::Vector2f startPosition, ProjectileManager& projectileManager, int maxHealth, EnemyType type);
	void update(sf::Vector2f playerPosition);
	void draw(sf::RenderWindow& window);

	std::vector<Enemy>& getEnemies();
	void displayEnemies();
	void loadEnemiesFromFile(const std::string& filename, ProjectileManager& projectileManager);
	void reset();

private:
	std::vector<Enemy> enemies;
};