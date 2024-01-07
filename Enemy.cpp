#include "Enemy.h"
#include "ProjectileManager.h"

Enemy::Enemy(sf::Vector2f startPosition, ProjectileManager& projectileManager, int maxHealth, EnemyType type) : projectileManager(projectileManager), health(maxHealth), type(type)
{
	switch (type)
	{
	case EnemyType::Dinosaur: // dinozaur
		texture.loadFromFile("dinosaur.png");
		texture2.loadFromFile("dinosaur_angry.png");
		texture3.loadFromFile("dinosaur_dead.png");
		projectileTexture = "fireball.png"; // tekstura pocisku
		projectileSpeed = 5.0; // prêdkoœæ pocisku
		projectileDamage = 10; // obra¿enia pocisku
		shootCooldown = 2.0; // odstêp czasowy miêdzy pociskami
		break;
	case EnemyType::Soldier: // nietoperz
		texture.loadFromFile("soldier.png");
		texture2.loadFromFile("soldier.png");
		texture3.loadFromFile("soldier_dead.png");
		projectileTexture = "bullet.png"; // tekstura pocisku
		projectileSpeed = 10.0; // prêdkoœæ pocisku
		projectileDamage = 5; // obra¿enia pocisku
		shootCooldown = 1.0; // odstêp czasowy miêdzy pociskami
		break;
	}
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setPosition(startPosition);
	sprite.setOrigin(sprite.getLocalBounds().width / 2.0f, sprite.getLocalBounds().height / 2.0f);

	canShootFlag = true;
}

void Enemy::update(sf::Vector2f playerPosition)
{	
	if (std::abs(playerPosition.x - sprite.getPosition().x) < 400.0f && !(isDead()))
	{
		facePlayer(playerPosition);
		sprite.setTexture(texture2);
	}
	else
	{
		sprite.setTexture(texture);
	}
	// strzelanie co shootColdown sekund
	if (canShoot() && std::abs(playerPosition.x - sprite.getPosition().x) < 400.0f) {
		facePlayer(playerPosition);
		shoot(playerPosition);
		resetShootTimer();
	}

	if (isDead())
	{
		sprite.setTexture(texture3);
	}
}

void Enemy::draw(sf::RenderWindow& window) const
{
	window.draw(sprite);
}

bool Enemy::canShoot() const
{
	return canShootFlag && shootTimer.getElapsedTime().asSeconds() >= shootCooldown && !(isDead());
}

void Enemy::resetShootTimer()
{
	shootTimer.restart();
}

void Enemy::shoot(sf::Vector2f playerPosition)
{
	sf::Vector2f textureSize(sprite.getTexture()->getSize());
	sf::Vector2f mouthPosition = sprite.getPosition() + mouthOffset;
	projectileManager.addProjectile(sprite.getPosition() + mouthOffset, playerPosition, projectileSpeed, projectileTexture, false, projectileDamage);

	std::cout << "Przeciwnik strzela!\n";
}

void Enemy::facePlayer(sf::Vector2f playerPosition)
{
	float angle = 0.0f;
	if (playerPosition.x < sprite.getPosition().x) {
		// Patrzy w lewo
		angle = 0.0f;
		sprite.setScale(1, 1);
		mouthOffset = sf::Vector2f(-57, -33);
	}
	else {
		// Patrzy w prawo
		angle = 180.0f;
		sprite.setScale(1, -1);
		mouthOffset = sf::Vector2f(57, -33);
	}

	sprite.setRotation(angle);
}

void Enemy::decreaseHealth(int value)
{
	health -= value;
	if (health < 0)
	{
		health = 0;
	}
}

sf::FloatRect Enemy::getBounds() const {
	return sprite.getGlobalBounds();
}

bool Enemy::isDead() const
{
	return health == 0;
}