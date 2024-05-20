#include "stdafx.h"
#include "GameMatch.h"

#include "game.h"

#pragma region Constantes

const float GameMatch::SCROLL_SPEED = -1.0f;
const int GameMatch::BULLETS_MAX = 20;
const float GameMatch::BULLET_RECOIL = 40;
const int GameMatch::CONTROLLER_DEAD_ZONE = 20;
const float GameMatch::GAMEPAD_SPEEDRATIO = 10.0f;
const float GameMatch::KEYBOARD_SPEED = 1.0f;


#pragma endregion


GameMatch::GameMatch()
    : Scene(SceneType::GAME_MATCH)
{

}

GameMatch::~GameMatch()
{

}
SceneType GameMatch::update()
{
    static int cptScrollBackground = 0;
    backgroundImage.setTextureRect(sf::IntRect(0, (int)(SCROLL_SPEED * cptScrollBackground++), Game::GAME_WIDTH, Game::GAME_HEIGHT));
    SceneType retval = getSceneType();
    //bullet logic
    if (recoil >= 0) {
        recoil -= Game::TIME_PER_FRAME;
    }
    if (inputs.fireBullet) {
        fireBullet();
    }
    for (Bullet& bullet : bullets)
    {
        if (bullet.isActive()) {
            if (bullet.update())
                bullet.deactivate();
        }
        player.update(inputs.moveFactorX, inputs.moveFactorY);

    }
    return getSceneType();
}

void GameMatch::draw(sf::RenderWindow& window) const
{
    window.draw(backgroundImage);
    player.draw(window);

    for (const Bullet& bullet : bullets)
    {
        //bullet.draw(window);
    }
}

bool GameMatch::init()
{
    if (!contentManager.loadContent())
        return false;
    backgroundImageTexture = contentManager.getBackgroundTexture();
    backgroundImageTexture.setRepeated(true);
    backgroundImage.setTexture(backgroundImageTexture);
   
    //Player
    player.initialize(contentManager, sf::Vector2f(Game::GAME_WIDTH / 4, Game::GAME_HEIGHT / 2 + 100));
    //Bullets
    for (int i = 0; i < BULLETS_MAX; ++i)
    {
        Bullet newBullet;
        newBullet.initialize(contentManager.getTitleScreenTexture(), sf::Vector2f(0, 0), contentManager.getPlayerGunSoundBuffer(), false);
        bullets.push_back(newBullet);
    }
    return true;
}

bool GameMatch::uninit()
{
    return true;
}

bool GameMatch::handleEvents(sf::RenderWindow& window)
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
            inputs.moveFactorX -= GameMatch::KEYBOARD_SPEED;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            inputs.moveFactorX += GameMatch::KEYBOARD_SPEED;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            inputs.moveFactorY -= GameMatch::KEYBOARD_SPEED;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            inputs.moveFactorY += GameMatch::KEYBOARD_SPEED;


        inputs.fireBullet = sf::Mouse::isButtonPressed(sf::Mouse::Left) && (recoil <= 0);
        sf::Vector2f playerPosition = player.getPosition();
    }
    return retval;
}
float GameMatch::handleControllerDeadZone(float analogInput)
{
    if (fabs(analogInput) < CONTROLLER_DEAD_ZONE)
    {
        analogInput = 0.0f;
    }
    return analogInput;
}
Bullet& GameMatch::getAvailableBullet()
{
    for (Bullet& b : bullets)
    {
        if (!b.isActive())
        {
            b.activate();
            return b;
        }
    }
    return bullets.front();
}

void GameMatch::fireBullet()
{
    if (recoil == 0) {
        Bullet& newBullet = getAvailableBullet();

        newBullet.setNormalBullet(contentManager.getMainCharacterTexture());
        newBullet.activate();
        newBullet.setPosition(player.getPosition());
        newBullet.setRotationAngleRadians(player.getRotationAngleInRadians());
        newBullet.playSound();
        recoil = BULLET_RECOIL;
    }
}
