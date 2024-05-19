#pragma once
#include "Bullet.h"
class EnemyBullet :
    public Bullet
{
public:
    EnemyBullet(const sf::Vector2f& initialPosition = sf::Vector2f(0, 0), const sf::Vector2f& initialThrust = sf::Vector2f(0, 0));
    EnemyBullet(const Bullet& src);
    virtual bool init(const ContentManager& contentManager) override;
private:
    sf::IntRect enemyBullet = sf::IntRect(287, 106, 15, 4);
};