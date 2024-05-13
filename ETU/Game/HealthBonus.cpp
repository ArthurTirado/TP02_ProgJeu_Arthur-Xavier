#include "stdafx.h"
#include "HealthBonus.h"
#include "ContentManager.h"


bool HealthBonus::init(const ContentManager& contentManager)
{
	bonusSFXBuffer = contentManager.getGunBonusSoundBuffer();
	bonusSFX.setBuffer(bonusSFXBuffer);
}

bool HealthBonus::update(float deltaT)
{
	return false;
}
