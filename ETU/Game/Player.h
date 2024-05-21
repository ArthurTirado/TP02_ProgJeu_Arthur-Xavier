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
    static const float INVINCIBILITY_DURATION;
    static const float GAME_MARGIN;

public:
    Player();
    virtual bool init(const ContentManager& contentManager) override;
    bool update(float deltaT, const Inputs& inputs) override;
    void shoot();
    void hit(int hitPoints);
    int getHealth() const;
private:
    int playerHP;
    float invincibilityCountdown;
    sf::Sound shotSound;
    void stayInbounds();
};

