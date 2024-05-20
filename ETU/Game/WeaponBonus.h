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
    sf::IntRect smallGun = sf::IntRect(336, 109, 6, 6);
    sf::IntRect bigGun = sf::IntRect(311, 64, 13, 10);
};