/*
 Brandon Ellis
 csce 315-503
 individual project 1 - achievement tracker
 
 Player.h - branch1
*/

#include "GamePlay.h"
#include "string"
#include "vector"

using namespace std;

class Player{
    
    int PlayerID;
    string PlayerName;
    vector<GamePlay> gameHistory;
    vector<Player> listFriends;
    
public:
    
    Player(int pID, string pName);
};