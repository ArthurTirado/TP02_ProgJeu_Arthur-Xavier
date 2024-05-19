#include "stdafx.h"
#include "ShipAnimation.h"
#include "Inputs.h"

const int ShipAnimation::NEUTRAL_ANIMATION_LENGTH_IN_SECONDS = 1.5;
const int ShipAnimation::NBS_NEUTRAL_ANIMATION_FRAMES = 4;

ShipAnimation::ShipAnimation(sf::Sprite& sprite)
	: InputBasedAnimation(sprite), LinearAnimation(sprite, NEUTRAL_ANIMATION_LENGTH_IN_SECONDS, true)
	, nbFrameInStateX(25)
{
}

void ShipAnimation::adjustNextFrame(const Inputs& inputs)
{
	if (inputs.moveFactorX < 0 && nbFrameInStateX <= 50) {
		nbFrameInStateX++;
	}
	else if (inputs.moveFactorX > 0 && nbFrameInStateX >= 0) {
		nbFrameInStateX--;
	}

	if (nbFrameInStateX > 25) {
		nbFrameInStateX--;
	}
	else if (nbFrameInStateX < 25) {
		nbFrameInStateX++;
	}

	if (nbFrameInStateX > 40) {
		nextFrame = 4;
	}
	else if (nbFrameInStateX > 30) {
		nextFrame = 3;
	}
	else if (nbFrameInStateX > 20) {
		nextFrame = 1;
	}
	else {
		nextFrame = 0;
	}

	if (nbFrameInStateX == 25){
		nextFrame = 2;
	}
}

void ShipAnimation::update(float deltaT, const Inputs& inputs) {
	LinearAnimation::update(deltaT, inputs);
}

bool ShipAnimation::init(const ContentManager& contentManager)
{
	sf::Texture mainTexture = contentManager.getMainCharacterTexture();

	InputBasedAnimation::frames.push_back(AnimationFrame::AnimationFrame(mainTexture, hardLeft));
	InputBasedAnimation::frames.push_back(AnimationFrame::AnimationFrame(mainTexture, left));
	// Si aucun mouvement horizontal
	InputBasedAnimation::frames.push_back(AnimationFrame::AnimationFrame(mainTexture, neutral1));
	InputBasedAnimation::frames.push_back(AnimationFrame::AnimationFrame(mainTexture, right));
	InputBasedAnimation::frames.push_back(AnimationFrame::AnimationFrame(mainTexture, hardRight));

	LinearAnimation::frames.push_back(AnimationFrame::AnimationFrame(mainTexture, neutral1));
	LinearAnimation::frames.push_back(AnimationFrame::AnimationFrame(mainTexture, neutral2));
	LinearAnimation::frames.push_back(AnimationFrame::AnimationFrame(mainTexture, neutral3));
	LinearAnimation::frames.push_back(AnimationFrame::AnimationFrame(mainTexture, neutral4));

	LinearAnimation::frames.begin();

	return true;
}
