#include "stdafx.h"
#include "Boss.h"
#include "Inputs.h"
#include "ContentManager.h"
#include "BossAnimation.h"
#include "game.h"

const int Boss::BOSS_SPD = 230;
const int Boss::BOSS_HP = 100;

Boss::Boss()
	: bossHP(BOSS_HP)
{
}

bool Boss::init(const ContentManager& contentManager)
{
	int posX = rand() % Game::GAME_WIDTH - this->getGlobalBounds().width;
	activate();
	setPosition(posX, 0);

	setTexture(contentManager.getMainCharacterTexture());
	setTextureRect(sf::IntRect(140, 0, 70, 32));
	currentState = State::BOSS;

	BossAnimation* bossAnimation = new BossAnimation(*this);
	bool retval = bossAnimation->init(contentManager);

	return retval && AnimatedGameObject::init(contentManager);
}

bool Boss::update(float deltaT, const Inputs& inputs, int playerPosX)
{
	if (getPosition().x > playerPosX) {
		move(sf::Vector2f(BOSS_SPD, 0));
	}
	else {
		move(sf::Vector2f(-BOSS_SPD, 0));
	}
	return GameObject::update(deltaT, inputs);
}
