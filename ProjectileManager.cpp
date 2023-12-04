#include "ProjectileManager.h"
#include "Projectile.h"


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

bool ProjectileManager::checkEnvironmentCollision(sf::FloatRect environmentBounds)
{
    // sprawdzanie kolizji z obiektem dla ka¿dego pocisku
    for (auto it = projectiles.begin(); it != projectiles.end();)
    {
        if (it->checkCollision(environmentBounds))
        {
            // pocisk trafi³ obiekt
            it = projectiles.erase(it);
            std::cout << "Pocisk trafi³ obiekt";
            return true;
        }
        else
        {
            // pocisk nie trafi³ obiektu
            ++it;
        }
    }

    // brak trafienia dla ¿adnego z pocisków
    return false;
}

bool ProjectileManager::checkEnemyCollision(sf::FloatRect enemyBounds)
{
    // sprawdzanie kolizji z obiektem dla ka¿dego pocisku
    for (auto it = projectiles.begin(); it != projectiles.end();)
    {
        if (it->checkCollision(enemyBounds))
        {
            // pocisk trafi³ obiekt
            it = projectiles.erase(it);
            std::cout << "Pocisk trafi³ obiekt";
            return true;
        }
        else
        {
            // pocisk nie trafi³ obiektu
            ++it;
        }
    }

    // brak trafienia dla ¿adnego z pocisków
    return false;
}