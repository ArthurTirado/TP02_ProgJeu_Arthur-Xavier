#include "stdafx.h"
#include "HealthBonus.h"
#include "ContentManager.h"


bool HealthBonus::init(const ContentManager& contentManager)
{
	bonusSFXBuffer = contentManager.getGunBonusSoundBuffer();
	bonusSFX.setBuffer(bonusSFXBuffer);

	bigHeart = sf::IntRect(229, 64, 10, 9);
	smallHeart = sf::IntRect(315, 109, 6, 6);

	spriteHitbox.setSize(sf::Vector2f(10, 9));

	bonusSprite.setTexture(contentManager.getMiscTexture());
	bonusSprite.setTextureRect(bigHeart);
}

bool HealthBonus::update(float deltaT)
{
	if (!((int)deltaT % 20)) {
		bonusSprite.setTextureRect(smallHeart);
	}
	else {
		bonusSprite.setTextureRect(bigHeart);
	}
	return GameObject::update(deltaT);
}
