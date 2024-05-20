#include "stdafx.h"
#include "ShipAnimation.h"
#include "contentManager.h"
#include "Inputs.h"

const int ShipAnimation::NEUTRAL_ANIMATION_LENGTH_IN_SECONDS = 1;
const int ShipAnimation::NBS_NEUTRAL_ANIMATION_FRAMES = 4;

ShipAnimation::ShipAnimation(sf::Sprite& sprite)
	: InputBasedAnimation(sprite)
	, nbFrameInStateX(25)
    ,neutralFrameCounter(0)
{
}

void ShipAnimation::adjustNextFrame(const Inputs& inputs) {
    // Adjust nbFrameInStateX based on input movement
    if (inputs.moveFactorX < 0) {
        nbFrameInStateX = std::min(nbFrameInStateX + 1, 49);
    }
    else if (inputs.moveFactorX > 0) {
        nbFrameInStateX = std::max(nbFrameInStateX - 1, 0);
    }
    else {
        // No input: smoothly return to neutral
        if (nbFrameInStateX > 25) {
            nbFrameInStateX--;
        }
        else if (nbFrameInStateX < 25) {
            nbFrameInStateX++;
        }
    }

    // Determine the frame based on nbFrameInStateX
    if (nbFrameInStateX >= 40) {
        nextFrame = 0; // hard left
    }
    else if (nbFrameInStateX >= 30) {
        nextFrame = 1; // left
    }
    else if (nbFrameInStateX >= 20) {
        nextFrame = 2; // neutral1
    }
    else if (nbFrameInStateX >= 10) {
        nextFrame = 3; // right
    }
    else {
        nextFrame = 4; // hard right
    }
}




//void ShipAnimation::update(float deltaT, const Inputs& inputs) {
//	LinearAnimation::update(deltaT, inputs);
//}

bool ShipAnimation::init(const ContentManager& contentManager)
{
	sf::Texture mainTexture = contentManager.getMainCharacterTexture();

	InputBasedAnimation::frames.push_back(AnimationFrame::AnimationFrame(contentManager.getMainCharacterTexture(), hardLeft));
	InputBasedAnimation::frames.push_back(AnimationFrame::AnimationFrame(contentManager.getMainCharacterTexture(), left));
	InputBasedAnimation::frames.push_back(AnimationFrame::AnimationFrame(contentManager.getMainCharacterTexture(), neutral1));
	InputBasedAnimation::frames.push_back(AnimationFrame::AnimationFrame(contentManager.getMainCharacterTexture(), right));
	InputBasedAnimation::frames.push_back(AnimationFrame::AnimationFrame(contentManager.getMainCharacterTexture(), hardRight));

	/*InputBasedAnimation::frames.push_back(AnimationFrame::AnimationFrame(contentManager.getMainCharacterTexture(), neutral1));
	InputBasedAnimation::frames.push_back(AnimationFrame::AnimationFrame(contentManager.getMainCharacterTexture(), neutral2));
	InputBasedAnimation::frames.push_back(AnimationFrame::AnimationFrame(contentManager.getMainCharacterTexture(), neutral3));
	InputBasedAnimation::frames.push_back(AnimationFrame::AnimationFrame(contentManager.getMainCharacterTexture(), neutral4));*/

	InputBasedAnimation::frames.begin();

	return true;
}
