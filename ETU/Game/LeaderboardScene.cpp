#include "stdafx.h"
#include "LeaderboardScene.h"
#include <fstream>
#include <iostream>

LeaderboardScene::LeaderboardScene(SceneType type)
	: Scene(type)
	, sceneType(type){
}

bool LeaderboardScene::handleEvents(sf::RenderWindow& window)
{
    leaderBoardFile.open("Leaderboard.txt");
    nameEntered.setColor(sf::Color::Green);
    nameEntered.setPosition(1000, 1000);
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
                nameEntered = nameEntered.getString() + "score";
                writeScoreInFile(leaderBoardFile, nameEntered.getString());
                leaderBoardFile.close();
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                // Retour menu principal
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
            leaderBoardFile << nameAndScore "\n";
            leaderBoardFile << rankedPlayer "\n";
        }
    }
    leaderBoardFile << "name 1000 \n";
}

void LeaderboardScene::removeNonAlphabeticalChars(std::string& str) {
    for (int i : str) {
        if (std::isalpha(i)) {
            str.erase(i);
        }
    }
}