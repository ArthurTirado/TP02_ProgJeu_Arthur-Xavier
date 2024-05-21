#include "stdafx.h"
#include "Player.h"
#include "Inputs.h"
#include "ContentManager.h"
#include "ShipAnimation.h"
#include "AnimatedGameObject.h"
#include "game.h"
#include "Publisher.h"

const int Player::PLAYER_HP = 2000;
const int Player::PLAYER_SPD = 500;
const float Player::PLAYER_SCALE = 3.0f; 
const float Player::CANNON_POSITION = 25.0f;


Player::Player()
	: playerHP(PLAYER_HP)
{

}

bool Player::init(const ContentManager& contentManager)
{
	activate();
	setPosition(sf::Vector2f(Game::GAME_HEIGHT / 2, Game::GAME_HEIGHT * 0.2f));

	setTexture(contentManager.getMainCharacterTexture());
	setTextureRect(sf::IntRect(36, 87, 22, 27));
	setScale(PLAYER_SCALE, PLAYER_SCALE); 
	shotSound.setBuffer(contentManager.getPlayerGunSoundBuffer());

	currentState = State::SHIP;

	//ShipAnimation* shipAnimation = new ShipAnimation(*this);
	//bool retval = shipAnimation->init(contentManager);
	bool retval = addAnimation<State::SHIP, ShipAnimation>(contentManager);

	return retval && AnimatedGameObject::init(contentManager);
}

bool Player::update(float deltaT, const Inputs& inputs)
{
	move(sf::Vector2f(inputs.moveFactorX * PLAYER_SPD, -inputs.moveFactorY * PLAYER_SPD));
	stayInbounds();
	return AnimatedGameObject::update(deltaT, inputs);
}

void Player::stayInbounds()
{
	float x = getPosition().x;
	float y = getPosition().y;
	if (x > Game::GAME_WIDTH - getGlobalBounds().width) {
		x = Game::GAME_WIDTH - getGlobalBounds().width;
	}
	else if (x < 0 + getGlobalBounds().width) {
		x = getGlobalBounds().width;
	}

	if (y > Game::GAME_HEIGHT - getGlobalBounds().height) {
		y = Game::GAME_HEIGHT - getGlobalBounds().height;
	}
	else if (y < 0 + getGlobalBounds().height) {
		y = getGlobalBounds().height;
	}
	setPosition(x, y);
}
void Player::shoot()  {
	shotSound.play();
}
void Player::hit(int hitPoints) {
	playerHP -= hitPoints;
	if (playerHP <= 0) {
		Publisher::notifySubscribers(Event::GAME_OVER, this);
		this->deactivate();
	}
}

