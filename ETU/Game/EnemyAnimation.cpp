#include "stdafx.h"
#include "EnemyAnimation.h"

const float EnemyAnimation::CAN_SHOOT = 0.7f;

EnemyAnimation::EnemyAnimation(sf::Sprite& s)
	: CyclicAnimation(s, 18, true)
{
}

void EnemyAnimation::update(float deltaT, const Inputs& inputs)
{
}

bool EnemyAnimation::canShoot() {
	if (EnemyAnimation::getPercentage() >= CAN_SHOOT) {
		return true;
	}
	return false;
}

bool EnemyAnimation::init(const ContentManager& contentManager)
{
	sf::Texture enemyTexture = contentManager.getEnemiesTexture();
	opening1 = sf::IntRect(28, 917, 63, 95);
	opening2 = sf::IntRect(101, 917, 63, 95);
	opening3 = sf::IntRect(174, 917, 63, 95);
	opening4 = sf::IntRect(247, 917, 63, 95);
	opening5 = sf::IntRect(320, 917, 63, 95);
	opening6 = sf::IntRect(393, 917, 63, 95);
	opening7 = sf::IntRect(466, 917, 63, 95);
	opening8 = sf::IntRect(539, 917, 63, 95);
	opening9 = sf::IntRect(612, 917, 63, 95);

	opening10 = sf::IntRect(28, 1031, 63, 95);
	opening11 = sf::IntRect(101, 1031, 63, 95);
	opening12 = sf::IntRect(174, 1031, 63, 95);
	opening13 = sf::IntRect(247, 1031, 63, 95);
	fire1 = sf::IntRect(320, 1031, 63, 95);
	fire2 = sf::IntRect(393, 1031, 63, 95);
	fire3 = sf::IntRect(466, 1031, 63, 95);
	fire4 = sf::IntRect(539, 1031, 63, 95);
	fire5 = sf::IntRect(611, 1031, 65, 95);

	hitbox.setSize(sf::Vector2f(63, 95));

	frames.push_back(AnimationFrame::AnimationFrame(enemyTexture, fire5));
	frames.push_back(AnimationFrame::AnimationFrame(enemyTexture, fire4));
	frames.push_back(AnimationFrame::AnimationFrame(enemyTexture, fire3));
	frames.push_back(AnimationFrame::AnimationFrame(enemyTexture, fire2));
	frames.push_back(AnimationFrame::AnimationFrame(enemyTexture, fire1));
	frames.push_back(AnimationFrame::AnimationFrame(enemyTexture, opening13));
	frames.push_back(AnimationFrame::AnimationFrame(enemyTexture, opening12));
	frames.push_back(AnimationFrame::AnimationFrame(enemyTexture, opening11));
	frames.push_back(AnimationFrame::AnimationFrame(enemyTexture, opening10));
	frames.push_back(AnimationFrame::AnimationFrame(enemyTexture, opening9));
	frames.push_back(AnimationFrame::AnimationFrame(enemyTexture, opening8));
	frames.push_back(AnimationFrame::AnimationFrame(enemyTexture, opening7));
	frames.push_back(AnimationFrame::AnimationFrame(enemyTexture, opening6));
	frames.push_back(AnimationFrame::AnimationFrame(enemyTexture, opening5));
	frames.push_back(AnimationFrame::AnimationFrame(enemyTexture, opening4));
	frames.push_back(AnimationFrame::AnimationFrame(enemyTexture, opening3));
	frames.push_back(AnimationFrame::AnimationFrame(enemyTexture, opening2));
	frames.push_back(AnimationFrame::AnimationFrame(enemyTexture, opening1));
	
	return true;
}