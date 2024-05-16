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
		nextFrame = 4;
	}
	else if (nbFrameInStateX > 30) {
		nextFrame = 3;
	}
	else if (nbFrameInStateX > 20) {
		nextFrame = 2;
	}
	else if (nbFrameInStateX > 10) {
		nextFrame = 1;
	}
	else {
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

	hardLeft = sf::IntRect(182, 87, 13, 27);
	left = sf::IntRect(156, 87, 17, 28);
	neutral1 = sf::IntRect(36, 87, 22, 27);
	neutral2 = sf::IntRect(7, 87, 22, 27);
	neutral3 = sf::IntRect(65, 87, 22, 29);
	neutral4 = sf::IntRect(95, 87, 22, 30);
	right = sf::IntRect(225, 87, 17, 28);
	hardRight = sf::IntRect(203, 87, 13, 27);
	LinearAnimation::frames.push_back(AnimationFrame::AnimationFrame(mainTexture, neutral4));
	LinearAnimation::frames.push_back(AnimationFrame::AnimationFrame(mainTexture, neutral3));
	LinearAnimation::frames.push_back(AnimationFrame::AnimationFrame(mainTexture, neutral2));
	LinearAnimation::frames.push_back(AnimationFrame::AnimationFrame(mainTexture, neutral1));

	return true;
}
