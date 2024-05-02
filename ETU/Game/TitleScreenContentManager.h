#pragma once
class TitleScreenContentManager
{
public:
	TitleScreenContentManager();
	virtual bool loadContent();

	const sf::Texture& getBackgroundTexture() const;
	const sf::Font& getTitleFont() const;
private:
	sf::Texture backgroundTexture;
	sf::Font titleFont;
};

