#include "stdafx.h"
#include "ShipAnimation.h"
#include "Inputs.h"

ShipAnimation::ShipAnimation(sf::Sprite& sprite)
	: InputBasedAnimation(sprite), LinearAnimation(sprite, 5, true)
{
}

void ShipAnimation::adjustNextFrame(const Inputs& inputs)
{
	if (inputs.moveFactorX < 0 && nbFrameInStateX <= 50) {
		nbFrameInStateX++;
	}
	else if(inputs.moveFactorX > 0 && nbFrameInStateX >= 0){
		nbFrameInStateX--;
	}

	if (nbFrameInStateX > 25) {
		nbFrameInStateX--;
	}
	else if(nbFrameInStateX < 25) {
		nbFrameInStateX++;
	}

	if (nbFrameInStateX > 40) {
		nextFrame = 3;
	}
	else if (nbFrameInStateX > 27) {
		nextFrame = 2;
	}
	else if (nbFrameInStateX > 14) {
		nextFrame = 1;
	}
	else
		nextFrame = 0;
	}
}

void ShipAnimation::update(float deltaT, const Inputs& inputs) {
	LinearAnimation::frames.begin();
	if (deltaT > 0.25f) {
		LinearAnimation::frames.at(1);
	}
	else if (deltaT > 0.5f) {
		LinearAnimation::frames.at(2);
	}
	else if (deltaT > 0.75f) {
		LinearAnimation::frames.at(3);
	}
	else {
		LinearAnimation::frames.at(4);
	}
}

bool ShipAnimation::init(const ContentManager& contentManager)
{
	sf::Texture mainTexture = contentManager.getMainCharacterTexture();
	
	shipAnimationHorizontalMovementFrames[0] = hardLeft;
	shipAnimationHorizontalMovementFrames[1] = left;
	
	// Si aucun mouvement horizontal
	shipAnimationHorizontalMovementFrames[2] = neutral1;

	shipAnimationHorizontalMovementFrames[3] = right;
	shipAnimationHorizontalMovementFrames[4] = hardRight;

	LinearAnimation::frames.push_back(AnimationFrame::AnimationFrame(mainTexture, neutral1));
	LinearAnimation::frames.push_back(AnimationFrame::AnimationFrame(mainTexture, neutral2));
	LinearAnimation::frames.push_back(AnimationFrame::AnimationFrame(mainTexture, neutral3));
	LinearAnimation::frames.push_back(AnimationFrame::AnimationFrame(mainTexture, neutral4));

	return true;
}
