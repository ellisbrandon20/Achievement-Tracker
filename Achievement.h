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
    
    int AchievementID;
    string AchievementName;
    int points;
    
public:
    
    Achievement(int achID, string achName, int achPoints);
};