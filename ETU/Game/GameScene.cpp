#include "stdafx.h"
#include "GameScene.h"
#include <iostream>
#include "game.h"

#pragma region Constantes

const float GameScene::SCROLL_SPEED = -1.0f;
const int GameScene::CONTROLLER_DEAD_ZONE = 20;
const float GameScene::GAMEPAD_SPEEDRATIO = 10.0f;
const float GameScene::KEYBOARD_SPEED = 0.01f;
const float GameScene::TIME_PER_FRAME = 1.0f / (float)Game::FRAME_RATE;
const int GameScene::NB_BULLETS_PLAYER = 200;
const float GameScene::BULLET_RECOIL = 0.2f;





#pragma endregion


GameScene::GameScene()
    : Scene(SceneType::GAME_MATCH)
    , recoil(0)
{

}

GameScene::~GameScene()
{

}
SceneType GameScene::update()
{
    static int cptScrollBackground = 0;
    gameBackground.setTextureRect(sf::IntRect(0, (int)(SCROLL_SPEED * cptScrollBackground++), Game::GAME_WIDTH, Game::GAME_HEIGHT));
    SceneType retval = getSceneType();
    
    player.update(TIME_PER_FRAME,inputs);

    //bullet
    if (recoil > 0) {
        recoil -= TIME_PER_FRAME;
    }
    else {
        recoil = 0;
    }
    if (inputs.fireBullet) {
        firePlayerBullet();
    }
    std::cout << recoil;

    for (PlayerBullet& p : playerBullets) {
        if (p.update(TIME_PER_FRAME)) {
            p.deactivate();
        }
    }

    return getSceneType();
}

void GameScene::draw(sf::RenderWindow& window) const
{
    //window.draw(bulletTest);
    window.draw(gameBackground);
    window.draw(player);

    for (const PlayerBullet& b : playerBullets) {
        b.draw(window);
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
    //Music
    if (!gameMusic.openFromFile("Assets\\Music\\Title\\SgMusic.ogg"))
        return false;
    gameMusic.setLoop(true);
    gameMusic.play();
    //PlayerBullets
    // Balles joueur
    for (int i = 0; i < NB_BULLETS_PLAYER; i++)
    {
        PlayerBullet newBullet;
        newBullet.init(contentManager);
        newBullet.setPosition(player.getPosition());
        playerBullets.push_back(newBullet);
    }


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


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            inputs.moveFactorX -= GameScene::KEYBOARD_SPEED;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            inputs.moveFactorX += GameScene::KEYBOARD_SPEED;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            inputs.moveFactorY += GameScene::KEYBOARD_SPEED;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            inputs.moveFactorY -= GameScene::KEYBOARD_SPEED;


        inputs.fireBullet = sf::Mouse::isButtonPressed(sf::Mouse::Left) && (recoil <= 0);
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
PlayerBullet& GameScene::getAvailablePlayerBullet()
{
    for (PlayerBullet& b : playerBullets)
    {
        if (!b.isActive())
        {
            b.activate();
            return b;
        }
    }
    return playerBullets.front();
}

void GameScene::firePlayerBullet()
{
    if (recoil == 0) {
        PlayerBullet& bullet1 = getAvailablePlayerBullet();
        bullet1.activate();
        bullet1.setPosition(player.getPosition().x + Player::CANNON_POSITION, player.getPosition().y);
        PlayerBullet& bullet2 = getAvailablePlayerBullet();
        bullet2.activate();
        bullet2.setPosition(player.getPosition().x - Player::CANNON_POSITION, player.getPosition().y);
        recoil = BULLET_RECOIL;
    }
}
