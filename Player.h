/*
 Brandon Ellis
 csce 315-503
 individual project 1 - achievement tracker
 
 Player.h - master
*/

#include "GamePlay.h"
#include "string"
#include "vector"

using namespace std;

class Player{
    int playerID;
    string playerName;
    int gamerScore;
    vector<GamePlay> gameHistory;
    vector<int> friendsList;
    
public:
    Player(int pID, string pName);
    bool operator < (const Player& tmpPlayer) const;

    //getters
    string getPlayerName() { return playerName; }
    int getPlayerID() { return playerID; }
    int getGamerScore() { return gamerScore; }
    vector<GamePlay> getGameHistory() { return gameHistory; }
    vector<int> getFriendsList() { return friendsList; }
    
    //methods
    void pushBackGamePlay(GamePlay tempGamePlay);
    void pushBackFriend(int playerID);
    void pushBackAchievement(int gameID, Achievement trophy);
    int checkForGameIDinGameHist(vector<GamePlay>& gameHist, int gameID);
};