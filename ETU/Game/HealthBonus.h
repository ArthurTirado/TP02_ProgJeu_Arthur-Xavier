#pragma once
#include "Bonus.h"
class HealthBonus :
    public Bonus
{
public:
    static const unsigned int BONUS_HEALTH_POINTS;
    virtual bool init(const ContentManager& contentManager) override;
    virtual bool update(float deltaT) override;
private:
    sf::IntRect smallHeart = sf::IntRect(315, 109, 6, 6);
    sf::IntRect bigHeart = sf::IntRect(229, 64, 10, 9);
};
