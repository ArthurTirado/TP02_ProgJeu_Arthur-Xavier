#include "stdafx.h"
#include "EnemyBullet.h"

EnemyBullet::EnemyBullet(const sf::Vector2f& initialPosition, const sf::Vector2f& initialThrust)
	: Bullet()
{
}

EnemyBullet::EnemyBullet(const Bullet& src)
{
}

bool EnemyBullet::init(const ContentManager& contentManager)
{
	sound.setBuffer(contentManager.getPlayerGunSoundBuffer());
	sprite.setTexture(contentManager.getMainCharacterTexture());
	sprite.setTextureRect(enemyBullet);
	sprite.setRotation(BULLET_TEXTURE_ROTATION);
	return true;
}
