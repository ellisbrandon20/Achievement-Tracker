/*
Brandon Ellis
csce 315-503
individual project 1 - achievement tracker

main.cpp - branch1
*/



/*

        NOTES TO SELF:
 
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

using namespace std;


// ======================== helper Funcitons ========================
void help(){

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


int searchForGameID(vector<Game> &game_DB, int target_gameID){
    //-1 = nonexistent
    
    if (game_DB.size() == 0)
        return -1;
    
    int mid = 0, low = 0, high = game_DB.size();
    while(low <= high){
        mid = low + (high-low)/2;
            if (game_DB[mid].getGameID() == target_gameID){
                return mid;
            }
            else if (game_DB[mid].getGameID() < target_gameID){
                low = mid + 1;
            }
            else if (game_DB[mid].getGameID() > target_gameID){
                high = mid - 1;
            }
    }
    return -1;

}

int searchForPlayerID(vector<Player> &player_DB, int target_playerID){
    //-1 = nonexistent
    
    if (player_DB.size() == 0)
        return -1;
    
    int mid = 0, low = 0, high = player_DB.size();
    while(low <= high){
        mid = low + (high-low)/2;
        if (player_DB[mid].getPlayerID() == target_playerID){
            return mid;
        }
        else if (player_DB[mid].getPlayerID() < target_playerID){
            low = mid + 1;
        }
        else if (player_DB[mid].getPlayerID() > target_playerID){
            high = mid - 1;
        }
    }
    return -1;
    
}
// ======================== Command Funcitons ========================
void AddPlayer(int playerID, string playerName, vector<Player> &player_DB){
    
    int PlayerIDexistence = searchForPlayerID(player_DB, playerID);
    
    if(PlayerIDexistence == -1){
        Player tempPlayer(playerID, playerName);
        player_DB.push_back(tempPlayer);
        sort(player_DB.begin(), player_DB.end());
    }
    else
        throw runtime_error("ERROR AddPlayer: PlayerID already exist in the database.");
}

void AddGame(int gameID, string gameName, vector<Game> &game_DB){

    int GameIDexistence = searchForGameID(game_DB, gameID);
    
    if (GameIDexistence == -1){
        Game tempGame(gameID, gameName);
        game_DB.push_back(tempGame);
        sort(game_DB.begin(), game_DB.end());
    }
    else
        throw runtime_error("ERROR AddGame: GameID already exist in the database.");
}

void AddAchievement(int target_gameID, int achievementID, string achievementName, int achievementPoints, vector<Game> &game_DB){
    
    int gameIndex = searchForGameID(game_DB, target_gameID);
    
    if(gameIndex != -1){
        Achievement tempAchieve(achievementID, achievementName, achievementPoints);
        game_DB[gameIndex].pushBackAchievement(tempAchieve);
    }
    else{
        throw runtime_error("ERROR AddAchievement: the GameID is not in the database." );
    }
}

void Plays(int playerID, int gameID, string playerIGN, vector<Player> &player_DB, vector<Game> &game_DB){
    /*
     Add entry for player playing a specific game. <Player IGN> is a string identifier for
     that that player's particular in game name for the specified game, enclosed by double quotes.
     <Player IGN> may contain special characters (excluding double quote).
     */
    cout << "\nPlayerID: " << playerID
    << "\nGameID: " << gameID
    << "\nPlayerIGN: " << playerIGN << endl;
    
    //search that PlayerID exists in player_DB
    int PlayerIDindex = searchForPlayerID(player_DB, playerID);
    //search that GameID exists in game_DB
    int GameIDindex = searchForGameID(game_DB, gameID);
    
    if(PlayerIDindex >= 0 && GameIDindex >= 0){
        //both exist
        GamePlay tempGamePlay(gameID, playerIGN);
        player_DB[PlayerIDindex].pushBackGamePlay(tempGamePlay);
    }
    else if (PlayerIDindex < 0){
        throw runtime_error("ERROR Plays: the PlayerID does not exist in the database.");
    }
    else if (GameIDindex < 0){
        throw runtime_error("ERROR Plays: the GameID does not exist in the database.");
    }
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
                    //cout << "error w/ quotes";
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
                
//cout << "addAch: " << gameID << " " << achievementID << " " << achievementName << " " << achievementPoints << endl;
                
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
                
                Plays(playerID, gameID, playerIGN, player_DB, game_DB);
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
            else if(cmd == ""){
                break;
            }
            else{
                throw runtime_error("ERROR COMMAND: Incorrect command re-run and try again.\n");
            }
            cmd = "";
        }
        
        
        
        
        
        
        
        
        
        cout << "GAMES: "<<endl;
        //print game_db
        for(int i = 0; i < game_DB.size(); ++i){
            cout << "- " << game_DB[i].getGameName() << "\n";
            //check if game has achievements
            vector<Achievement> vec_Ach = game_DB[i].getAchievementVector();
            if (vec_Ach.size() > 0){
                for (int j = 0; j < vec_Ach.size(); j++)
                    cout << "\tAchievement: " << vec_Ach[j].getAchievementID() << "; " << vec_Ach[j].getAchievementName() <<endl;
            }
         
        }
        
        cout << "\n\nPLAYERS: "<< endl;
        //print player_db
        for(int i = 0; i < player_DB.size(); ++i){
            cout << player_DB[i].getPlayerName() << "\n";
            //check if player has gamehistory
            vector<GamePlay> vec_GP = player_DB[i].getGameHistory();
            if (vec_GP.size() > 0){
                for (int j = 0; j < vec_GP.size(); j++)
                    cout << "\tGameHistory: " << vec_GP[j].getPlayerIGN() << "; " << vec_GP[j].getGamePlayID() << endl;
            }
                
        }
        
        
        
        
        
        
        
        
        
        
        
        return 0;
    }
    catch (const runtime_error& e){
        cout << e.what();
        return 1;
    }
}












