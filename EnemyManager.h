#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Enemy.h"
class ProjectileManager; // Forward declaration

class EnemyManager
{
public:
	void addEnemy(sf::Vector2f startPosition, ProjectileManager& projectileManager, int maxHealth);
	void update(sf::Vector2f playerPosition);
	void draw(sf::RenderWindow& window);

	std::vector<Enemy>& getEnemies();

private:
	std::vector<Enemy> enemies;
};