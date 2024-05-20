#pragma once
#include "AnimatedGameObject.h"
struct Inputs;
class Player :
    public AnimatedGameObject
{
public:
    static const int PLAYER_HP;
    static const int PLAYER_SPD;
public:
    Player();
    virtual bool init(const ContentManager& contentManager) override;

    bool update(float deltaT, const Inputs& inputs) override;
private:
    int playerHP;
    void stayInbounds();
};

