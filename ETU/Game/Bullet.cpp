#include "stdafx.h"
#include "Bullet.h"
#include "ContentManager.h"
#include "game.h"
#include <iostream>

const float Bullet::BULLET_SPEED = 1000;
const int Bullet::BULLET_TIMEOUT = 2;

Bullet::Bullet(const sf::Vector2f& initialPosition, const sf::Vector2f& initialThrust)
	: GameObject(),
	timer(BULLET_TIMEOUT),
	isSpecial(false)
{
	setPosition(initialPosition);
	move(initialThrust);
}

Bullet::Bullet(const Bullet& src)
	: GameObject(src),
	timer(BULLET_TIMEOUT),
	bulletSound(src.bulletSound)
{
	GameObject::initialize(*src.getTexture(), src.getPosition());
	isSpecial = src.isSpecial;
}
Bullet& Bullet::operator=(const Bullet& rhs)
{
	if (this != &rhs)
	{
		GameObject::operator=(rhs);
		GameObject::initialize(*rhs.getTexture(), rhs.getPosition());
	}
	return *this;
}

void Bullet::draw(sf::RenderWindow& window) const
{
	window.draw(*this);
}


bool Bullet::update()
{
	move(sf::Vector2f(cos(getRotationAngleInRadians()) * BULLET_SPEED * Game::TIME_PER_FRAME, sin(getRotationAngleInRadians()) * BULLET_SPEED * Game::TIME_PER_FRAME));
	timer -= Game::TIME_PER_FRAME;
	if (getPosition().x > Game::GAME_WIDTH || getPosition().x < 0 || getPosition().y > Game::GAME_HEIGHT || getPosition().y < 0 || timer <= 0)
	{
		timer = BULLET_TIMEOUT;
		return true;
	}
	return false;
}


void Bullet::initialize(const sf::Texture& texture, const sf::Vector2f& initialPosition, const sf::SoundBuffer& sb, bool special)
{
	isSpecial = special;
	GameObject::initialize(texture, initialPosition);
	bulletSound.setBuffer(sb);
}

void Bullet::playSound() {
	bulletSound.play();
}
void Bullet::collision() {
	if (!isSpecial) {
		deactivate();
	}
}
void Bullet::setSpecialBullet(const sf::Texture& texture) {
	isSpecial = true;
	setTexture(texture, true);
}
void Bullet::setNormalBullet(const sf::Texture& texture) {
	isSpecial = false;
	setTexture(texture, true);
}
