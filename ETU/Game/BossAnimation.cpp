#include "stdafx.h"
#include "BossAnimation.h"

const float BossAnimation::CAN_SHOOT = 0.5f;

BossAnimation::BossAnimation(sf::Sprite& s)
	: CyclicAnimation(s, 12, true)
{
}

void BossAnimation::update(float deltaT, const Inputs& inputs)
{
}

bool BossAnimation::canShoot() {
	if (BossAnimation::getPercentage() >= CAN_SHOOT) {
		return true;
	}
	return false;
}

bool BossAnimation::init(const ContentManager& contentManager)
{
	sf::Texture bossTexture = contentManager.getEnemiesTexture();
	opening1 = sf::IntRect(32, 1906, 83, 122);
	opening2 = sf::IntRect(133, 1906, 83, 124);
	opening3 = sf::IntRect(232, 1906, 85, 137);
	opening4 = sf::IntRect(329, 1906, 73, 141);
	opening5 = sf::IntRect(426, 1906, 73, 142);
	opening6 = sf::IntRect(522, 1906, 71, 145);

	fire1 = sf::IntRect(33, 2070, 69, 149);
	fire2 = sf::IntRect(140, 2070, 67, 153);
	fire3 = sf::IntRect(237, 2070, 67, 154);
	fire4 = sf::IntRect(335, 2070, 63, 159);
	fire5 = sf::IntRect(433, 2070, 63, 174);
	fire6 = sf::IntRect(531, 2070, 63, 176);

	hitbox.setSize(sf::Vector2f(85, 176));

	frames.push_back(AnimationFrame::AnimationFrame(bossTexture, fire6));
	frames.push_back(AnimationFrame::AnimationFrame(bossTexture, fire5));
	frames.push_back(AnimationFrame::AnimationFrame(bossTexture, fire4));
	frames.push_back(AnimationFrame::AnimationFrame(bossTexture, fire3));
	frames.push_back(AnimationFrame::AnimationFrame(bossTexture, fire2));
	frames.push_back(AnimationFrame::AnimationFrame(bossTexture, fire1));
	frames.push_back(AnimationFrame::AnimationFrame(bossTexture, opening6));
	frames.push_back(AnimationFrame::AnimationFrame(bossTexture, opening5));
	frames.push_back(AnimationFrame::AnimationFrame(bossTexture, opening4));
	frames.push_back(AnimationFrame::AnimationFrame(bossTexture, opening3));
	frames.push_back(AnimationFrame::AnimationFrame(bossTexture, opening2));
	frames.push_back(AnimationFrame::AnimationFrame(bossTexture, opening1));

	return true;
}
