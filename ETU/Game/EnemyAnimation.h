#pragma once
#include "CyclicAnimation.h"
#include "ContentManager.h"
class EnemyAnimation :
    public CyclicAnimation
{
public:
    static const float CAN_SHOOT;
public:
    EnemyAnimation(sf::Sprite& s);
    bool canShoot();
    virtual void update(float deltaT, const Inputs& inputs) override;
    virtual bool init(const ContentManager& contentManager) override;
private:
    sf::RectangleShape hitbox;
    sf::IntRect opening1;
    sf::IntRect opening2;
    sf::IntRect opening3;
    sf::IntRect opening4;
    sf::IntRect opening5;
    sf::IntRect opening6;
    sf::IntRect opening7;
    sf::IntRect opening8;
    sf::IntRect opening9;
    sf::IntRect opening10;
    sf::IntRect opening11;
    sf::IntRect opening12;
    sf::IntRect opening13;
    sf::IntRect fire1;
    sf::IntRect fire2;
    sf::IntRect fire3;
    sf::IntRect fire4;
    sf::IntRect fire5;
};

