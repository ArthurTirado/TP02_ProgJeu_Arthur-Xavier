#include "stdafx.h"
#include "Enemy.h"
#include "Inputs.h"
#include "ContentManager.h"
#include "EnemyAnimation.h"
#include "game.h"

const int Enemy::ENEMY_SPD = 160;
const int Enemy::ENEMY_HP = 5;

Enemy::Enemy()
	: enemyHP(ENEMY_HP)
{
}

bool Enemy::init(const ContentManager& contentManager)
{
	int posX = rand() % Game::GAME_WIDTH - this->getGlobalBounds().width;
	activate();
	setPosition(posX, 0);

	setTexture(contentManager.getMainCharacterTexture());
	setTextureRect(sf::IntRect(140, 0, 70, 32));
	currentState = State::STANDARD_ENEMY;

	EnemyAnimation* enemyAnimation = new EnemyAnimation(*this);
	bool retval = enemyAnimation->init(contentManager);

	return retval && AnimatedGameObject::init(contentManager);
}

bool Enemy::update(float deltaT, const Inputs& inputs)
{
	move(sf::Vector2f(0, ENEMY_SPD));
	return GameObject::update(deltaT, inputs);
}
