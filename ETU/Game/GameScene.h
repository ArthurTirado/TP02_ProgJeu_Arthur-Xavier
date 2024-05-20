#pragma once
#include "Scene.h"
#include "ContentManager.h"
#include "Inputs.h"

class GameScene :
    public Scene
{
public:

    static const float SCROLL_SPEED;
    static const int CONTROLLER_DEAD_ZONE;
    static const float GAMEPAD_SPEEDRATIO;
    static const float KEYBOARD_SPEED;

    // Héritées via Scene
    GameScene();
    ~GameScene();
    virtual SceneType update() override;
    virtual void draw(sf::RenderWindow& window) const override;
    virtual bool init() override;
    virtual bool uninit() override;
    virtual bool handleEvents(sf::RenderWindow& window) override;
    float handleControllerDeadZone(float analogInput);
private:
    sf::Texture gameBackgroundTexture;
    sf::Sprite gameBackground;
    sf::Music titleScreenMusic;
    ContentManager contentManager;
    bool passToLeaderboard;
    Inputs inputs;
    float recoil;
};

