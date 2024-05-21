#include "stdafx.h"
#include "Boss.h"
#include "Inputs.h"
#include "ContentManager.h"
#include "BossAnimation.h"
#include "game.h"
#include <iostream>

const int Boss::BOSS_SPD = 2;
const int Boss::BOSS_HP = 24;
const float Boss::MOVEMENT_TOLERANCE = 2;
const float Boss::BOSS_SCALE = 1.5f;
const float Boss::INTRO_DURATION = 2.5f;
const float Boss::SLOW_SPD = 1;
const float Boss::ENEMY_RECOIL = 0.05f;
const float Boss::LASER = 5;


Boss::Boss()
	: bossHP(BOSS_HP)
	, descendTimer(INTRO_DURATION)
	, recoil(0)
{
}

bool Boss::init(const ContentManager& contentManager)
{
	setTexture(contentManager.getMainCharacterTexture());
	setTextureRect(sf::IntRect(140, 0, 70, 32));
	enemyGunSound.setBuffer(contentManager.getEnemyGunSoundBuffer());
	currentState = State::BOSS;
	setPosition(Game::GAME_WIDTH / 2, 0);
	setScale(BOSS_SCALE, BOSS_SCALE);
	bool retval = addAnimation<State::BOSS, BossAnimation>(contentManager);

	return retval && AnimatedGameObject::init(contentManager);

}

bool Boss::update(float deltaT, const Inputs& inputs, int playerPosX)
{
	if (isActive()) {
		if (recoil > 0) {
			recoil -= deltaT;
		}
		if (descendTimer > 0) {
			descendTimer -= deltaT;
			move(0, SLOW_SPD);
		}
		else {
			if (std::abs(getPosition().x - playerPosX) > MOVEMENT_TOLERANCE)
			{
				if (getPosition().x > playerPosX) {
					move(sf::Vector2f(-BOSS_SPD, 0));
				}
				else {
					move(sf::Vector2f(BOSS_SPD, 0));
				}
			}
		}
		if (animations[currentState]->getPercentage() > BossAnimation::CAN_SHOOT && recoil <= 0 && isActive()) {
			Publisher::notifySubscribers(Event::BOSS_SHOOT, this);
			if (enemyGunSound.getStatus() == sf::Sound::Stopped) {
				enemyGunSound.play();
			}
			recoil = ENEMY_RECOIL;
		}

	}
	
	return AnimatedGameObject::update(deltaT, inputs);
}
void Boss::hit(int hitPoints) {
	bossHP -= hitPoints;
	if (bossHP <= 0) {
		Publisher::notifySubscribers(Event::BOSS_KILLED, this);
		this->deactivate();
	}
}
