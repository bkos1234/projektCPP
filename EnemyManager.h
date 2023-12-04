#pragma once

#include "Enemy.h"
#include <vector>
#include "ProjectileManager.h"

class EnemyManager
{
public:
	void addEnemy(sf::Vector2f startPosition, ProjectileManager& projectileManager, int maxHealth);
	void update(sf::Vector2f playerPosition);
	void draw(sf::RenderWindow& window);

private:
	std::vector<Enemy> enemies;
};