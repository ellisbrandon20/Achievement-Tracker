/*
 Brandon Ellis
 csce 315-503
 individual project 1 - achievement tracker
 
 GamePlay.cpp - master
*/

#include "GamePlay.h"
#include <algorithm>

using namespace std;

GamePlay::GamePlay(int gID, string pIGN){
    
    playerIGN = pIGN;
    gamePlayID = gID;
    awardedAchievements.clear();
}

GamePlay::GamePlay(){
    
    playerIGN = "";
    gamePlayID = -1;
    awardedAchievements.clear();
}

GamePlay::~GamePlay(){
    
    awardedAchievements.clear();
}

bool GamePlay::operator < (const GamePlay& tempGamePlay) const{
    
    return (gamePlayID < tempGamePlay.gamePlayID);
}


void GamePlay::pushBackTrophy(Achievement trophy){
    
    awardedAchievements.push_back(trophy);
    sort(awardedAchievements.begin(), awardedAchievements.end());
}