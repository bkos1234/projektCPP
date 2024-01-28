#pragma once
#include <SFML/Graphics.hpp>
class ProjectileManager; // Forward declaration

enum class EnemyType
{
	Dinosaur,
	Soldier,
	Steve,
	Dog,
	Dog2
};

class Enemy
{
public:
	Enemy(sf::Vector2f startPosition, ProjectileManager& projectileManager, int maxHealth, EnemyType type);

	void update(sf::Vector2f playerPosition);
	void draw(sf::RenderWindow& window) const;

	bool canShoot() const;
	void resetShootTimer();
	void shoot(sf::Vector2f playerPosition);

	void facePlayer(sf::Vector2f playerPosition);

	void decreaseHealth(int value);

	sf::FloatRect getBounds() const;

	bool isDead() const;

private:
	sf::Texture texture;
	sf::Texture texture2;
	sf::Texture texture3;
	sf::Sprite sprite;
	sf::Clock shootTimer;
	float shootCooldown;
	bool canShootFlag;
	ProjectileManager& projectileManager;
	sf::Vector2f mouthOffset;
	int health;
	std::string projectileTexture;
	float projectileSpeed;
	int projectileDamage;
	EnemyType type;
};