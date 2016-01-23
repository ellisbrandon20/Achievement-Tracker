/*
 Brandon Ellis
 csce 315-503
 individual project 1 - achievement tracker
 
 Game.h - branch1
 */

#include "Game.h"

using namespace std;

Game::Game(int gID, string gName){
    gameID = gID;
    gameName = gName;
    possibleAchievements.clear();
}

Game::Game(){}

bool Game::operator < (const Game& tmpGame) const{
    return (gameID < tmpGame.gameID);
}