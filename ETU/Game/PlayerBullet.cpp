#include "stdafx.h"
#include "PlayerBullet.h"
#include "Game.h"
#include "Player.h"


const float PlayerBullet::BULLET_SPEED = 600;
const float PlayerBullet::TIME_TO_LIVE = 2000;

PlayerBullet::PlayerBullet(const sf::Vector2f& initialPosition, const sf::Vector2f& initialThrust)
	: GameObject()
	, activationTime(0)
	, isPlayer(true)
{
	setPosition(initialPosition);
	move(initialThrust);
}

PlayerBullet::PlayerBullet(const PlayerBullet& src)
	:GameObject(src)
{
	sprite = src.sprite;
}


void PlayerBullet::draw(sf::RenderWindow& window) const
{
	if (isActive()) {
		window.draw(*this);
	}
}


bool PlayerBullet::update(float elapsedTime)
{
	if (isActive())
	{
		move(-sf::Vector2f(cos(getRotationAngleInRadians()) * BULLET_SPEED * elapsedTime, sin(getRotationAngleInRadians()) * BULLET_SPEED * elapsedTime));
		if (getPosition().x > Game::GAME_WIDTH || getPosition().x < 0 || getPosition().y > Game::GAME_HEIGHT || getPosition().y < 0)
			return true;

		activationTime += elapsedTime;
	}
	else
		return true;
	if (activationTime > TIME_TO_LIVE)
		return true;
	return false;

}

bool PlayerBullet::init(const ContentManager& contentManager, bool isPlayerBullet){
	isPlayer = isPlayerBullet;
	setTexture(contentManager.getMainCharacterTexture());
	if (isPlayer) {
		setTextureRect(playerBullet);
	}
	else {
		setTextureRect(enemyBullet);
	}
	setScale(Player::PLAYER_SCALE, Player::PLAYER_SCALE);
	setRotation(90.0f);

	return true;
}

void PlayerBullet::activate()
{
	GameObject::activate();
	activationTime = 0;
}

bool PlayerBullet::isPlayerBullet() const {
	return isPlayer;
}