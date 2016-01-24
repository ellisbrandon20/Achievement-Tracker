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
    int playerID;
    string playerName;
    vector<GamePlay> gameHistory;
    vector<Player> listFriends;
    
public:
    Player(int pID, string pName);
    bool operator < (const Player& tmpPlayer) const;
    
    string getPlayerName() { return playerName; }
    int getPlayerID() { return playerID; }
};