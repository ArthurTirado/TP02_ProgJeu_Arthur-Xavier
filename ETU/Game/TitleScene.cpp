#include "stdafx.h"
#include "TitleScene.h"

#include "game.h"

const std::string TitleScene::GAME_NAME = "SPACE SHOOTER";
const std::string TitleScene::PROMPT = "(Press any key to start!)";
const int TitleScene::TITLE_TEXT_SIZE = 50;
const int TitleScene::SMALL_TEXT_SIZE = 15;


TitleScene::TitleScene()
  : Scene(SceneType::TITLE_SCENE)
{

}

TitleScene::~TitleScene()
{

}
SceneType TitleScene::update()
{
  return getSceneType();
}

void TitleScene::draw(sf::RenderWindow& window) const
{
  window.draw(menuImage);
  window.draw(blackBar);
  window.draw(gameTitle);
  window.draw(prompt);
}

bool TitleScene::init()
{
  if (!contentManager.loadContent())
    return false;
  menuImage.setTexture(contentManager.getBackgroundTexture());
  menuImage.setOrigin(menuImage.getTexture()->getSize().x / 2.0f, menuImage.getTexture()->getSize().y / 2.0f);
  menuImage.setPosition(Game::GAME_WIDTH / 2.0f, Game::GAME_HEIGHT / 2.0f);
  gameTitle.setFont(contentManager.getTitleFont());  
  gameTitle.setCharacterSize(TITLE_TEXT_SIZE);
  gameTitle.setOutlineColor(sf::Color::White);
  gameTitle.setString(GAME_NAME);
  gameTitle.setPosition((Game::GAME_WIDTH - (gameTitle.getLocalBounds().width)) / 2, Game::GAME_HEIGHT / 1.5f);

  prompt.setFont(contentManager.getTitleFont());
  prompt.setCharacterSize(SMALL_TEXT_SIZE);
  prompt.setOutlineColor(sf::Color::White);
  prompt.setString(PROMPT);
  prompt.setPosition((Game::GAME_WIDTH - (prompt.getLocalBounds().width)) / 2, Game::GAME_HEIGHT / 1.25f);

  blackBar.setSize(sf::Vector2f(Game::GAME_WIDTH, gameTitle.getLocalBounds().height * 2));
  blackBar.setFillColor(sf::Color::Black);
  blackBar.setPosition((Game::GAME_WIDTH - (blackBar.getLocalBounds().width)) / 2, gameTitle.getPosition().y -40);

  if (!titleScreenMusic.openFromFile("Assets\\Music\\Title\\SkyFire (Title Screen).ogg"))
      return false;
  titleScreenMusic.setLoop(true);
  titleScreenMusic.play();

  return true;
}

bool TitleScene::uninit()
{
  return true;
}

bool TitleScene::handleEvents(sf::RenderWindow& window)
{
  bool retval = false;
  sf::Event event;
  while (window.pollEvent(event))
  {
    //x sur la fenêtre
    if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || sf::Joystick::isButtonPressed(0, 1))
    {
      window.close();
      retval = true;
    }
    else {
        SceneType::GAME_SCENE;
        titleScreenMusic.stop();
    }
  }
  return retval;
}
