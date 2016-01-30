/*
 Brandon Ellis
 csce 315-503
 individual project 1 - achievement tracker
 
 GamePlay.h - master
 */

#include "Game.h"
#include "string"
#include "vector"

using namespace std;

class GamePlay: public Game{

    string playerIGN;
    int gamePlayID;
    vector<Achievement> awardedAchievements;
    
public:
    GamePlay(int gID, string pIGN);
    bool operator < (const GamePlay& tempGamePlay) const;
    
    //getters
    string getPlayerIGN() { return playerIGN; }
    int getGamePlayID() { return gamePlayID; }
    vector<Achievement> getAwardedAchievements() { return awardedAchievements; }
    
    //methods
    void pushBackTrophy(Achievement trophy);
    
};