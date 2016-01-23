/*
 Brandon Ellis
 csce 315-503
 individual project 1 - achievement tracker
 
 Player.cpp - branch1
*/

#include "Player.h"

using namespace std;

Player::Player(int pID, string pName){
    PlayerID = pID;
    PlayerName = pName;
    gameHistory.clear();
    listFriends.clear();
}