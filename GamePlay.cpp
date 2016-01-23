/*
 Brandon Ellis
 csce 315-503
 individual project 1 - achievement tracker
 
 GamePlay.h - branch1
 */

#include "GamePlay.h"

using namespace std;

GamePlay::GamePlay(int gID, string pIGN){
    PlayerIGN = pIGN;
    GamePlayID = gID;
    awardedAchievements.clear();
}