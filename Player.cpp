/*
 Brandon Ellis
 csce 315-503
 individual project 1 - achievement tracker
 
 Player.cpp - branch1
*/

#include "Player.h"

using namespace std;

Player::Player(int pID, string pName){
    playerID = pID;
    playerName = pName;
    gameHistory.clear();
    friendsList.clear();
}

bool Player::operator < (const Player& tmpPlayer) const{
    return (playerID < tmpPlayer.playerID);
}

void Player::pushBackGamePlay(GamePlay tempGamePlay){
    gameHistory.push_back(tempGamePlay);
    sort(gameHistory.begin(), gameHistory.end());
}

void Player::pushBackFriend(int playerID){
    friendsList.push_back(playerID);
    sort(friendsList.begin(), friendsList.end());
}

int Player::checkForGameIDinGameHist(vector<GamePlay>& gameHist, int gameID){
    
    
    if(gameHist.size() == 0)
        return -1;
    else{
        int mid = 0, low = 0, high = gameHist.size();
        while(low <= high){
            mid = low + (high-low)/2;
            if (gameHist[mid].getGamePlayID() == gameID){
                return mid;
            }
            else if (gameHist[mid].getGamePlayID() < gameID){
                low = mid + 1;
            }
            else if (gameHist[mid].getGamePlayID() > gameID){
                high = mid - 1;
            }
        }
        return -1;
    }

    
    
    
}

void Player::pushBackAchievement(int gameID, Achievement trophy){
    //search for gameID in gameHistory
    int gameIDgamehist_index = checkForGameIDinGameHist(gameHistory, gameID); // returns index
    
    if (gameIDgamehist_index == -1){
        throw runtime_error("ERROR pushBackAchievement: the player has not played this game yet.");
    }
    
    gameHistory[gameIDgamehist_index].pushBackTrophy(trophy);

}
