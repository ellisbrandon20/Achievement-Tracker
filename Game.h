/*
 Brandon Ellis
 csce 315-503
 individual project 1 - achievement tracker
 
 Game.h
 
     Notes about Class:
     
     This class stores all information about Games:
         - ID
         - Name
         - record of possible Achievements that a player can achieve
     
     In Main, I have the game database ordered by ID so when I need to find a specific game
     I can use the binary search algorithm to quickly find it

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
    ~Game();
    
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