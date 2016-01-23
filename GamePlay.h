/*
 Brandon Ellis
 csce 315-503
 individual project 1 - achievement tracker
 
 GamePlay.h - branch1
 */

#include "Game.h"
#include "string"
#include "vector"

using namespace std;

class GamePlay: public Game{

    string PlayerIGN;
    int GamePlayID;
    vector<Achievement> awardedAchievements;
    
public:
    
    GamePlay(int gID, string pIGN);
};