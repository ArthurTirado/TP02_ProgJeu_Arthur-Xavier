#pragma once
#include "Bonus.h"
class WeaponBonus :
    public Bonus
{
public:
    virtual bool init(const ContentManager& contentManager) override;
    virtual bool update(float deltaT, int dmgTaken);
private:
    int weaponHP;
    sf::IntRect smallGun;
    sf::IntRect bigGun;
};
