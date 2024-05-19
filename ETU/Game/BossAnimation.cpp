#include "stdafx.h"
#include "BossAnimation.h"

const int BossAnimation::ANIMATION_LENGTH_IN_SECONDS = 3;
const int BossAnimation::NBS_OPENING_ANIMATION_FRAMES = 6;
const int BossAnimation::NBS_SHOOTING_ANIMATION_FRAMES = 6;
const int BossAnimation::NBS_TOTAL_ANIMATION_FRAMES = 12;
const float BossAnimation::CAN_SHOOT = NBS_OPENING_ANIMATION_FRAMES / NBS_TOTAL_ANIMATION_FRAMES;

BossAnimation::BossAnimation(sf::Sprite& s)
	: CyclicAnimation(s, ANIMATION_LENGTH_IN_SECONDS, true)
{
}

void BossAnimation::update(float deltaT, const Inputs& inputs)
{
	//deltaT = deltaT / (ANIMATION_LENGTH_IN_SECONDS * NBS_TOTAL_ANIMATION_FRAMES);
	//deltaT = deltaT * NBS_TOTAL_ANIMATION_FRAMES;
	CyclicAnimation::update(deltaT, inputs);
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

	lengthInSeconds = ANIMATION_LENGTH_IN_SECONDS;

	hitbox.setSize(sf::Vector2f(85, 176));

	frames.push_back(AnimationFrame::AnimationFrame(bossTexture, opening1));
	frames.push_back(AnimationFrame::AnimationFrame(bossTexture, opening2));
	frames.push_back(AnimationFrame::AnimationFrame(bossTexture, opening3));
	frames.push_back(AnimationFrame::AnimationFrame(bossTexture, opening4));
	frames.push_back(AnimationFrame::AnimationFrame(bossTexture, opening5));
	frames.push_back(AnimationFrame::AnimationFrame(bossTexture, opening6));
	frames.push_back(AnimationFrame::AnimationFrame(bossTexture, fire1));
	frames.push_back(AnimationFrame::AnimationFrame(bossTexture, fire2));
	frames.push_back(AnimationFrame::AnimationFrame(bossTexture, fire3));
	frames.push_back(AnimationFrame::AnimationFrame(bossTexture, fire4));
	frames.push_back(AnimationFrame::AnimationFrame(bossTexture, fire5));
	frames.push_back(AnimationFrame::AnimationFrame(bossTexture, fire6));

	return true;
}
