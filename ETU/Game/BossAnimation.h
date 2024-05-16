#pragma once
#include "CyclicAnimation.h"
#include "ContentManager.h"
class BossAnimation :
    public CyclicAnimation
{
public:
    static const float CAN_SHOOT;
public:
    BossAnimation(sf::Sprite& s);
    virtual void update(float deltaT, const Inputs& inputs) override;
    virtual bool init(const ContentManager& contentManager) override;
    bool canShoot();
private:
    sf::RectangleShape hitbox;
    sf::IntRect opening1;
    sf::IntRect opening2;
    sf::IntRect opening3;
    sf::IntRect opening4;
    sf::IntRect opening5;
    sf::IntRect opening6;
    sf::IntRect fire1;
    sf::IntRect fire2;
    sf::IntRect fire3;
    sf::IntRect fire4;
    sf::IntRect fire5;
    sf::IntRect fire6;
};

