#pragma once
#include "AnimatedGameObject.h"
struct Inputs;
class Boss :
    public AnimatedGameObject
{
public:
    static const int BOSS_SPD;
    static const int BOSS_HP;
public:
    Boss();
    virtual bool init(const ContentManager& contentManager) override;

    bool update(float deltaT, const Inputs& inputs, int playerPosX);
private:
    int bossHP;
};

