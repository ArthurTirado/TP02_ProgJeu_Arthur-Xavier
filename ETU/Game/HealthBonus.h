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
    sf::IntRect smallHeart;
    sf::IntRect bigHeart;
};

