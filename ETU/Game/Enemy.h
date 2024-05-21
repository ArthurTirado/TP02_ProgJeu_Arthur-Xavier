#pragma once
#include "AnimatedGameObject.h"
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


public:
    Enemy();
    Enemy(const Enemy& src);
    virtual bool init(const ContentManager& contentManager) override;

    bool update(float deltaT, const Inputs& inputs) override; 
private:
    int enemyHP;
};

