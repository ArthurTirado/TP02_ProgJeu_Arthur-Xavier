#pragma once
#include "AnimatedGameObject.h"
#include "Publisher.h"

struct Inputs;
class Boss :
    public AnimatedGameObject
{
public:
    static const int BOSS_SPD;
    static const int BOSS_HP;
    static const float MOVEMENT_TOLERANCE;
    static const float BOSS_SCALE;
    static const float INTRO_DURATION;
    static const float SLOW_SPD;
    static const float ENEMY_RECOIL;
    static const float LASER;

public:
    Boss();
    virtual bool init(const ContentManager& contentManager) override;
    bool update(float deltaT, const Inputs& inputs, int playerPosX);
    virtual void draw(sf::RenderWindow& window) const override;

    void hit(int hitPoints);
private:
    int bossHP;
    float descendTimer;
    sf::Sound enemyGunSound;
    float recoil;
    void updateHealthBar();


    sf::RectangleShape healthBarBackground;
    sf::RectangleShape healthBarForeground;
};

