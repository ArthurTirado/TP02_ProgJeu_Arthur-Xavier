#include "stdafx.h"
#include "GameScene.h"
#include <iostream>
#include "game.h"
#include "Publisher.h"


#pragma region Constantes

const float GameScene::SCROLL_SPEED = -1.0f;
const int GameScene::CONTROLLER_DEAD_ZONE = 20;
const float GameScene::GAMEPAD_SPEEDRATIO = 10.0f;
const float GameScene::KEYBOARD_SPEED = 0.01f;
const float GameScene::TIME_PER_FRAME = 1.0f / (float)Game::FRAME_RATE;
const int GameScene::NB_BULLETS_PLAYER = 200;
const float GameScene::BULLET_RECOIL = 0.2f;
const int GameScene::NB_ENEMIES = 17;
const int GameScene::MIN_ENEMIES = 1;
const float GameScene::ENEMY_SPAWN_RATE = 1.5f;
const int GameScene::ENEMY_BULLET_DAMAGE = 100;
const int GameScene::ENEMY_POINTS = 100;
const int GameScene::BOSS_POINTS = 1000;









#pragma endregion


GameScene::GameScene()
    : Scene(SceneType::GAME_MATCH)
    , recoil(0)
    , nbEnemies(0)
    , enemyCooldown(0)
    , passToLeaderboard(false)
    ,points(0)
{

}

GameScene::~GameScene()
{

}
SceneType GameScene::update()
{
    if (passToLeaderboard) {
        return SceneType::LEADERBBOARD;
    }
    if (recoil > 0) {
        recoil -= TIME_PER_FRAME;
    }
    else {
        recoil = 0;
    }

    if (enemyCooldown > 0) {
        enemyCooldown -= TIME_PER_FRAME;
    }
    else {
        enemyCooldown = 0;
    }
    static int cptScrollBackground = 0;

    gameBackground.setTextureRect(sf::IntRect(0, (int)(SCROLL_SPEED * cptScrollBackground++), Game::GAME_WIDTH, Game::GAME_HEIGHT));
    SceneType retval = getSceneType();
    
    player.update(TIME_PER_FRAME,inputs);

    if (inputs.fireBullet) {
        firePlayerBullet();
    }

    for (PlayerBullet& e : enemyBullets) {
        if (e.update(TIME_PER_FRAME)) {
            e.deactivate();
        }
    }
    if ((enemyCooldown <= 0 && nbEnemies <= NB_ENEMIES) ||  nbEnemies < MIN_ENEMIES) {
        spawnEnemy();
    }
    //hud
    hud.update(points, player.getHealth(), 0);
    //bullet
    for (PlayerBullet& bullet : playerBullets)
    {
        if (bullet.isActive()) {
            if (bullet.update(TIME_PER_FRAME))
                bullet.deactivate();
            for (Enemy& enemy : enemyPool)
            {
                if (bullet.getGlobalBounds().intersects(enemy.getGlobalBounds()) && enemy.isActive())
                {
                    bullet.deactivate();
                    enemy.hit(1);
                    break;
                }
            }
            if (bullet.getGlobalBounds().intersects(boss.getGlobalBounds()) && boss.isActive())
            {
                bullet.deactivate();
                boss.hit(1);
                break;
            }
        }
    }
    for (PlayerBullet& bullet : enemyBullets)
    {
        if (bullet.isActive()) {
            if (bullet.update(TIME_PER_FRAME))
                bullet.deactivate();
            if (bullet.getGlobalBounds().intersects(player.getGlobalBounds()) && player.isActive())
            {
                bullet.deactivate();
                player.hit(ENEMY_BULLET_DAMAGE);
                break;
            }
        }
    }
    for (Enemy& enemy : enemyPool)
    {

        if (enemy.isActive()) {
            enemy.update(TIME_PER_FRAME, inputs);
            if (player.getGlobalBounds().intersects(enemy.getGlobalBounds()) && enemy.isActive())
            {
                enemy.hit(Enemy::ENEMY_HP);
                player.hit(ENEMY_BULLET_DAMAGE);
            }
        }
    }
    boss.update(TIME_PER_FRAME, inputs, player.getPosition().x);
    if (player.getGlobalBounds().intersects(boss.getGlobalBounds()) && boss.isActive())
    {
        player.hit(player.getHealth());
    }
    if (points == NB_ENEMIES * ENEMY_POINTS) {
        boss.activate();
    }
    return getSceneType();
}

void GameScene::draw(sf::RenderWindow& window) const
{
    window.draw(gameBackground);
    if (player.isActive()) {
          window.draw(player);
    }
    for (const PlayerBullet& b : playerBullets) {
        b.draw(window);
    }
    for (const PlayerBullet& b : enemyBullets) {
        b.draw(window);
    }
    for (const Enemy& enemy : enemyPool) {
        enemy.draw(window);
    }
    hud.draw(window);
    if (boss.isActive()) {
        boss.draw(window);
    }

}

