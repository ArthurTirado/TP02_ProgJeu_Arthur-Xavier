#pragma once
#include "Bullet.h"
class PlayerBullet :
    public Bullet
{
public:
    PlayerBullet(const sf::Vector2f& initialPosition = sf::Vector2f(0, 0), const sf::Vector2f& initialThrust = sf::Vector2f(0, 0));
    PlayerBullet(const Bullet& src);
    virtual bool init(const ContentManager& contentManager) override;
private:
    sf::IntRect playerBullet = sf::IntRect(264, 106, 15, 4);
};

