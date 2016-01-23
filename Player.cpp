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
    listFriends.clear();
}

bool Player::operator < (const Player& tmpPlayer) const{
    return (playerID < tmpPlayer.playerID);
}