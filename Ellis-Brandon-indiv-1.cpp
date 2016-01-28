/*
Brandon Ellis
csce 315-503
individual project 1 - achievement tracker

main.cpp - branch1
*/



/*

        NOTES TO SELF:
 
        -FriendsThatPlay: need to addin the Serpartor function for the dashed line
 
        - naming: most variables are in format like this gamerScore. some are like this player_DB
                should I change it and make it all one convention?
 
 
        
        - use gameID and playerID to put the entries in increasing order so when you need to
            search for a specified game/player you can use a binary search.
            -- possibly achievementID as well ????
 



*/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
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
    // After talking with the Peer Teacher in 503 lab, we have come to a conclusion that
    // the reason I am deleting the first 4 characters and the last 3 characters because
    // of the functionality of getline() we believe that it is retrieving hidden characters
    // that we still need to delete.
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

int searchForFriend(vector<int> friendsList, int playerID_2){
    //-1 = nonexistent
    
    if(friendsList.size() == 0)
        return -1;
    
    int mid = 0, low = 0, high = friendsList.size();
    while(low <= high){
        mid = low + (high-low)/2;
        if (friendsList[mid] == playerID_2){
            return mid;
        }
        else if (friendsList[mid] < playerID_2){
            low = mid + 1;
        }
        else if (friendsList[mid] > playerID_2){
            high = mid - 1;
        }
    }
    return -1;

}

int searchforGamePlayID(vector<GamePlay>& playerHistory, int target_gameID){
    
    if (playerHistory.size() == 0)
        return -1;
    
    int mid = 0, low = 0, high = playerHistory.size();
    while(low <= high){
        mid = low + (high-low)/2;
        if (playerHistory[mid].getGamePlayID() == target_gameID){
            return mid;
        }
        else if (playerHistory[mid].getGamePlayID() < target_gameID){
            low = mid + 1;
        }
        else if (playerHistory[mid].getGamePlayID() > target_gameID){
            high = mid - 1;
        }
    }
    return -1;
}

int searchIfAchievedID(vector<Achievement>& possibleAchievements, int target_achievementID){
    
    if (possibleAchievements.size() == 0)
        return -1;
    
    int mid = 0, low = 0, high = possibleAchievements.size();
    while(low <= high){
        mid = low + (high-low)/2;
        if (possibleAchievements[mid].getAchievementID() == target_achievementID){
            return mid;
        }
        else if (possibleAchievements[mid].getAchievementID() < target_achievementID){
            low = mid + 1;
        }
        else if (possibleAchievements[mid].getAchievementID() > target_achievementID){
            high = mid - 1;
        }
    }
    return -1;
}

int findLongestString(vector<string>& vecStr){
    
    int max = 0;
    for(int i = 0; i < vecStr.size(); i++){
        string curr = vecStr[i];
        int currSize = curr.size();
        if(currSize > max){
            max = currSize;
        }
    }
    
    return max;
}

int findLongestInt(vector<int>& vecInt){
    
    int max = 0;
    int length = 0;
    for (int i = 0; i < vecInt.size(); i++){
        int curr_int = vecInt[i];

        while( curr_int != 0 ){
            length++;
            curr_int /= 10;
        }

        if(length > max){
            max = length;
        }
    }
    
    return max;
}

int getGamerScore(int playerID, int gameID, vector<Player>& player_DB){
    
    int player_index = searchForPlayerID(player_DB, playerID);
    
    vector<GamePlay> playerHistory = player_DB[player_index].getGameHistory();
    
    int vAchievementIndex = searchforGamePlayID(playerHistory, gameID);

    vector<Achievement> vAchievements = playerHistory[vAchievementIndex].getAwardedAchievements();
    
    int points = 0;
    for(int i = 0; i < vAchievements.size(); i++){
        //get cumulative points and return it
        int currPoint = vAchievements[i].getPoints();
        points += currPoint;
    }
    return points;
}

void printSeparator(int separatorLength){
    for (int i = 0; i < separatorLength; i++){
        cout << "-";
    }
    cout << "\n";
}

// ======================== Command Funcitons ========================

void AddPlayer(int playerID, string playerName, vector<Player> &player_DB){
    
    int PlayerIDexistence = searchForPlayerID(player_DB, playerID);
    
    if (PlayerIDexistence != -1){
        throw runtime_error("ERROR AddPlayer: PlayerID already exist in the database.");
    }
    
    Player tempPlayer(playerID, playerName);
    player_DB.push_back(tempPlayer);
    sort(player_DB.begin(), player_DB.end());
    
}

