/*
 Brandon Ellis
 csce 315-503
 individual project 1 - achievement tracker
 
 Game.h - branch1
*/
#include "Achievement.h"
#include "string"
#include "vector"

using namespace std;

class Game{
    int gameID;
    string gameName;
    vector<Achievement> possibleAchievements;
    
public:
    Game(int gID, string gName);
    Game();
    bool operator < (const Game& tmpGame) const;
};