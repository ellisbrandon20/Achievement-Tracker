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