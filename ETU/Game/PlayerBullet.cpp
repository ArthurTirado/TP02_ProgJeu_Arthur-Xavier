#include "stdafx.h"
#include "PlayerBullet.h"

PlayerBullet::PlayerBullet(const sf::Vector2f& initialPosition, const sf::Vector2f& initialThrust)
	: Bullet()
{
}

PlayerBullet::PlayerBullet(const Bullet& src)
{

}

bool PlayerBullet::init(const ContentManager& contentManager){
	sound.setBuffer(contentManager.getPlayerGunSoundBuffer());
	sprite.setTexture(contentManager.getMainCharacterTexture());
	sprite.setTextureRect(playerBullet);
	sprite.setRotation(BULLET_TEXTURE_ROTATION);
	return true;
}