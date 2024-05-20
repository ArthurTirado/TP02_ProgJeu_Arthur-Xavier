#pragma once
#include "CyclicAnimation.h"
#include "ContentManager.h"
class EnemyAnimation :
	public CyclicAnimation
{
public:
	static const int ANIMATION_LENGTH_IN_SECONDS;
	static const float CAN_SHOOT;
	static const int NBS_OPENING_ANIMATION_FRAMES;
	static const int NBS_SHOOTING_ANIMATION_FRAMES;
	static const int NBS_TOTAL_ANIMATION_FRAMES;
public:
	EnemyAnimation(sf::Sprite& s);
	bool canShoot();
	virtual void update(float deltaT, const Inputs& inputs) override;
	virtual bool init(const ContentManager& contentManager) override;
private:
	sf::RectangleShape hitbox = sf::RectangleShape(sf::Vector2f(63, 95));

	sf::IntRect opening1 = sf::IntRect(28, 917, 63, 95);
	sf::IntRect opening2 = sf::IntRect(101, 917, 63, 95);
	sf::IntRect opening3 = sf::IntRect(174, 917, 63, 95);
	sf::IntRect opening4 = sf::IntRect(247, 917, 63, 95);
	sf::IntRect opening5 = sf::IntRect(320, 917, 63, 95);
	sf::IntRect opening6 = sf::IntRect(393, 917, 63, 95);
	sf::IntRect opening7 = sf::IntRect(466, 917, 63, 95);
	sf::IntRect opening8 = sf::IntRect(539, 917, 63, 95);
	sf::IntRect opening9 = sf::IntRect(612, 917, 63, 95);
	sf::IntRect opening10 = sf::IntRect(28, 1031, 63, 95);
	sf::IntRect opening11 = sf::IntRect(101, 1031, 63, 95);
	sf::IntRect opening12 = sf::IntRect(174, 1031, 63, 95);
	sf::IntRect opening13 = sf::IntRect(247, 1031, 63, 95);

	sf::IntRect fire1 = sf::IntRect(320, 1031, 63, 95);
	sf::IntRect fire2 = sf::IntRect(393, 1031, 63, 95);
	sf::IntRect fire3 = sf::IntRect(466, 1031, 63, 95);
	sf::IntRect fire4 = sf::IntRect(539, 1031, 63, 95);
	sf::IntRect fire5 = sf::IntRect(611, 1031, 65, 95);
};
