/*
 Brandon Ellis
 csce 315-503
 individual project 1 - achievement tracker
 
 Player.h
 
    Notes about Class:
 
    This class stores all information about players:
        - ID
        - Name
        - total Gamerscore
        - record of Games the player plays
        - record of friends list. I chose to only store the IDs in this so I wouldn't have
            to deal with data being copying over and repeated in multiple locations
 
    In Main, I have the player database ordered by ID so when I need to find a specific player
       I can use the binary search algorithm to quickly find that person
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
    Player();
    ~Player();
    
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