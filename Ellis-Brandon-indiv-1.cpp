/*
Brandon Ellis
csce 315-503
individual project 1 - achievement tracker

main.cpp - branch1
*/



/*

        NOTES TO SELF:
        
        - use gameID and playerID to put the entries in increasing order so when you need to
            search for a specified game/player you can use a binary search.
            -- possibly achievementID as well ????
        
        - need to allow NEWLINES in input file



*/



#include <iostream>
#include <string>
#include <sstream>
#include <vector>


#include "Player.h"
//#include "Game.h"
//#include "GamePlay.h"
//#include "Achievement.h"

using namespace std;


// ======================== helper Funcitons ========================
void help(){
    // function to list all commands
    cout << "\t\tHELP:" << endl;
    cout << "AddPlayer <Player ID> <Player Name>" << endl;
    cout << "AddGame <Game ID> <Game Name>" << endl;
    cout << "AddAchievement <Game ID> <Achievement ID> <Achievement Name> <Achievement Points>" << endl;
    cout << "Plays <Player ID> <Game ID> <Player IGN>" << endl;
    cout << "AddFriends <Player ID1> <Player ID2>" << endl;
    cout << "Achieve <Player ID> <Game ID> <Achievement ID>" << endl;
    cout << "FriendsWhoPlay <Player ID> <Game ID>" << endl;
    cout << "ComparePlayers <Player ID1> <Player ID2> <Game ID>" << endl;
    cout << "SummarizePlayer <Player ID>" << endl;
    cout << "SummarizeGame <Game ID>" << endl;
    cout << "SummarizeAchievement <Game ID> <Achievement ID>" << endl;
    cout << "AchievementRanking" << endl;
    cout << "To quit type in \"q\"" << endl;
    cout << "\n";
}

string truncQuotes(string str){
    str.erase(str.begin(), str.begin()+2);
    str.erase(str.end()-1, str.end());
    return str;
}

// ======================== Command Funcitons ========================
void AddPlayer(int PlayerID, string PlayerName){
    /**/
    cout << "PlayerID: " << PlayerID
         << "\nPlayerName: " << PlayerName << endl;
    //Player* tempPlayer = new Player(PlayerID, PlayerName);
    //Player tempPlayer(PlayerID, PlayerName);
    //Player_DB.push_back(tempPlayer);
}

void AddGame(int GameID, string GameName){
    /**/
    cout << "GameID: " << GameID
         << "\nGameName: " << GameName << endl;
}

void AddAchievement(int GameID, int AchievementID, string AchievementName, int AchievementPoints){
    /*
    */
    cout << "GameID: " << GameID
    << "\nAchID: " << AchievementID
    << "\nAchName: " << AchievementName
    << "\nAchPoints: " << AchievementPoints << endl;
}

void Plays(int PlayerID, int GameID, string PlayerIGN){
    /**/
    cout << "PlayerID: " << PlayerID
    << "\nGameID: " << GameID
    << "\nPlayerIGN: " << PlayerIGN << endl;
}

void AddFriends(int PlayerID_1, int PlayerID_2){
    /**/
    cout << "PlayerID_1: " << PlayerID_1
    << "\nPlayerID_2: " << PlayerID_2 << endl;
}

void Achieve(int PlayerID, int GameID, int AchievementID){
    /**/
    cout << "PlayerID: " << PlayerID
    << "\nGameID: " << GameID
    << "\nAchID: " << AchievementID << endl;
}

void FriendsWhoPlay(int PlayerID, int GameID){
    /*
        retrieve vector_friends of PlayerID
        for each Player in vector_friends
                within vector_gamge_history
                binary search for gameID
                if found == true --> report player to console
    */
    cout << "PlayerID: " << PlayerID
    << "\nGameID: " << GameID << endl;
}

void ComparePlayers(int PlayerID_1, int PlayerID_2, int GameID){
    /**/
    cout << "PlayerID_1: " << PlayerID_1
    << "\nPlayerID_2: " << PlayerID_2
    << "\nGameID: " << GameID << endl;
}

void SummarizePlayer(int PlayerID){
    /**/
    cout << "PlayerID: " << PlayerID << endl;
}

void SummarizeGame(int GameID){
    /**/
    cout << "GameID: " << GameID << endl;
}

void SummarizeAchievement(int GameID, int AchievementID){
    /**/
    cout << "GameID: " << GameID
    << "\nAchID: " << AchievementID << endl;
}

void AchievementRanking(){
    /**/
    cout << "AchRanking" << endl;
}
// ====================== End Command Funcitons ======================