bool GameScene::init()
{
    if (!contentManager.loadContent())
        return false;

    gameBackgroundTexture = contentManager.getBackgroundTexture();
    gameBackgroundTexture.setRepeated(true);
    gameBackground.setTexture(gameBackgroundTexture);
    player.init(contentManager);
    //hud
    hud.initialize(contentManager);
    //PlayerBullets
    for (int i = 0; i < NB_BULLETS_PLAYER; i++)
    {
        PlayerBullet newBullet;
        newBullet.init(contentManager, true);
        playerBullets.push_back(newBullet);
    }

    //EnemyBullets        
    for (int i = 0; i < NB_BULLETS_PLAYER; i++)
    {
        PlayerBullet newBullet;
        newBullet.init(contentManager, false);
        enemyBullets.push_back(newBullet);
    }


    //Enemy
    nbEnemies = 0;
    enemyCooldown = 0;
   for (int i = 0; i < NB_ENEMIES; i++)
    {
        Enemy newEnemy;
        newEnemy.init(contentManager);
        enemyPool.push_back(newEnemy);
    }
   //Boss
   boss.init(contentManager);
    Publisher::addSubscriber(*this, Event::ENEMY_SHOOT);
    Publisher::addSubscriber(*this, Event::ENEMY_KILLED);
    Publisher::addSubscriber(*this, Event::BOSS_SHOOT);
    Publisher::addSubscriber(*this, Event::BOSS_KILLED);




    return true;
}

bool GameScene::uninit()
{
    return true;
}

bool GameScene::handleEvents(sf::RenderWindow& window)
{
    bool retval = false;
    sf::Event event;
    while (window.pollEvent(event))
    {
        //x sur la fenêtre
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
            retval = true;
        }
        /*else if (event.type == sf::Event::KeyPressed) {
            retval = true;
        }*/
    }
    if (sf::Joystick::isConnected(0))
    {
        inputs.moveFactorX = handleControllerDeadZone(sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y)) / GAMEPAD_SPEEDRATIO;
        inputs.moveFactorY = handleControllerDeadZone(sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X)) / GAMEPAD_SPEEDRATIO;

        inputs.fireBullet = sf::Joystick::isButtonPressed(0, 6) && (recoil <= 0);


    }
    else
    {
        inputs.moveFactorX = inputs.moveFactorY = 0.0f;


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            inputs.moveFactorX -= GameScene::KEYBOARD_SPEED;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            inputs.moveFactorX += GameScene::KEYBOARD_SPEED;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            inputs.moveFactorY += GameScene::KEYBOARD_SPEED;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            inputs.moveFactorY -= GameScene::KEYBOARD_SPEED;


        inputs.fireBullet = sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (recoil <= 0);
    }
    return retval;
}
float GameScene::handleControllerDeadZone(float analogInput)
{
    if (fabs(analogInput) < CONTROLLER_DEAD_ZONE)
    {
        analogInput = 0.0f;
    }
    return analogInput;
}
PlayerBullet& GameScene::getAvailableBulletFromList(std::list<PlayerBullet>& bulletList)
{
    for (PlayerBullet& b : bulletList)
    {
        if (!b.isActive())
        {
            b.activate();
            return b;
        }
    }
    return bulletList.front();
}

void GameScene::firePlayerBullet()
{
    if (recoil == 0) {
        PlayerBullet& bullet1 = getAvailableBulletFromList(playerBullets);
        bullet1.activate();
        bullet1.setPosition(player.getPosition().x + Player::CANNON_POSITION, player.getPosition().y);
        PlayerBullet& bullet2 = getAvailableBulletFromList(playerBullets);
        bullet2.activate();
        bullet2.setPosition(player.getPosition().x - Player::CANNON_POSITION, player.getPosition().y);
        player.shoot();
        recoil = BULLET_RECOIL;
    }
}

Enemy& GameScene::getAvailableEnemy()
{
    for (Enemy& enemy : enemyPool)
    {
        if (!enemy.isActive())
        {
            enemy.activate();
            return enemy;
        }
    }
    Enemy newEnemy;
    newEnemy.init(contentManager);
    enemyPool.push_back(newEnemy);
    return enemyPool.front();
}

void GameScene::spawnEnemy()
{
    Enemy& enemy = getAvailableEnemy();
    enemy.activate();
    enemy.setPosition(Game::GAME_WIDTH/2, Game::GAME_HEIGHT/2);
    enemy.setPosition(rand() % Game::GAME_WIDTH - enemy.getGlobalBounds().width, 0);
    nbEnemies++;
    enemyCooldown = ENEMY_SPAWN_RATE;
}


void GameScene::fireEnemyBullet(sf::Vector2f pos, float bulletThreshold)
{
    PlayerBullet& bullet1 = getAvailableBulletFromList(enemyBullets);
    bullet1.activate();
    bullet1.setPosition(pos.x + bulletThreshold, pos.y);
    bullet1.setRotation(-90);  // Rotate the bullet 180 degrees

    PlayerBullet& bullet2 = getAvailableBulletFromList(enemyBullets);
    bullet2.activate();
    bullet2.setPosition(pos.x - bulletThreshold, pos.y);
    bullet2.setRotation(-90);  // Rotate the bullet 180 degrees
}

void GameScene::notify(Event event, const void* data)
{
    switch (event)
    {
    case Event::NONE:
        break;
    case Event::ENEMY_SHOOT:
    {
        const Enemy* shootingEnemy = static_cast<const Enemy*>(data);
        fireEnemyBullet(shootingEnemy->getPosition(), Enemy::CANNON_POSITION);
        break;
    }
    case Event::BOSS_SHOOT:
    {
        const Boss* shootingEnemy = static_cast<const Boss*>(data);
        fireEnemyBullet(shootingEnemy->getPosition(), Boss::LASER);
        break;
    }
    case Event::ENEMY_KILLED: 
    {
        points += ENEMY_POINTS;
        break;
    }
    case Event::GAME_OVER:
    {
        passToLeaderboard = true;
        break;
    }
    case Event::BOSS_KILLED:
    {
        passToLeaderboard = true;
        points += BOSS_POINTS;
        break;
    }
    default:
        break;
    }

}