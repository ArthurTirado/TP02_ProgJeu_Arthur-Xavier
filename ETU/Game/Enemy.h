#pragma once
#include "AnimatedGameObject.h"
struct Inputs;
class Enemy :
    public AnimatedGameObject
{
public:
    static const int ENEMY_SPD;
    static const int ENEMY_HP;
public:
    Enemy();
    virtual bool init(const ContentManager& contentManager) override;

    bool update(float deltaT, const Inputs& inputs) override;
private:
    int enemyHP;
};