// ======================== Main ========================
int main(){
    try{
        
        vector<Player> Player_DB;
        vector<Game> Game_DB;
        
        
        cout << "\nHello welcome to Achievement Tracker" << endl;
        cout << "To begin type in the command you wish to run with the correct credentials" << endl;
        cout << "or type \"help\" to list the available commands." << endl;
        cout << "to quit simple type \"q\"" << endl;
        
        cout << "----------------\n";
        
        string cmd;
        cin >> cmd;
        
        while(cmd != "q"){
            if (cmd == "help"){
                help();
            }
            else if (cmd == "AddPlayer"){
                int PlayerID;
                string PlayerName;
            
                cin >> PlayerID;
                if(cin.fail()) throw runtime_error("ERROR ADDPLAYER: Incorrect input for PlayerID\n");
                getline(cin, PlayerName);
                
                PlayerName = truncQuotes(PlayerName);
                
                AddPlayer(PlayerID, PlayerName);
            }
            else if (cmd == "AddGame"){
                int GameID;
                string GameName;
                
                cin >> GameID;
                if(cin.fail()) throw runtime_error("ERROR ADDGAME: Incorrect input for GameID\n");
                getline(cin, GameName);

                GameName = truncQuotes(GameName);
                
                AddGame(GameID, GameName);
            }
            else if (cmd == "AddAchievement"){
                int GameID;
                int AchievementID;
                int AchievementPoints;
                
                cin >> GameID;
                if(cin.fail()) throw runtime_error("ERROR ADDACHIEVEMENT: Incorrect input for GameID\n");
                cin >> AchievementID;
                if(cin.fail()) throw runtime_error("ERROR ADDACHIEVEMENT: Incorrect input for AchievementID\n");

                char ch = getchar();
                
                while (ch != '"')
                    ch = getchar();
                
                ch = getchar();
                
                vector<char> vAchName;
                
                while(ch != '"'){
                    vAchName.push_back(ch);
                    ch = getchar();
                }
                
                string AchievementName(vAchName.begin(), vAchName.end());
                
                cin >> AchievementPoints;
                if(cin.fail()) throw runtime_error("ERROR ADDACHIEVEMENT: Incorrect input for AchievementPoints\n");
                
                AddAchievement(GameID, AchievementID, AchievementName, AchievementPoints);
                
            }
            else if (cmd == "Plays"){
                int PlayerID;
                int GameID;
                string PlayerIGN; //not enclosed with quotation marks
                
                cin >> PlayerID;
                if(cin.fail()) throw runtime_error("ERROR PLAYS: Incorrect input for PlayerID\n");
                cin >> GameID;
                if(cin.fail()) throw runtime_error("ERROR PLAYS: Incorrect input for GameID\n");
                cin >> PlayerIGN;
                if(cin.fail()) throw runtime_error("ERROR PLAYS: Incorrect input for PlayerIGN\n");
                
                Plays(PlayerID, GameID, PlayerIGN);
            }
            else if (cmd == "AddFriends"){
                int PlayerID_1;
                int PlayerID_2;
                
                cin >> PlayerID_1;
                if(cin.fail()) throw runtime_error("ERROR ADDFRIENDS: Incorrect input for PlayerID_1\n");
                cin >> PlayerID_2;
                if(cin.fail()) throw runtime_error("ERROR ADDFRIENDS: Incorrect input for PlayerID_2\n");
                
                AddFriends(PlayerID_1, PlayerID_2);

            }
            else if (cmd == "Achieve"){
                int PlayerID;
                int GameID;
                int AchievementID;
                
                cin >> PlayerID;
                if(cin.fail()) throw runtime_error("ERROR ACHIEVE: Incorrect input for PlayerID\n");
                cin >> GameID;
                if(cin.fail()) throw runtime_error("ERROR ACHIEVE: Incorrect input for GameID\n");
                cin >> AchievementID;
                if(cin.fail()) throw runtime_error("ERROR ACHIEVE: Incorrect input for AchievementID\n");
                
                Achieve(PlayerID, GameID, AchievementID);
            }
            else if (cmd == "FriendsWhoPlay"){
                int PlayerID;
                int GameID;
                
                cin >> PlayerID;
                if(cin.fail()) throw runtime_error("ERROR FRIENDSWHOPLAY: Incorrect input for PlayerID\n");
                cin >> GameID;
                if(cin.fail()) throw runtime_error("ERROR FRIENDSWHOPLAY: Incorrect input for GameID\n");
                
                FriendsWhoPlay(PlayerID, GameID);
            }
            else if (cmd == "ComparePlayers"){
                int PlayerID_1;
                int PlayerID_2;
                int GameID;
                
                cin >> PlayerID_1;
                if(cin.fail()) throw runtime_error("ERROR COMPAREPLAYERS: Incorrect input for PlayerID_1\n");
                cin >> PlayerID_2;
                if(cin.fail()) throw runtime_error("ERROR COMPAREPLAYERS: Incorrect input for PlayerID_2\n");
                cin >> GameID;
                if(cin.fail()) throw runtime_error("ERROR COMPAREPLAYERS: Incorrect input for GameID\n");
                
                ComparePlayers(PlayerID_1, PlayerID_2, GameID);
            }
            else if (cmd == "SummarizePlayer"){
                int PlayerID;
                
                cin >> PlayerID;
                if(cin.fail()) throw runtime_error("ERROR SUMMARIZEPLAYER: Incorrect input for PlayerID\n");
                
                SummarizePlayer(PlayerID);
            }
            else if (cmd == "SummarizeGame"){
                int GameID;
                
                cin >> GameID;
                if(cin.fail()) throw runtime_error("ERROR SUMMARIZEGAME: Incorrect input for GameID\n");
                
                SummarizeGame(GameID);
            }
            else if (cmd == "SummarizeAchievement"){
                int GameID;
                int AchievementID;
                
                cin >> GameID;
                if(cin.fail()) throw runtime_error("ERROR SUMMARIZEGAME: Incorrect input for GameID\n");
                cin >> AchievementID;
                if(cin.fail()) throw runtime_error("ERROR SUMMARIZEGAME: Incorrect input for AchievementID\n");
                
                SummarizeAchievement(GameID,AchievementID);
            }
            else if (cmd == "AchievementRanking"){
                    AchievementRanking();
            }
            else{
                throw runtime_error("ERROR COMMAND: Incorrect command re-run and try again.\n");
            }
            
            cout << "----------------\n";
            cin >> cmd;
        }
        
        return 0;
    }
    catch (const runtime_error& e){
        cout << e.what();
        return 1;
    }
}












