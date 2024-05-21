#include "stdafx.h"
#include "BossAnimation.h"

const int BossAnimation::ANIMATION_LENGTH_IN_SECONDS = 2;
const float BossAnimation::NBS_OPENING_ANIMATION_FRAMES = 6;
const float BossAnimation::NBS_SHOOTING_ANIMATION_FRAMES = 6;
const float BossAnimation::NBS_TOTAL_ANIMATION_FRAMES = 12;
const float BossAnimation::CAN_SHOOT = NBS_OPENING_ANIMATION_FRAMES / NBS_TOTAL_ANIMATION_FRAMES;

BossAnimation::BossAnimation(sf::Sprite& s)
	: CyclicAnimation(s, ANIMATION_LENGTH_IN_SECONDS, true)
{
}

bool BossAnimation::init(const ContentManager& contentManager)
{
	lengthInSeconds = ANIMATION_LENGTH_IN_SECONDS;

	hitbox.setSize(sf::Vector2f(85, 176));

	frames.push_back(AnimationFrame::AnimationFrame(contentManager.getEnemiesTexture(), opening1));
	frames.push_back(AnimationFrame::AnimationFrame(contentManager.getEnemiesTexture() , opening2));
	frames.push_back(AnimationFrame::AnimationFrame(contentManager.getEnemiesTexture() , opening3));
	frames.push_back(AnimationFrame::AnimationFrame(contentManager.getEnemiesTexture() , opening4));
	frames.push_back(AnimationFrame::AnimationFrame(contentManager.getEnemiesTexture() , opening5));
	frames.push_back(AnimationFrame::AnimationFrame(contentManager.getEnemiesTexture() , opening6));
	frames.push_back(AnimationFrame::AnimationFrame(contentManager.getEnemiesTexture(), fire1));
	frames.push_back(AnimationFrame::AnimationFrame(contentManager.getEnemiesTexture(), fire2));
	frames.push_back(AnimationFrame::AnimationFrame(contentManager.getEnemiesTexture() , fire3));
	frames.push_back(AnimationFrame::AnimationFrame(contentManager.getEnemiesTexture() , fire4));
	frames.push_back(AnimationFrame::AnimationFrame(contentManager.getEnemiesTexture(), fire5));
	frames.push_back(AnimationFrame::AnimationFrame(contentManager.getEnemiesTexture(), fire6));

	return true;
}
