#pragma once
#include "Scene.h"
#include "ContentManager.h"
#include "PlayerBullet.h"
#include "EnemyBullet.h"
#include "HealthBonus.h"
#include "WeaponBonus.h"
#include "Enemy.h"
#include "Boss.h"
#include "Canon.h"
#include "Player.h"
#include "Hud.h"
#include "Inputs.h"

class GameScene :
    public Scene
{
public:
    static const int NB_HP_BONUSES;
    static const int NB_WEAPON_BONUSES;
    static const int NB_BULLETS_PLAYER;
    static const int NB_BULLETS_ENEMIES;
    static const int NB_ENEMIES;
    static const int FIRE_BUTTON_PRESSED;
    static const int GAMEPAD_SPEEDRATIO;
    static const int KEYBOARD_SPEED;
public:
    GameScene();
    ~GameScene();
    virtual SceneType update() override;
    virtual void draw(sf::RenderWindow& window) const override;
    virtual bool init() override;
    virtual bool uninit() override;
    virtual bool handleEvents(sf::RenderWindow& window) override;
private:
    Enemy& getAvailableEnemy();
    HealthBonus& getAvailableHealthBonus();
    WeaponBonus& getAvailableWeaponBonus();

    float handleControllerDeadZone(float analogInput);
    sf::Sprite playerBulletSprite;
    sf::Sprite enemyBulletSprite;
    sf::Sprite background;
    ContentManager contentManager;
    std::list<PlayerBullet> playerBullets;
    std::list<EnemyBullet> enemyBullets;
    std::list<HealthBonus> healthBonuses;
    std::list<WeaponBonus> gunBonuses;
    std::list<Enemy> enemies;
    sf::Clock clock;
    Player player;
    Canon canon;
    Boss boss;
    Hud hud;
    Inputs inputs;
};

