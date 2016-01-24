/*
 Brandon Ellis
 csce 315-503
 individual project 1 - achievement tracker
 
 Game.h - branch1
 */

#include "Game.h"

using namespace std;

Game::Game(int gID, string gName){
    gameID = gID;
    gameName = gName;
    possibleAchievements.clear();
}

Game::Game(){}

bool Game::operator < (const Game& tmpGame) const{
    return (gameID < tmpGame.gameID);
}

void Game::pushBackAchievement(Achievement tempAchieve){
    
    bool found = false;
    //check that Achievement ID doesn't exist
    if(possibleAchievements.size() == 0)
        found = false;
    else{
        int mid = 0, low = 0, high = possibleAchievements.size();
        while(low <= high){
            mid = low + (high-low)/2;
            if (possibleAchievements[mid].getAchievementID() == tempAchieve.getAchievementID()){
                found = true;
                break;
            }
            else if (possibleAchievements[mid].getAchievementID() < tempAchieve.getAchievementID()){
                low = mid + 1;
            }
            else if (possibleAchievements[mid].getAchievementID() > tempAchieve.getAchievementID()){
                high = mid - 1;
            }
        }
    }
    
    if (found){
        throw runtime_error("ERROR pushBackAchievement: AchievementID already exists.");
    }
    else{
        possibleAchievements.push_back(tempAchieve);
        sort(possibleAchievements.begin(), possibleAchievements.end());
    }
}









