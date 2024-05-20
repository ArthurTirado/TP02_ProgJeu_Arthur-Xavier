#include "stdafx.h"
#include "Canon.h"
#include "Inputs.h"
#include "ContentManager.h"
#include "ShipAnimation.h"
#include "game.h"

const int Canon::CANON_HP = 50;

Canon::Canon()
	: canonHP(CANON_HP)
{

}

bool Canon::init(const ContentManager& contentManager)
{
	activate();
	setPosition(sf::Vector2f(Game::GAME_HEIGHT / 2, Game::GAME_HEIGHT * 0.2f));

	setTexture(contentManager.getMainCharacterTexture());
	setTextureRect(sf::IntRect(36, 87, 22, 27));

	return GameObject::init(contentManager);
}

bool Canon::update(float deltaT, const Inputs& inputs)
{
	move(sf::Vector2f(inputs.moveFactorX, -inputs.moveFactorY));
	stayInbounds();
	return GameObject::update(deltaT, inputs);
}

void Canon::stayInbounds()
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

