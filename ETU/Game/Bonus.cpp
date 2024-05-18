#include "stdafx.h"
#include "Bonus.h"
#include "ContentManager.h"

Bonus::Bonus()
{
}

bool Bonus::update(float deltaT)
{
	return false;
}

bool Bonus::init(const ContentManager& contentManager)
{
	return false;
}

void Bonus::playSound()
{
	bonusSFX.play();
}

