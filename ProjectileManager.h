#pragma once

#include "Projectile.h"
#include <vector>

class ProjectileManager
{
public:
    void addProjectile(sf::Vector2f startPosition, sf::Vector2f targetPosition, float speed, const std::string& texturePath, bool isPlayerProjectile);
    void update();
    void draw(sf::RenderWindow& window);
    bool checkPlayerCollision(sf::FloatRect playerBounds);

    bool checkEnvironmentCollision(sf::FloatRect environmentBounds);

    bool checkEnemyCollision(sf::FloatRect enemyBounds);

private:
    std::vector<Projectile> projectiles;
};