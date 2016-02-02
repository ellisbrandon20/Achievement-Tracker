/*
 Brandon Ellis
 csce 315-503
 individual project 1 - achievement tracker
 
 Achievement.cpp - master
*/

#include "Achievement.h"

using namespace std;

Achievement::Achievement(int achID, string achName, int achPoints){
   
    achievementID = achID;
    achievementName = achName;
    points = achPoints;
}

Achievement::Achievement(){
    achievementID = -1;
    achievementName = "";
    points = -1;
}

Achievement::~Achievement() { }

bool Achievement::operator < (const Achievement& tmpAchievement) const{
    
    return (achievementID < tmpAchievement.achievementID);
}