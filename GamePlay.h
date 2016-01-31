/*
 Brandon Ellis
 csce 315-503
 individual project 1 - achievement tracker
 
 GamePlay.h
 
    Notes about Class:
 
    The class stores all the information about Players Gameplay of a specific game
        - playerIGN = the palyers username for the game
        - gamePlayID = the gameID that the user played
        - awardedAchievements = record of achievements the player earned when playing this game
    
    I kept these stored in order by gamePlayID to so I can use binary search algorithm
      when I needed to locate a specific item
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
    GamePlay();
    ~GamePlay();
    bool operator < (const GamePlay& tempGamePlay) const;
    
    //getters
    string getPlayerIGN() { return playerIGN; }
    int getGamePlayID() { return gamePlayID; }
    vector<Achievement> getAwardedAchievements() { return awardedAchievements; }
    
    //methods
    void pushBackTrophy(Achievement trophy);
    
};