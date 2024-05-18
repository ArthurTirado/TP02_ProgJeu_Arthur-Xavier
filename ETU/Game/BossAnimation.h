#pragma once
#include "CyclicAnimation.h"
#include "ContentManager.h"
class BossAnimation :
    public CyclicAnimation
{
public:
	static const int ANIMATION_LENGTH_IN_SECONDS;
    static const float CAN_SHOOT;
	static const int NBS_OPENING_ANIMATION_FRAMES;
	static const int NBS_SHOOTING_ANIMATION_FRAMES;
	static const int NBS_TOTAL_ANIMATION_FRAMES;
public:
    BossAnimation(sf::Sprite& s);
    virtual void update(float deltaT, const Inputs& inputs) override;
    virtual bool init(const ContentManager& contentManager) override;
    bool canShoot();
private:
    sf::RectangleShape hitbox;
    sf::IntRect opening1 = sf::IntRect(32, 1906, 83, 122);
	sf::IntRect opening2 = sf::IntRect(133, 1906, 83, 124);
	sf::IntRect opening3 = sf::IntRect(232, 1906, 85, 137);
	sf::IntRect opening4 = sf::IntRect(329, 1906, 73, 141);
	sf::IntRect opening5 = sf::IntRect(426, 1906, 73, 142);
	sf::IntRect opening6 = sf::IntRect(522, 1906, 71, 145);

	sf::IntRect fire1 = sf::IntRect(33, 2070, 69, 149);
	sf::IntRect fire2 = sf::IntRect(140, 2070, 67, 153);
	sf::IntRect fire3 = sf::IntRect(237, 2070, 67, 154);
	sf::IntRect fire4 = sf::IntRect(335, 2070, 63, 159);
	sf::IntRect fire5 = sf::IntRect(433, 2070, 63, 174);
	sf::IntRect fire6 = sf::IntRect(531, 2070, 63, 176);
};

