#include "stdafx.h"
#include <iostream>
#include "ContentManager.h"
#include "game.h"
#include "Bullet.h"

const float Bullet::BULLET_SPEED = 800;
const int Bullet::BULLET_TEXTURE_ROTATION = 90;
// Code emprunté de l'exercice #4

Bullet::Bullet(const sf::Vector2f& initialPosition, const sf::Vector2f& initialThrust)
	: GameObject()
{
	setPosition(initialPosition);
	move(initialThrust);
}

bool Bullet::init(const ContentManager& contentManager)
{
	return false;
}


void Bullet::draw(sf::RenderWindow& window) const
{
	if (isActive())
		window.draw(*this);
}


bool Bullet::update(float elapsedTime)
{
	if (isActive())
	{
		move(sf::Vector2f(0, BULLET_SPEED * elapsedTime));
		if (getPosition().y > Game::GAME_HEIGHT || getPosition().y < 0)
			return true;
	}
	else {
		return true;
	}
	return false;

}

void Bullet::activate(float posX, float posY)
{
	setPosition(posX, posY);
	GameObject::activate();
	sound.play();
}