#pragma once
#include "Scene.h"
#include "ContentManager.h"

class LeaderboardScene :
    public Scene
{
public:
    static const std::string GAME_OVER;
    LeaderboardScene();
    virtual bool handleEvents(sf::RenderWindow& window) override;
    virtual SceneType update() override;
    virtual void draw(sf::RenderWindow& window) const override;
    virtual bool init() override;
    virtual bool uninit() override;
private:
    void writeScoreInFile(std::fstream& leaderBoardFile, std::string nameAndScore);
    void removeNonAlphabeticalChars(std::string& str);
    std::string rankedPlayer;
    std::string nameEnteredStr;
    sf::Text gameOverText;
    sf::Text nameEntered;
    sf::Text score;
    sf::Text arrayPlaces[5];
    ContentManager contentManager;
    sf::Sprite background;
    int numLines = 0;
    int posY = 0;
};

