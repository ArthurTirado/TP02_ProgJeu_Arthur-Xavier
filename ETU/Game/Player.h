#pragma once
#include "AnimatedGameObject.h"
struct Inputs;
class Player :
    public AnimatedGameObject
{
public:
    static const int PLAYER_HP;
    static const int PLAYER_SPD;
    static const float PLAYER_SCALE;
    static const float CANNON_POSITION;

public:
    Player();
    virtual bool init(const ContentManager& contentManager) override;
    bool update(float deltaT, const Inputs& inputs) override;
    void shoot();
private:
    int playerHP;
    sf::Sound shotSound;
    void stayInbounds();
};

