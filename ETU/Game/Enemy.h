#pragma once
#include "AnimatedGameObject.h"
#include "EnemyAnimation.h"
#include "Subscriber.h"
struct Inputs;
class Enemy :
    public AnimatedGameObject
{
public:
    static const float ENEMY_SPD;
    static const int ENEMY_HP;
    static const float CANNON_POSITION;
    static const float ENEMY_SCALE_X;
    static const float ENEMY_SCALE_Y;
    static const float ENEMY_RECOIL;


public:
    Enemy();
    Enemy(const Enemy& src);
    virtual bool init(const ContentManager& contentManager) override;
    void hit(int hitPoints);

    bool update(float deltaT, const Inputs& inputs) override; 
private:
    int enemyHP;
    float recoil;
    sf::Sound enemyGunSound;
    sf::Sound enemyDeathSound;
};

