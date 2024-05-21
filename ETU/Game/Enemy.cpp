#include "stdafx.h"
#include "Enemy.h"
#include "Inputs.h"
#include "ContentManager.h"
#include "EnemyAnimation.h"
#include "AnimatedGameObject.h"
#include "game.h"
#include "Publisher.h"
#include <iostream>

const float Enemy::ENEMY_SPD = 2;
const int Enemy::ENEMY_HP = 5;
const float Enemy::CANNON_POSITION = 30;
const float Enemy::ENEMY_SCALE_X = 1.25f;
const float Enemy::ENEMY_SCALE_Y = 0.75f;
const float Enemy::ENEMY_RECOIL = 0.05f;



Enemy::Enemy()
	: enemyHP(ENEMY_HP)
	, recoil (ENEMY_HP)
{
}

Enemy::Enemy(const Enemy& src)
	:AnimatedGameObject(src)
{
	enemyHP = src.enemyHP;
	init(*contentManager);
}

bool Enemy::init(const ContentManager& contentManager)
{
	setTexture(contentManager.getMainCharacterTexture());
	setTextureRect(sf::IntRect(140, 0, 70, 32));
	setScale(ENEMY_SCALE_X, ENEMY_SCALE_Y);
	enemyGunSound.setBuffer(contentManager.getEnemyGunSoundBuffer());
	enemyDeathSound.setBuffer(contentManager.getEnemyKilledSoundBuffer());
	currentState = State::STANDARD_ENEMY;

	bool retval = addAnimation<State::STANDARD_ENEMY, EnemyAnimation>(contentManager);
	return retval && AnimatedGameObject::init(contentManager);
}

bool Enemy::update(float deltaT, const Inputs& inputs)
{
	if (isActive()) {
		if (recoil > 0) {
			recoil -= deltaT;
		}
		move(sf::Vector2f(0, ENEMY_SPD));
		if (getPosition().y >= Game::GAME_HEIGHT) {
			setPosition(getPosition().x, 0);
		}
		if (animations[currentState]->getPercentage() > EnemyAnimation::CAN_SHOOT && recoil <= 0 && isActive()) {
			Publisher::notifySubscribers(Event::ENEMY_SHOOT, this);
			if (enemyGunSound.getStatus() == sf::Sound::Stopped) {
				enemyGunSound.play();
			}
			recoil = ENEMY_RECOIL;
		}
	}

	return AnimatedGameObject::update(deltaT, inputs);
}
void Enemy::hit(int hitPoints) {
	enemyHP -= hitPoints;
	if (enemyHP <= 0) {
		Publisher::notifySubscribers(Event::ENEMY_KILLED, this);
		this->deactivate();
		enemyDeathSound.play();
	}
}
