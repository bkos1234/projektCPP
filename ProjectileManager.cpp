#include "ProjectileManager.h"

void ProjectileManager::addProjectile(sf::Vector2f startPosition, sf::Vector2f targetPosition, float speed, const std::string& texturePath, bool isPlayerProjectile)
{
	projectiles.emplace_back(startPosition, targetPosition, speed, texturePath, isPlayerProjectile);
}

void ProjectileManager::update()
{
	for (auto& projectile : projectiles)
	{
		projectile.update();
	}
}

void ProjectileManager::draw(sf::RenderWindow& window)
{
	for (auto& projectile : projectiles)
	{
		projectile.draw(window);
	}
}

bool ProjectileManager::checkPlayerCollision(sf::FloatRect playerBounds)
{
    // sprawdzanie kolizji z graczem dla ka¿dego pocisku
    for (auto it = projectiles.begin(); it != projectiles.end();)
    {
        if (!it->isPlayerProjectile && it->checkCollision(playerBounds))
        {
            // pocisk trafi³ gracza
            it = projectiles.erase(it);
            return true;
        }
        else
        {
            // pocisk nie trafi³ gracza
            ++it;
        }
    }

    // brak trafienia dla ¿adnego z pocisków
    return false;
}

void ProjectileManager::checkCollisions(Environment& environment) {
    for (auto it = projectiles.begin(); it != projectiles.end();) {
        bool collisionDetected = false;

        // sprawdzanie kolizji z obiektami drzew
        for (const auto& treeBox : environment.treeCollisionBoxes) {
            if (it->checkCollision(treeBox)) {
                collisionDetected = true;
                break;
            }
        }

        // sprawdzanie kolizji z obiektami kamieni
        for (const auto& stoneBox : environment.stoneCollisionBoxes) {
            if (it->checkCollision(stoneBox)) {
                collisionDetected = true;
                break;
            }
        }

        // usuwanie pocisku, jeœli wykryto kolizjê z obiektem
        if (collisionDetected) {
            it = projectiles.erase(it);
        }
        else {
            ++it;
        }
    }
}

bool ProjectileManager::checkEnemyCollisions(std::vector<Enemy>& enemies) {
    bool hitDetected = false;
    for (auto it = projectiles.begin(); it != projectiles.end();) {
        bool collisionDetected = false;

        for (auto enemyIt = enemies.begin(); enemyIt != enemies.end(); ++enemyIt) {
            if (it->isPlayerProjectile && it->checkCollision(enemyIt->getBounds())) {
                // Pocisk trafi³ przeciwnika
                enemyIt->decreaseHealth(25); // Zmniejsz zdrowie przeciwnika
                collisionDetected = true;
                hitDetected = true;
                break;
            }
        }

        if (collisionDetected) {
            // Usuwanie pocisku, jeœli wykryto kolizjê z przeciwnikiem
            it = projectiles.erase(it);
        }
        else {
            ++it;
        }
    }
    return hitDetected;
}
