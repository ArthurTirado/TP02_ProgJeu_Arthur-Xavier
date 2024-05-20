#pragma once
#include "GameObject.h"
#include "ContentManager.h"

class PlayerBullet : public GameObject
{
	static const float BULLET_SPEED;
	static const float TIME_TO_LIVE;
public:
	PlayerBullet(const sf::Vector2f& initialPosition = sf::Vector2f(0, 0), const sf::Vector2f& initialThrust = sf::Vector2f(0, 0));
	PlayerBullet(const PlayerBullet& src);
	bool init(const ContentManager& contentManager);
	virtual void activate() override;
	void draw(sf::RenderWindow& window) const;
	bool update(float elapsedTime);

private:
	PlayerBullet& operator=(const PlayerBullet& rhs);
	sf::Sound sound;
	sf::Sprite sprite;
	float activationTime;
	sf::IntRect playerBullet = sf::IntRect(264, 106, 15, 4);
};

