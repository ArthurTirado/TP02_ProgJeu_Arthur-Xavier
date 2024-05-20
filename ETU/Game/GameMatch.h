#pragma once
#include "Scene.h"
#include "ContentManager.h"
#include "TitleScreenContentManager.h"

class GameMatch :
    public Scene
{
public:
    static const float SCROLL_SPEED;
    static const int BULLETS_MAX;
    static const float BULLET_RECOIL;
    static const int CONTROLLER_DEAD_ZONE;
    static const float GAMEPAD_SPEEDRATIO;
    static const float KEYBOARD_SPEED;




    // Héritées via Scene
    GameMatch();
    ~GameMatch();

    SceneType update() override;
    void draw(sf::RenderWindow& window) const override;
    bool init() override;
    bool uninit() override;
    bool handleEvents(sf::RenderWindow& window) override;
private:
    sf::Texture menuImageTexture;
    sf::Sprite menuImage;
    sf::Text gameTitle;
    sf::Text prompt;
    sf::Music titleScreenMusic;
    sf::RectangleShape blackBar;
    TitleScreenContentManager contentManager;
    bool passToGameMatch;

};