void AddGame(int gameID, string gameName, vector<Game> &game_DB){

    int GameIDexistence = searchForGameID(game_DB, gameID);
    
    
    if(GameIDexistence != -1){
        throw runtime_error("ERROR AddGame: GameID already exist in the database.");
    }
    
    Game tempGame(gameID, gameName);
    game_DB.push_back(tempGame);
    sort(game_DB.begin(), game_DB.end());
}

void AddAchievement(int target_gameID, int achievementID, string achievementName, int achievementPoints, vector<Game> &game_DB){
    
    int gameIndex = searchForGameID(game_DB, target_gameID);
    
    if(gameIndex == -1){
        throw runtime_error("ERROR AddAchievement: the GameID is not in the database." );
    }

    Achievement tempAchieve(achievementID, achievementName, achievementPoints);
    game_DB[gameIndex].pushBackAchievement(tempAchieve);
}

void Plays(int playerID, int gameID, string playerIGN, vector<Player> &player_DB, vector<Game> &game_DB){

    int playerIDindex = searchForPlayerID(player_DB, playerID);
    int gameIDindex = searchForGameID(game_DB, gameID);

    if (playerIDindex < 0){
        throw runtime_error("ERROR Plays: the PlayerID does not exist in the database.");
    }
    else if (gameIDindex < 0){
        throw runtime_error("ERROR Plays: the GameID does not exist in the database.");
    }
    
    GamePlay tempGamePlay(gameID, playerIGN);
    player_DB[playerIDindex].pushBackGamePlay(tempGamePlay);
}

void AddFriends(int playerID_1, int playerID_2, vector<Player>& player_DB){
    
    int playerID_1Index = searchForPlayerID(player_DB, playerID_1);
    int playerID_2Index = searchForPlayerID(player_DB, playerID_2);
    
    if (playerID_1Index < 0){
        throw runtime_error("ERROR Plays: the PlayerID does not exist in the database.");
    }
    else if (playerID_2Index < 0){
        throw runtime_error("ERROR Plays: the PlayerID does not exist in the database.");
    }
    
    vector<int> friendsList = player_DB[playerID_1Index].getFriendsList();
    int friendExistence = searchForFriend(friendsList, playerID_2);
    
    if (friendExistence != -1){
        throw runtime_error("ERROR AddFriends: Players are already friends.");
    }
    
    player_DB[playerID_1Index].pushBackFriend(playerID_2);
    player_DB[playerID_2Index].pushBackFriend(playerID_1);
    
}

void Achieve(int playerID, int gameID, int achievementID, vector<Player>& player_DB, vector<Game>& game_DB){
    
    int playerIDindex = searchForPlayerID(player_DB, playerID);
    int gameIDindex = searchForGameID(game_DB, gameID);
    
    if (playerIDindex < 0){
        throw runtime_error("ERROR Achieve: the PlayerID does not exist in the database.");
    }
    else if (gameIDindex < 0){
        throw runtime_error("ERROR Achieve: the GameID does not exist in the database.");
    }
    
    int AchievementExistenceInGame = game_DB[gameIDindex].checkForAchievementID(achievementID);
    //cout << "AchievementExistence: " << AchievementExistence << endl;
    if (AchievementExistenceInGame == -1){
        throw runtime_error("ERROR Achieve: the AchievementID does not exist in the Game.");
    }
    
    Achievement trophy = game_DB[gameIDindex].getAchievementByID(achievementID);
    player_DB[playerIDindex].pushBackAchievement(gameID, trophy);
    
    
}

void FriendsWhoPlay(int playerID, int gameID, vector<Player>& player_DB, vector<Game>& game_DB){
    
    int playerIDindex = searchForPlayerID(player_DB, playerID);
    int gameIDindex = searchForGameID(game_DB, gameID);
    
    if (playerIDindex < 0){
        throw runtime_error("ERROR FriendsWhoPlay: the PlayerID does not exist in the database.");
    }
    else if (gameIDindex < 0){
        throw runtime_error("ERROR FriendsWhoPlay: the GameID does not exist in the database.");
    }
    
    // spacing to keep text above actual column of results and not the nubmering system
    string numberSpacing = string(3, ' ');
    string game = game_DB[gameIDindex].getGameName();
    
    cout << "Player: " << player_DB[playerIDindex].getPlayerName() << endl;
    cout << "Game: " << game_DB[gameIDindex].getGameName() << endl;
    cout << "\n";
    cout << numberSpacing <<"Friends that Play: " << game << endl;
    
    int separatorLength = numberSpacing.size() + 19 + game.size(); //19 is number of chars in the title in previoud line
    printSeparator(separatorLength);
    
    vector<int> friendsList = player_DB[playerIDindex].getFriendsList();
    
    for (int i = 0; i < friendsList.size(); i++){
        int friend_ID = friendsList[i];
        int player_index = searchForPlayerID(player_DB, friend_ID);
        int playsGame = searchForGameID(game_DB, gameID);
        if ( playsGame >= 0 ){
            cout << i+1 << ". " << player_DB[player_index].getPlayerName() << endl;
        }
    }
    
    
    
}

