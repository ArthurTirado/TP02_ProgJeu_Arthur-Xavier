#include "stdafx.h"
#include "GameScene.h"

#include "game.h"
#include "Inputs.cpp"

const int GameScene::NB_HP_BONUSES = 5;
const int GameScene::NB_WEAPON_BONUSES = 3;
const int GameScene::NB_BULLETS_PLAYER = 150;
const int GameScene::NB_BULLETS_ENEMIES = 100;
const int GameScene::NB_ENEMIES = 50;
const int GameScene::FIRE_BUTTON_PRESSED = 1;
const int GameScene::GAMEPAD_SPEEDRATIO = 20;
const int GameScene::KEYBOARD_SPEED = 5;


GameScene::GameScene()
	: Scene(SceneType::GAME_SCENE)
{

}

GameScene::~GameScene()
{
}

SceneType GameScene::update()
{
	SceneType retval = getSceneType();
	float elapsedTime = clock.getElapsedTime().asSeconds();

	player.update(elapsedTime, inputs);

	for (PlayerBullet& p : playerBullets) {
		if (p.update(elapsedTime)) {
			p.deactivate();
		}
	}

	for (EnemyBullet& e : enemyBullets) {
		if (e.update(elapsedTime)) {
			e.deactivate();
		}
	}

	if (inputs.fireBullet) {
		inputs.fireBullet = false;
	}
	return SceneType();
}

void GameScene::draw(sf::RenderWindow& window) const
{
	window.draw(background);

	for (const PlayerBullet& b : playerBullets) {
		b.draw(window);
	}

	for (const EnemyBullet& b : enemyBullets) {
		b.draw(window);
	}

	for (const Enemy& e : enemies) {
		e.draw(window);
	}

	for (const HealthBonus& hb : healthBonuses) {
		hb.draw(window);
	}

	for (const WeaponBonus& wb : gunBonuses) {
		wb.draw(window);
	}
	player.draw(window);
	canon.draw(window);
	boss.draw(window);
	hud.draw(window);
}

bool GameScene::init()
{
    inputs.reset();
	// Bonus HP
	for (int i = 0; i < NB_HP_BONUSES; i++) {
		HealthBonus newBonus;
		newBonus.init(contentManager);
		healthBonuses.push_back(newBonus);
	}

	// Bonus arme
	for (int i = 0; i < NB_WEAPON_BONUSES; i++) {
		WeaponBonus newBonus;
		newBonus.init(contentManager);
		gunBonuses.push_back(newBonus);
	}

	// Balles joueur
	for (int i = 0; i < NB_BULLETS_PLAYER; i++)
	{
		PlayerBullet newBullet;
		newBullet.init(contentManager);
		playerBullets.push_back(newBullet);
	}

	//Balles ennemis
	for (int i = 0; i < NB_BULLETS_ENEMIES; i++)
	{
		EnemyBullet newBullet;
		newBullet.init(contentManager);
		enemyBullets.push_back(newBullet);
	}
}

bool GameScene::uninit()
{
	return false;
}

bool GameScene::handleEvents(sf::RenderWindow& window)
{
    sf::Event event;
    //On passe l'événement en référence et celui-ci est chargé du dernier événement reçu!
    while (window.pollEvent(event))
    {
        //x sur la fenêtre
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
    //Si le Gamepad est connecté, on l'utilise pour sélectionner et déplacer les vaisseaux
    if (sf::Joystick::isConnected(0))
    {
        inputs.moveFactorY = handleControllerDeadZone(sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y)) / GAMEPAD_SPEEDRATIO;
        inputs.moveFactorX = handleControllerDeadZone(sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X)) / GAMEPAD_SPEEDRATIO;

        if (sf::Joystick::isButtonPressed(0, FIRE_BUTTON_PRESSED)) {
            inputs.fireBullet = true;
        }
    }
    //Sinon on se rabat sur le clavier
    else
    {
        inputs.moveFactorX = inputs.moveFactorY = 0.0f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			inputs.moveFactorX -= KEYBOARD_SPEED;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            inputs.moveFactorX += KEYBOARD_SPEED;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			inputs.moveFactorY -= KEYBOARD_SPEED;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            inputs.moveFactorY += KEYBOARD_SPEED;


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			inputs.fireBullet = true;
        }
    }
}

float GameScene::handleControllerDeadZone(float analogInput)
{
    if (fabs(analogInput) < Inputs::CONTROLLER_DEAD_ZONE)
    {
        analogInput = 0.0f;
    }
    return analogInput;
}

Enemy& GameScene::getAvailableEnemy() {
	for (Enemy& e : enemies) {
		if (!e.isActive()) {
			e.activate();
			return e;
		}
	}
	Enemy newEnemy;
	newEnemy.init(contentManager);
	return enemies.back();
}

HealthBonus& GameScene::getAvailableHealthBonus()
{
	for (HealthBonus& h : healthBonuses) {
		if (!h.isActive()) {
			h.activate();
			return h;
		}
	}
	HealthBonus newBonus;
	newBonus.init(contentManager);
	return healthBonuses.back();
}

WeaponBonus& GameScene::getAvailableWeaponBonus()
{
	for (WeaponBonus& w : gunBonuses) {
		if (!w.isActive()) {
			w.activate();
			return w;
		}
	}
	WeaponBonus newBonus;
	newBonus.init(contentManager);
	return gunBonuses.back();
}
