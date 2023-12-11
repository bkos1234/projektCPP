#include "EnemyManager.h"
#include "Enemy.h"
#include "ProjectileManager.h"
#include <algorithm>

void EnemyManager::addEnemy(sf::Vector2f startPosition, ProjectileManager& projectileManager, int maxHealth)
{
	enemies.emplace_back(startPosition, projectileManager, maxHealth);
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