#include "stdafx.h"
#include "EnemyAnimation.h"

const int EnemyAnimation::ANIMATION_LENGTH_IN_SECONDS = 4;
const int EnemyAnimation::NBS_OPENING_ANIMATION_FRAMES = 13;
const int EnemyAnimation::NBS_SHOOTING_ANIMATION_FRAMES = 5;
const int EnemyAnimation::NBS_TOTAL_ANIMATION_FRAMES = 18;
const float EnemyAnimation::CAN_SHOOT = NBS_OPENING_ANIMATION_FRAMES / NBS_TOTAL_ANIMATION_FRAMES;

EnemyAnimation::EnemyAnimation(sf::Sprite& s)
	: CyclicAnimation(s, ANIMATION_LENGTH_IN_SECONDS, true)
{
}

/*void EnemyAnimation::update(float deltaT, const Inputs& inputs)
{
	//deltaT = deltaT / (ANIMATION_LENGTH_IN_SECONDS * NBS_TOTAL_ANIMATION_FRAMES);
	//deltaT = deltaT * NBS_TOTAL_ANIMATION_FRAMES;
	CyclicAnimation::update(deltaT, inputs);
}*/

bool EnemyAnimation::canShoot() {
	if (EnemyAnimation::getPercentage() >= CAN_SHOOT) {
		return true;
	}
	return false;
}

bool EnemyAnimation::init(const ContentManager& contentManager)
{
	sf::Texture enemyTexture = contentManager.getEnemiesTexture();


	hitbox.setSize(sf::Vector2f(63, 95));

	frames.push_back(AnimationFrame::AnimationFrame(contentManager.getEnemiesTexture(), opening1));
	frames.push_back(AnimationFrame::AnimationFrame(contentManager.getEnemiesTexture(), opening2));
	frames.push_back(AnimationFrame::AnimationFrame(contentManager.getEnemiesTexture(), opening3));
	frames.push_back(AnimationFrame::AnimationFrame(contentManager.getEnemiesTexture(), opening4));
	frames.push_back(AnimationFrame::AnimationFrame(contentManager.getEnemiesTexture(), opening5));
	frames.push_back(AnimationFrame::AnimationFrame(contentManager.getEnemiesTexture(), opening6));
	frames.push_back(AnimationFrame::AnimationFrame(contentManager.getEnemiesTexture(), opening7));
	frames.push_back(AnimationFrame::AnimationFrame(contentManager.getEnemiesTexture(), opening8));
	frames.push_back(AnimationFrame::AnimationFrame(contentManager.getEnemiesTexture(), opening9));
	frames.push_back(AnimationFrame::AnimationFrame(contentManager.getEnemiesTexture(), opening10));
	frames.push_back(AnimationFrame::AnimationFrame(contentManager.getEnemiesTexture(), opening11));
	frames.push_back(AnimationFrame::AnimationFrame(contentManager.getEnemiesTexture(), opening12));
	frames.push_back(AnimationFrame::AnimationFrame(contentManager.getEnemiesTexture(), opening13));
	frames.push_back(AnimationFrame::AnimationFrame(contentManager.getEnemiesTexture(), fire1));
	frames.push_back(AnimationFrame::AnimationFrame(contentManager.getEnemiesTexture(), fire2));
	frames.push_back(AnimationFrame::AnimationFrame(contentManager.getEnemiesTexture(), fire3));
	frames.push_back(AnimationFrame::AnimationFrame(contentManager.getEnemiesTexture(), fire4));
	frames.push_back(AnimationFrame::AnimationFrame(contentManager.getEnemiesTexture(), fire5));

	return true;
}
