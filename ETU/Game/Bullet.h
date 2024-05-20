#pragma once
#include "GameObject.h"
class Bullet : public GameObject
{
	static const float BULLET_SPEED;
	static const int BULLET_TIMEOUT;
public:
	Bullet(const sf::Vector2f& initialPosition = sf::Vector2f(0, 0), const sf::Vector2f& initialThrust = sf::Vector2f(0, 0));
	Bullet& operator=(const Bullet& rhs);
	void draw(sf::RenderWindow& window) const;
	bool update();
	void initialize(const sf::Texture& texture, const sf::Vector2f& initialPosition, const sf::SoundBuffer& sb, bool special);
	Bullet(const Bullet& src);
	void playSound();
	sf::Sound bulletSound;
	void collision();
	void setSpecialBullet(const sf::Texture& texture);
	void setNormalBullet(const sf::Texture& texture);

private:
	float timer;
	bool isSpecial;
};



