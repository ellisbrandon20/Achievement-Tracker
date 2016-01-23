/*
 Brandon Ellis
 csce 315-503
 individual project 1 - achievement tracker
 
 Achievement.h - branch1
 */

#include "Achievement.h"

using namespace std;

Achievement::Achievement(int achID, string achName, int achPoints){
    AchievementID = achID;
    AchievementName = achName;
    points = achPoints;
}