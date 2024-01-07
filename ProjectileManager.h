#pragma once
#include <vector>
#include "Projectile.h"
#include "Environment.h" // musi byc zeby dzialalo checkCollisions
#include "Enemy.h"

class ProjectileManager
{
public:
    void addProjectile(sf::Vector2f startPosition, sf::Vector2f targetPosition, float speed, const std::string& texturePath, bool isPlayerProjectile, int damage);
    void update();
    void draw(sf::RenderWindow& window);
    bool checkPlayerCollision(sf::FloatRect playerBounds);

    void checkCollisions(Environment& environment);

    bool checkEnemyCollisions(std::vector<Enemy>& enemies);

private:
    std::vector<Projectile> projectiles;
};