void ComparePlayers(int playerID_1, int playerID_2, int gameID, vector<Player>& player_DB, vector<Game>& game_DB){
    
    int playerID1_index = searchForPlayerID(player_DB, playerID_1);
    int playerID2_index = searchForPlayerID(player_DB, playerID_2);
    int gameIDindex = searchForGameID(game_DB, gameID);
    
    if (playerID1_index < 0 || playerID2_index < 0){
        throw runtime_error("ERROR FriendsWhoPlay: the PlayerID does not exist in the database.");
    }
    else if (gameIDindex < 0){
        throw runtime_error("ERROR FriendsWhoPlay: the GameID does not exist in the database.");
    }
    
    string playerName_1 = player_DB[playerID1_index].getPlayerName();
    string playerName_2 = player_DB[playerID2_index].getPlayerName();
    
    vector<string> playerNames;
    playerNames.push_back(playerName_1);
    playerNames.push_back(playerName_2);
    
    int longestStr = findLongestString(playerNames);
    // the purpose of this value is to use it for the setw() functions to properly align the text
    
    vector<int> playerIDs;
    
    playerIDs.push_back(playerID_1);
    playerIDs.push_back(playerID_2);
    
    int longestID = findLongestInt(playerIDs);
    // same purpose as the value in line 399

    int player1score = getGamerScore(playerID_1, gameID, player_DB);
    int player2score = getGamerScore(playerID_2, gameID, player_DB);
    
    vector<int> gamerScore;
    gamerScore.push_back(player1score);
    gamerScore.push_back(player2score);
    
    int longestGamerScore = findLongestInt(gamerScore);
    // same purpose as the value in line 399
    
    //compare the lengths to the respective titles and print title information
    //"Player" to longestStr - the max will be the arguement for setw()
    int playerWidth;
    
    if ( 6 > longestStr){ // 6 chars in "Player"
        playerWidth = 6;
    }
    else{
        playerWidth = longestStr;
    }
    //"PlayerID" to longestID - the max will be the arguement for setw()
    int IDwidth;
    
    if ( 8 > longestID){ // 8 chars in "PlayerID"
        IDwidth = 8;
    }
    else{
        IDwidth = longestID;
    }
    //"GamerScore" to longestGamerScore - the max will be the arguement for setw()
    int gamerScoreWidth;
    
    if ( 10 > longestGamerScore){ // 10 chars in "Gamerscore"
        gamerScoreWidth = 10;
    }
    else{
        gamerScoreWidth = longestGamerScore;
    }
    
    // spacing will be used to add a more space in between each column
    int spacing = 5;
    string numberSpacing = string(3, ' ');
    
    cout << numberSpacing << left << setw(playerWidth + spacing) << "Player";
    cout << left << setw(IDwidth + spacing) << "PlayerID";
    cout << left << setw(gamerScoreWidth) << "Gamerscore" << endl;
    
    // make function runs loop passing in combined widths to pring out that many '-' for title
    int separatorLength = numberSpacing.size() + playerWidth + IDwidth + gamerScoreWidth + spacing + spacing;
    printSeparator(separatorLength);
    
    //print player title info
    for (int i = 0; i < playerNames.size(); i++){
        cout << i+1 << ". " << left << setw(playerWidth + spacing) << playerNames[i];
        cout << left << setw(IDwidth + spacing) << playerIDs[i];
        cout << left << setw(gamerScoreWidth + spacing) << gamerScore[i] << endl;
    }
    cout << "\n";
    
    //find largest int in char for AchievementID
    vector<Achievement> possibleAchievements = game_DB[gameIDindex].getAchievementVector();
    vector<int> AchievementPoints;
    
    for(int i = 0; i < possibleAchievements.size(); i++){
        int points = possibleAchievements[i].getPoints();
        AchievementPoints.push_back(points);
    }
    
    int largestAchievementInt = findLongestInt(AchievementPoints);
    
    int achievementWidth;
    if( 14 > largestAchievementInt){ // 14 chars in "Achievement ID"
        achievementWidth = 14;
    }
    else{
        achievementWidth = largestAchievementInt;
    }
    //compare largest playerID to find setw() for that column
    
    if( 21 > longestID){ // 21 chars in "Player w/ achievement"
        IDwidth = 21;
    }
    else{
        IDwidth = longestID;
    }
    
    //print comparing title
    cout << numberSpacing << left << setw(achievementWidth + spacing) << "Achievement ID";
    cout << left << setw(IDwidth) << "Player w/ Achievement" << endl;
    
    separatorLength = numberSpacing.size() + achievementWidth + spacing + IDwidth;
    printSeparator(separatorLength);

    
    for(int i = 0; i < possibleAchievements.size(); i++){
        int achievementID = possibleAchievements[i].getAchievementID();
        cout << i+1 << ". " << left << setw(achievementWidth + spacing) << achievementID;
        
        //find out if player 1 recieved the achievement
        vector<GamePlay> playerGamePlay = player_DB[playerID1_index].getGameHistory();
        int gamePlayIndex = searchforGamePlayID(playerGamePlay, gameID);
        vector<Achievement> playerAchievements = playerGamePlay[gamePlayIndex].getAwardedAchievements();
        
        
        int player1Achieve = searchIfAchievedID(playerAchievements, achievementID);
        
        if(player1Achieve >= 0){
            cout << left << setw(longestID) << playerIDs[0];
        }
        else{
            cout << string(longestID, ' '); // to properly align the Player ID's in their own column
        }
        
        //find out if player 2 recieved the achievement
        vector<GamePlay> player2GamePlay = player_DB[playerID2_index].getGameHistory();
        gamePlayIndex = searchforGamePlayID(player2GamePlay, gameID);
        vector<Achievement> player2Achievements = player2GamePlay[gamePlayIndex].getAwardedAchievements();
        
        
        //find out if player 2 got acheivement
        int player2Achieve = searchIfAchievedID(player2Achievements, achievementID);
        
        if(player2Achieve >= 0){
            cout << left << setw(longestID) << playerIDs[1];
        }
        else{
            cout << string(longestID, ' '); // to properly align the Player ID's in their own column
        }
        cout << "\n";
    }
    
    
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
        
        //cout << "\nHello welcome to Achievement Tracker" << endl;
        //cout << "To begin type in the command you wish to run with the correct credentials" << endl;
        //cout << "or type \"help\" to list the available commands." << endl;
        
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
                
                AddFriends(playerID_1, playerID_2, player_DB);

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
                
                Achieve(playerID, gameID, achievementID, player_DB, game_DB);
            }
            else if (cmd == "FriendsWhoPlay"){
                int playerID;
                int gameID;
                
                cin >> playerID;
                if(cin.fail()) throw runtime_error("ERROR FRIENDSWHOPLAY: Incorrect input for PlayerID\n");
                cin >> gameID;
                if(cin.fail()) throw runtime_error("ERROR FRIENDSWHOPLAY: Incorrect input for GameID\n");
                
                FriendsWhoPlay(playerID, gameID, player_DB, game_DB);
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
                
                ComparePlayers(playerID_1, playerID_2, gameID, player_DB, game_DB);
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
        
        
        
        
        
        
        
        
        cout << "\n\n\n";
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
            
            //print gamehistory
            vector<GamePlay> vec_GP = player_DB[i].getGameHistory();
            if (vec_GP.size() > 0){
                for (int j = 0; j < vec_GP.size(); j++){
                    cout << "\tGameHistory: " << vec_GP[j].getPlayerIGN() << "; " << vec_GP[j].getGamePlayID() << endl;
                    //print awarded achievements
                    vector<Achievement> vec_trophies = vec_GP[j].getAwardedAchievements();
                    if (vec_trophies.size() > 0){
                        cout << "\t\tTrophies:" << endl;
                        for (int t = 0; t < vec_trophies.size(); t++){
                            cout << "\t\t\t-" << vec_trophies[t].getAchievementID() << endl;
                        }
                    }
                }
            }
        
            
            //print friends list
            vector<int> vec_FL = player_DB[i].getFriendsList();
            if (vec_FL.size() > 0){
                cout << "\tFriends List:" << endl;
                for (int k = 0; k < vec_FL.size(); k++){
                    int friend_ID = vec_FL[k];
                    int friend_PlayerDB = searchForPlayerID(player_DB, friend_ID);
                    string friendName = player_DB[friend_PlayerDB].getPlayerName();
                    int friendID = player_DB[friend_PlayerDB].getPlayerID();
                    cout << "\t\t" << friendName << " " << friendID << endl;
                }
            }
        }
        
        
        
        
        
        
        
        
        
        
        
        return 0;
    }
    catch (const runtime_error& e){
        cout << e.what();
        return 1;
    }
}












