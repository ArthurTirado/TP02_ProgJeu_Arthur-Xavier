#include "stdafx.h"
#include "TitleScreenContentManager.h"

TitleScreenContentManager::TitleScreenContentManager()
{
}

bool TitleScreenContentManager::loadContent()
{

    if (!backgroundTexture.loadFromFile("Assets\\Sprites\\Title\\Title.png"))
        return false;
    else
        backgroundTexture.setRepeated(true);
    if (!titleFont.loadFromFile("Assets\\Fonts\\Level01\\emulogic.ttf"))
        return false;

    return true;
}


const sf::Texture& TitleScreenContentManager::getBackgroundTexture() const
{
    return backgroundTexture;
}

const sf::Font& TitleScreenContentManager::getTitleFont() const
{
    return titleFont;
}
