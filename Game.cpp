/*
 Brandon Ellis
 csce 315-503
 individual project 1 - achievement tracker
 
 Game.cpp - master
*/

#include "Game.h"
#include <algorithm>

using namespace std;

Game::Game(int gID, string gName){
    
    gameID = gID;
    gameName = gName;
    possibleAchievements.clear();
}

Game::Game(){
    
    gameID = -1;
    gameName = "";
    possibleAchievements.clear();
}

Game::~Game(){
    
    possibleAchievements.clear();
}

bool Game::operator < (const Game& tmpGame) const{
    return (gameID < tmpGame.gameID);
}

void Game::pushBackAchievement(Achievement tempAchieve){
    
    int tempAchieveID = tempAchieve.getAchievementID();
    int found = checkForAchievementID(tempAchieveID);
    
    if (found != -1){
       // throw runtime_error("ERROR pushBackAchievement: AchievementID already exists.");
    }
    else{
        possibleAchievements.push_back(tempAchieve);
        sort(possibleAchievements.begin(), possibleAchievements.end());
    }
}

int Game::checkForAchievementID(int target_AchID){
    
    if(possibleAchievements.size() == 0)
        return -1;
    else{
        int mid = 0, low = 0, high = possibleAchievements.size();
        while(low <= high){
            mid = low + (high-low)/2;
            if (possibleAchievements[mid].getAchievementID() == target_AchID){
                return mid;
            }
            else if (possibleAchievements[mid].getAchievementID() < target_AchID){
                low = mid + 1;
            }
            else if (possibleAchievements[mid].getAchievementID() > target_AchID){
                high = mid - 1;
            }
        }
        return -1;
    }
}

Achievement Game::getAchievementByID(int achievementID){
    
    int achivementIndex = checkForAchievementID(achievementID);
    
    if (achivementIndex == -1){
       // throw runtime_error("ERROR getAchievementByID: Cannot be awarded an achievement that does not exist.");
    }
    
    return possibleAchievements[achivementIndex];
    
}









