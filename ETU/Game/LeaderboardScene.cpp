#include "stdafx.h"
#include "LeaderboardScene.h"
#include <fstream>
#include <iostream>
#include <locale>

LeaderboardScene::LeaderboardScene(SceneType type)
    : Scene(type)
    , sceneType(type) {
}

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
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && enterHasBeenPressed) {
                // Retour menu principal
                SceneType::TITLE_SCENE;
                sceneType = TITLE_SCENE;
            }
        }
    }
    return retval;
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
