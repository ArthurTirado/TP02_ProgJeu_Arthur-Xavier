#include "stdafx.h"
#include "WeaponBonus.h"
#include "ContentManager.h"


bool WeaponBonus::init(const ContentManager& contentManager)
{
	bonusSFXBuffer = contentManager.getHealthSoundBuffer();
	bonusSFX.setBuffer(bonusSFXBuffer);
}

bool WeaponBonus::update(float deltaT, int dmgTaken)
{
	if (weaponHP <= 0) {
		deactivate();
	}
	return false;
}
