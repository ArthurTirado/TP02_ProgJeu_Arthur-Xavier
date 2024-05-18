#pragma once
#include "Scene.h"

class LeaderboardScene :
    public Scene
{
public:
    LeaderboardScene(SceneType type);
    virtual bool handleEvents(sf::RenderWindow& window) override;
private:
    void writeScoreInFile(std::fstream& leaderBoardFile, std::string nameAndScore);
    void removeNonAlphabeticalChars(std::string& str);
    SceneType sceneType;
    std::string rankedPlayer;
    std::string nameEnteredStr;
    sf::Text nameEntered;
    sf::Text score;
    sf::Text arrayPlaces[5];
    int numLines = 0;
    int posY = 0;
};

