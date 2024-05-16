#include "stdafx.h"
#include "Playership.h"
#include "Inputs.h"

Playership::Playership(sf::Sprite& sprite)
	: InputBasedAnimation(sprite), CyclicAnimation(sprite, 100, true)
{
}

void Playership::adjustNextFrame(const Inputs& inputs)
{
	if (inputs.moveFactorX < 0 && nbFrameInState <= 50) {
		nbFrameInState++;
	}
	else if(inputs.moveFactorX > 0 && nbFrameInState >= 0){
		nbFrameInState--;
	}

	if (nbFrameInState > 25) {
		nbFrameInState--;
	}
	else if(nbFrameInState < 25) {
		nbFrameInState++;
	}

	if (nbFrameInState > 40) {
		nextFrame = 4;
	}
	else if (nbFrameInState > 30) {
		nextFrame = 3;
	}
	else if (nbFrameInState > 20) {
		nextFrame = 2;
	}
	else if (nbFrameInState > 10) {
		nextFrame = 1;
	}
	else {
		nextFrame = 0;
	}
}

void Playership::init()
{
	hardLeft = sf::IntRect(182, 87, 13, 27);
	left = sf::IntRect(156, 87, 17, 28);
	neutral1 = sf::IntRect(36, 87, 22, 27);
	neutral2 = sf::IntRect(7, 87, 22, 27);
	neutral3 = sf::IntRect(65, 87, 22, 29);
	neutral4 = sf::IntRect(95, 87, 22, 30);
	right = sf::IntRect(225, 87, 17, 28);
	hardRight = sf::IntRect(203, 87, 13, 27);
}
