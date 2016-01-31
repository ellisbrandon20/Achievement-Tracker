/*
 Brandon Ellis
 csce 315-503
 individual project 1 - achievement tracker
 
 Achievement.h
 
    Notes about this Class:
 
    This class stores all information about Achievements
        - Achievement ID
        - Achievement Name
        - Achievement Points
    
    I decided to keep vectors of type Achievement in order by ID to easily be able to search
      for an Achievement with binary search algorithm
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
    Achievement();
    ~Achievement();
    
    bool operator < (const Achievement& tmpAchievement) const;
    
    //getters
    string getAchievementName() { return achievementName; }
    int getAchievementID() { return achievementID; }
    int getPoints() { return points; }
};