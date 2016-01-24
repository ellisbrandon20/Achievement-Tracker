/*
Brandon Ellis
csce 315-503
individual project 1 - achievement tracker

main.cpp - branch1
*/



/*

        NOTES TO SELF:
        
 
 
 
 
 - can't access the vectors that are defined inside classes !*!*!*!*!*!*!*!*!*!*!*!**!!*!*!**!*!*!*!*!*!*!**!*!*!*
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
        - ASK TA: addAchievemtn() funciton is throwing runtime error OK or do I print a cerr instead?
 
 
        
        - use gameID and playerID to put the entries in increasing order so when you need to
            search for a specified game/player you can use a binary search.
            -- possibly achievementID as well ????
 



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
    cout << "\n";
}

string truncQuotes(string str){
    
    str.erase(str.begin(), str.begin()+4);
    str.erase(str.end()-3, str.end());
    
    return str;
}

// ======================== Command Funcitons ========================
void AddPlayer(int playerID, string playerName, vector<Player> &player_DB){
    
    Player tempPlayer(playerID, playerName);
    player_DB.push_back(tempPlayer);
    sort(player_DB.begin(), player_DB.end());
}

void AddGame(int gameID, string gameName, vector<Game> &game_DB){

    Game tempGame(gameID, gameName);
    game_DB.push_back(tempGame);
    sort(game_DB.begin(), game_DB.end());
}

void AddAchievement(int target_gameID, int achievementID, string achievementName, int achievementPoints, vector<Game> &game_DB){

    vector<Achievement> possibleAchievements;
    bool found = false;
    //binary search for game_ID within game_DB and retrieve vector of possible acheivements
    int mid = 0, low = 0, high = game_DB.size();
    while(low <= high){
        mid = low + (high-low)/2;
        if (game_DB[mid].getGameID() == target_gameID){
            //possibleAchievements = game_DB[mid].getAchievementVector();
            found = true;
            //cout << "found\n";
            break;
        }
        else if (game_DB[mid].getGameID() < target_gameID)
            low = mid + 1;
        else if (game_DB[mid].getGameID() > target_gameID)
            high = mid - 1;
    }
    
    if(found){
        Achievement tempAchieve(achievementID, achievementName, achievementPoints);
        game_DB[mid].pushBackAchievement(tempAchieve);
    }
    else{
        throw runtime_error("ERROR AddAchievement: the GameID is not in the database." );
    }
}

void Plays(int PlayerID, int GameID, string PlayerIGN){
    /*
     Add entry for player playing a specific game. <Player IGN> is a string identifier for 
     that that player's particular in game name for the specified game, enclosed by double quotes.
     <Player IGN> may contain special characters (excluding double quote).
     */
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
        vector<Player> player_DB;
        vector<Game> game_DB;
        
        
        cout << "\nHello welcome to Achievement Tracker" << endl;
        cout << "To begin type in the command you wish to run with the correct credentials" << endl;
        cout << "or type \"help\" to list the available commands." << endl;
        
        //cout << "----------------\n";
        
        string cmd;
        
        while(!cin.eof()){
            cin >> cmd;
            
            
            
            
            if (cmd == "help"){
                help();
            }
            else if (cmd == "AddPlayer"){
                int playerID;
                string playerName;
            
                cin >> playerID;
                if(cin.fail()) throw runtime_error("ERROR ADDPLAYER: Incorrect input for PlayerID\n");
                getline(cin, playerName);
                
                playerName = truncQuotes(playerName);
                
                AddPlayer(playerID, playerName, player_DB);
            }
            else if (cmd == "AddGame"){
                int gameID;
                string gameName;
                
                cin >> gameID;
                if(cin.fail()) throw runtime_error("ERROR ADDGAME: Incorrect input for GameID\n");
                getline(cin, gameName);

                gameName = truncQuotes(gameName);
                
                AddGame(gameID, gameName, game_DB);
            }
            else if (cmd == "AddAchievement"){
                int gameID;
                int achievementID;
                int achievementPoints;
                
                cin >> gameID;
                if(cin.fail()) throw runtime_error("ERROR ADDACHIEVEMENT: Incorrect input for GameID\n");
                cin >> achievementID;
                if(cin.fail()) throw runtime_error("ERROR ADDACHIEVEMENT: Incorrect input for AchievementID\n");

                char ch = getchar();

                while (ch != '"'){
                    ch = getchar();
                    cout << "H";
                }
                
                ch = getchar();
                
                vector<char> vAchName;
                
                while(ch != '"'){
                    vAchName.push_back(ch);
                    ch = getchar();
                }
                
                string achievementName(vAchName.begin(), vAchName.end());

                cin >> achievementPoints;
                if(cin.fail()) throw runtime_error("ERROR ADDACHIEVEMENT: Incorrect input for AchievementPoints\n");
                
cout << "addAch: " << gameID << " " << achievementID << " " << achievementName << " " << achievementPoints << endl;
                
                AddAchievement(gameID, achievementID, achievementName, achievementPoints, game_DB);
                
            }
            else if (cmd == "Plays"){
                int playerID;
                int gameID;
                string playerIGN; //not enclosed with quotation marks
                
                cin >> playerID;
                if(cin.fail()) throw runtime_error("ERROR PLAYS: Incorrect input for PlayerID\n");
                cin >> gameID;
                if(cin.fail()) throw runtime_error("ERROR PLAYS: Incorrect input for GameID\n");
                cin >> playerIGN;
                if(cin.fail()) throw runtime_error("ERROR PLAYS: Incorrect input for PlayerIGN\n");
                
                Plays(playerID, gameID, playerIGN);
            }
            else if (cmd == "AddFriends"){
                int playerID_1;
                int playerID_2;
                
                cin >> playerID_1;
                if(cin.fail()) throw runtime_error("ERROR ADDFRIENDS: Incorrect input for PlayerID_1\n");
                cin >> playerID_2;
                if(cin.fail()) throw runtime_error("ERROR ADDFRIENDS: Incorrect input for PlayerID_2\n");
                
                AddFriends(playerID_1, playerID_2);

            }
            else if (cmd == "Achieve"){
                int playerID;
                int gameID;
                int achievementID;
                
                cin >> playerID;
                if(cin.fail()) throw runtime_error("ERROR ACHIEVE: Incorrect input for PlayerID\n");
                cin >> gameID;
                if(cin.fail()) throw runtime_error("ERROR ACHIEVE: Incorrect input for GameID\n");
                cin >> achievementID;
                if(cin.fail()) throw runtime_error("ERROR ACHIEVE: Incorrect input for AchievementID\n");
                
                Achieve(playerID, gameID, achievementID);
            }
            else if (cmd == "FriendsWhoPlay"){
                int playerID;
                int gameID;
                
                cin >> playerID;
                if(cin.fail()) throw runtime_error("ERROR FRIENDSWHOPLAY: Incorrect input for PlayerID\n");
                cin >> gameID;
                if(cin.fail()) throw runtime_error("ERROR FRIENDSWHOPLAY: Incorrect input for GameID\n");
                
                FriendsWhoPlay(playerID, gameID);
            }
            else if (cmd == "ComparePlayers"){
                int playerID_1;
                int playerID_2;
                int gameID;
                
                cin >> playerID_1;
                if(cin.fail()) throw runtime_error("ERROR COMPAREPLAYERS: Incorrect input for PlayerID_1\n");
                cin >> playerID_2;
                if(cin.fail()) throw runtime_error("ERROR COMPAREPLAYERS: Incorrect input for PlayerID_2\n");
                cin >> gameID;
                if(cin.fail()) throw runtime_error("ERROR COMPAREPLAYERS: Incorrect input for GameID\n");
                
                ComparePlayers(playerID_1, playerID_2, gameID);
            }
            else if (cmd == "SummarizePlayer"){
                int playerID;
                
                cin >> playerID;
                if(cin.fail()) throw runtime_error("ERROR SUMMARIZEPLAYER: Incorrect input for PlayerID\n");
                
                SummarizePlayer(playerID);
            }
            else if (cmd == "SummarizeGame"){
                int gameID;
                
                cin >> gameID;
                if(cin.fail()) throw runtime_error("ERROR SUMMARIZEGAME: Incorrect input for GameID\n");
                
                SummarizeGame(gameID);
            }
            else if (cmd == "SummarizeAchievement"){
                int gameID;
                int achievementID;
                
                cin >> gameID;
                if(cin.fail()) throw runtime_error("ERROR SUMMARIZEGAME: Incorrect input for GameID\n");
                cin >> achievementID;
                if(cin.fail()) throw runtime_error("ERROR SUMMARIZEGAME: Incorrect input for AchievementID\n");
                
                SummarizeAchievement(gameID, achievementID);
            }
            else if (cmd == "AchievementRanking"){
                    AchievementRanking();
            }
            else{
                throw runtime_error("ERROR COMMAND: Incorrect command re-run and try again.\n");
            }
        }
        
        
        
        
        
        
        
        
        
        
        //print game_db
        for(int i = 0; i < game_DB.size(); ++i){
            cout << "G: " << game_DB[i].getGameName() << "\n";
            //check if game has achievements
            vector<Achievement> vec_Ach = game_DB[i].getAchievementVector();
            if (vec_Ach.size() > 0){
                for (int j = 0; j < vec_Ach.size(); j++)
                    cout << "\tAchievement " << vec_Ach[j].getAchievementID() << ": " << vec_Ach[j].getAchievementName();
            }
         
        }
        
        
        //print player_db
        for(int i = 0; i < player_DB.size(); ++i){
            cout << player_DB[i].getPlayerName() << "\n";
        }
        
        
        
        
        
        
        
        
        
        
        
        return 0;
    }
    catch (const runtime_error& e){
        cout << e.what();
        return 1;
    }
}












