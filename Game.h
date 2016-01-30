/*
 Brandon Ellis
 csce 315-503
 individual project 1 - achievement tracker
 
 Game.h - master
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
    
    //getters
    int getGameID() { return gameID; }
    string getGameName() { return gameName; }
    vector<Achievement> getAchievementVector() {return possibleAchievements;}
    Achievement getAchievementByID(int achievementID);
    
    //methods
    void pushBackAchievement(Achievement tempAchieve);
    int checkForAchievementID(int target_AchID);

};