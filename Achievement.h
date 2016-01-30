/*
 Brandon Ellis
 csce 315-503
 individual project 1 - achievement tracker
 
 Achievement.h - branch1
 */
#include "string"
#include "vector"

using namespace std;

class Achievement{
    int achievementID;
    string achievementName;
    int points;
    
public:
    Achievement(int achID, string achName, int achPoints);
    
    bool operator < (const Achievement& tmpAchievement) const;
    
    //getters
    string getAchievementName() { return achievementName; }
    int getAchievementID() { return achievementID; }
    int getPoints() { return points; }
};