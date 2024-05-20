#include "stdafx.h"
#include "WeaponBonus.h"
#include "ContentManager.h"


bool WeaponBonus::init(const ContentManager& contentManager)
{
	bonusSFXBuffer = contentManager.getHealthSoundBuffer();
	bonusSFX.setBuffer(bonusSFXBuffer);

	spriteHitbox.setSize(sf::Vector2f(13, 10));

	bonusSprite.setTexture(contentManager.getMiscTexture());
	bonusSprite.setTextureRect(bigGun);

	return true;
}

bool WeaponBonus::update(float deltaT, int dmgTaken)
{
	weaponHP -= dmgTaken;
	if (weaponHP <= 0) {
		deactivate();
	}
	if (!((int)deltaT % 20)) {
		bonusSprite.setTextureRect(smallGun);
	}
	else {
		bonusSprite.setTextureRect(bigGun);
	}
	return GameObject::update(deltaT);
	return false;
}
