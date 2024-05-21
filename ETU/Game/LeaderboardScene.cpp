#include "stdafx.h"
#include "LeaderboardScene.h"
#include "game.h"
#include <fstream>
#include <iostream>
#include <locale>

LeaderboardScene::LeaderboardScene()
	: Scene(SceneType::LEADERBOARD){
}
const std::string LeaderboardScene::GAME_OVER = "GAME OVER";
bool LeaderboardScene::handleEvents(sf::RenderWindow& window)
{
    bool enterHasBeenPressed = false;
    std::fstream leaderBoardFile;
    leaderBoardFile.open("Leaderboard.txt", std::ios::in | std::ios::out);
    nameEntered.setFillColor(sf::Color::Green);
    score.setFillColor(sf::Color::Green);
    nameEntered.setPosition(1000, 1000);
    score.setPosition(1200, 1000);
    // Le podium pour les 5 meilleurs joueurs
    while (std::getline(leaderBoardFile, rankedPlayer) && numLines < 5) {
        arrayPlaces[numLines].setString(rankedPlayer);
        arrayPlaces[numLines].setPosition(0, posY);
        numLines++;
        posY += 200;
    }
        
    bool retval = false;
    while (window.pollEvent(event))
    {
        //x sur la fenêtre
        if (event.type == sf::Event::Closed)
        {
            window.close();
            retval = true;
        }
        if (nameEntered.getString().getSize() < 3) {
            std::cin >> nameEnteredStr;
            removeNonAlphabeticalChars(nameEnteredStr);
            nameEntered.setString(nameEnteredStr);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && !nameEntered.getString().isEmpty()) {
            nameEntered.setString(nameEntered.getString().getSize() - 1);
        }
        if (nameEntered.getString().getSize() == 3) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                //Besoin score joueur
                nameEntered.setString(nameEntered.getString() + "score");
                writeScoreInFile(leaderBoardFile, nameEntered.getString());
                leaderBoardFile.close();
                enterHasBeenPressed = true;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && enterHasBeenPressed) {
                // Retour menu principal
                SceneType::TITLE_SCENE;
            }
        }
    }
    return retval;
}
bool LeaderboardScene::init()
{
    if (!contentManager.loadContent())
        return false;
    background.setTexture(contentManager.getBackgroundTexture());
    background.setOrigin(background.getTexture()->getSize().x / 2.0f, background.getTexture()->getSize().y / 2.0f);
    background.setPosition(Game::GAME_WIDTH / 2.0f, Game::GAME_HEIGHT / 2.0f);
    gameOverText.setFont(contentManager.getMainFont());
    gameOverText.setCharacterSize(30);
    gameOverText.setOutlineColor(sf::Color::Red);
    gameOverText.setString(GAME_OVER);
    gameOverText.setPosition((Game::GAME_WIDTH - (gameOverText.getLocalBounds().width)) / 2, Game::GAME_HEIGHT / 4);


    return true;
}

SceneType LeaderboardScene::update()
{
    return getSceneType();
}

void LeaderboardScene::draw(sf::RenderWindow& window) const
{
    window.draw(background);
    window.draw(gameOverText);
}

bool LeaderboardScene::uninit()
{
    return true;
}

void LeaderboardScene::writeScoreInFile(std::fstream& leaderBoardFile, std::string nameAndScore) {
    int playerScore = std::stoi(nameAndScore);
    while (std::getline(leaderBoardFile, rankedPlayer)) {
        int score = std::stoi(rankedPlayer);
        if (playerScore > score) {
            // Mettre nouveau score \n score \n
            leaderBoardFile << nameAndScore << "\n";
            leaderBoardFile << rankedPlayer << "\n";
            break;
        }
    }
    leaderBoardFile << "name 1000 \n";
}

void LeaderboardScene::removeNonAlphabeticalChars(std::string& str) {
    // https://cplusplus.com/reference/locale/isalpha/
    std::locale loc;
    for (std::string::iterator i = str.begin(); i != str.end(); ++i) {
        if (std::isalpha(*i, loc)) {
            str.erase(i);
            i--;
        }
    }
}