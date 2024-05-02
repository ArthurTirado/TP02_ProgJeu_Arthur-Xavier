#pragma once
#include "Scene.h"
#include "ContentManager.h"
#include "TitleScreenContentManager.h"

class TitleScene :
    public Scene
{
public:
   static const std::string GAME_NAME;
   static const std::string PROMPT;
   static const int TITLE_TEXT_SIZE;
   static const int SMALL_TEXT_SIZE;



  // Héritées via Scene
  TitleScene();
  ~TitleScene();
  virtual SceneType update() override;
  virtual void draw(sf::RenderWindow& window) const override;
  virtual bool init() override;
  virtual bool uninit() override;
  virtual bool handleEvents(sf::RenderWindow& window) override;
private:
  sf::Texture menuImageTexture;
  sf::Sprite menuImage;
  sf::Text gameTitle;
  sf::Text prompt;
  sf::Music titleScreenMusic;
  sf::RectangleShape blackBar;
  TitleScreenContentManager contentManager;
};

