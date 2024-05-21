#pragma once
#include "Scene.h"
#include "ContentManager.h"
#include "Inputs.h"
#include "Inputs.h"
#include "Player.h"
#include "PlayerBullet.h"
#include "Enemy.h"
#include "Subscriber.h"



class GameScene :
    public Scene, public Subscriber
{
public:

    static const float SCROLL_SPEED;
    static const int CONTROLLER_DEAD_ZONE;
    static const float GAMEPAD_SPEEDRATIO;
    static const float KEYBOARD_SPEED;
    static const float TIME_PER_FRAME;
    static const int NB_BULLETS_PLAYER;
    static const float BULLET_RECOIL;
    static const int NB_ENEMIES;
    static const int MIN_ENEMIES;
    static const float ENEMY_SPAWN_RATE;
    static const int ENEMY_BULLET_DAMAGE;



    // Héritées via Scene
    GameScene();
    ~GameScene();
    virtual SceneType update() override;
    virtual void draw(sf::RenderWindow& window) const override;
    virtual bool init() override;
    virtual bool uninit() override;
    virtual bool handleEvents(sf::RenderWindow& window) override;
    float handleControllerDeadZone(float analogInput);
private:
    sf::Texture gameBackgroundTexture;
    sf::Sprite gameBackground;
    sf::Music gameMusic;
    ContentManager contentManager;
    bool passToLeaderboard;
    Inputs inputs;
    float recoil;
    Player player;

    std::list<PlayerBullet> playerBullets;
    void firePlayerBullet();
    PlayerBullet& getAvailableBulletFromList(std::list<PlayerBullet>& bulletList);

    std::list<Enemy> enemyPool;
    void spawnEnemy();
    Enemy& getAvailableEnemy();
    float enemyCooldown;
    int nbEnemies;
    virtual void notify(Event event, const void* data) override;

    std::list<PlayerBullet> enemyBullets;
    void fireEnemyBullet(sf::Vector2f pos);};
