/*
<<<<<<< HEAD
Brandon Ellis
csce 315-503
individual project 1 - achievement tracker

main.cpp - branch1
*/



/*

        NOTES TO SELF:
 
        - make reports print names instead of ID's
 
        
        - use gameID and playerID to put the entries in increasing order so when you need to
            search for a specified game/player you can use a binary search.
            -- possibly achievementID as well ????
 



=======
    Brandon Ellis
    csce 315-503
    individual project 1 - acheivement tracker
 
    master
>>>>>>> master
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
    cout << "AddAchievement <Game ID> <Achievement ID> <Achievement Name> <Achievement Points>"
         << endl;
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
    
    str.erase(str.begin(), str.begin()+2);
    str.erase(str.end()-1, str.end());
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
        length = 0;
    }
    // added this in case all ints being looked at are the value 0
    if (max == 0)
        max = 1;
    
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
    
    int separatorLength = numberSpacing.size() + 19 + game.size();
    //19 is number of chars in the title in previoud line
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
    
    cout << "\n";
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
    
    vector<string> vNames;
    vNames.push_back(playerName_1);
    vNames.push_back(playerName_2);
    
    int longestStr = findLongestString(vNames);
    // the purpose of this value is to use it for the setw() functions to properly
    // align the text

    int player1score = getGamerScore(playerID_1, gameID, player_DB);
    int player2score = getGamerScore(playerID_2, gameID, player_DB);
    
    vector<int> vInts;
    vInts.push_back(player1score);
    vInts.push_back(player2score);
    
    int longestGamerScore = findLongestInt(vInts);
    // same purpose as the value longestStr
    
    //compare the lengths to the respective titles and print title information
    //"Player" to longestStr - the max will be the arguement for setw()
    int playerWidth;
    
    if ( 6 > longestStr){ // 6 chars in "Player"
        playerWidth = 6;
    }
    else{
        playerWidth = longestStr;
    }
    
    //"GamerScore" to longestGamerScore - the max will be the arguement for setw()
    int gamerScoreWidth;
    longestGamerScore += 4; // add 4 because of the score.append(" pts")
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
    cout << left << setw(gamerScoreWidth) << "Gamerscore" << endl;
    
    // make function runs loop passing in combined widths to pring out that many '-' for title
    int separatorLength = numberSpacing.size() + playerWidth + gamerScoreWidth + spacing;
    printSeparator(separatorLength);
    
    //print player title info
    for (int i = 0; i < vNames.size(); i++){
        cout << i+1 << ". " << left << setw(playerWidth + spacing) << vNames[i];
        //cout << left << setw(IDwidth + spacing) << playerIDs[i];
        string score = to_string(vInts[i]);
        score.append(" pts");
        cout << left << setw(gamerScoreWidth + spacing) << score << endl;
    }
    vNames.clear();
    vInts.clear();

    cout << "\n";
    
    //retrieve player 1 achievements for the deisred game
    vector<GamePlay> gameHistory = player_DB[playerID1_index].getGameHistory();
    int gamePlayIndex = searchforGamePlayID(gameHistory, gameID);
    vector<Achievement> playerAchievements = gameHistory[gamePlayIndex].getAwardedAchievements();
    
    // need to find out what is the longest string/int to be able to correctly set the width
    
    for(int i = 0; i < playerAchievements.size(); i++){
        string achieveName = playerAchievements[i].getAchievementName();
        vNames.push_back(achieveName);
        
        int points = playerAchievements[i].getPoints();
        vInts.push_back(points);
    }
    
    int longestAchievment = findLongestString(vNames);
    int longestNumber = findLongestInt(vInts);
    
    int pointTitleWidth = 6; // 6 = "Points" .size()
    if(pointTitleWidth < longestNumber){
        pointTitleWidth = longestNumber;
    }

    string title = "Player: ";
    title.append(playerName_1);
    int playerTitleWidth = title.size();
    cout << numberSpacing << left << setw(playerTitleWidth + spacing) << title;
    cout << left << setw(pointTitleWidth) << "Points" << endl;
    
    separatorLength = numberSpacing.size() + playerTitleWidth + spacing + pointTitleWidth;
    printSeparator(separatorLength);
    
    //list awarded achievements
    for(int i = 0; i < playerAchievements.size(); i++){
        cout << i+1 << ". " << left << setw(playerTitleWidth + spacing)
             << playerAchievements[i].getAchievementName();
        cout << playerAchievements[i].getPoints() << " pts" << endl;
    }
    
    cout << "\n";
    
    vNames.clear();
    vInts.clear();
    
    //repeat for player 2
    gameHistory = player_DB[playerID2_index].getGameHistory();
    gamePlayIndex = searchforGamePlayID(gameHistory, gameID);
    playerAchievements = gameHistory[gamePlayIndex].getAwardedAchievements();
    
    for(int i = 0; i < playerAchievements.size(); i++){
        string achieveName = playerAchievements[i].getAchievementName();
        vNames.push_back(achieveName);
        
        int points = playerAchievements[i].getPoints();
        vInts.push_back(points);
    }
    
    longestAchievment = findLongestString(vNames);
    longestNumber = findLongestInt(vInts);
    
    pointTitleWidth = 6; // 6 = "Points" .size()
    if(pointTitleWidth < longestNumber){
        pointTitleWidth = longestNumber;
    }
    
    title = "Player: ";
    title.append(playerName_2);
    playerTitleWidth = title.size();
    cout << numberSpacing << left << setw(playerTitleWidth + spacing) << title;
    cout << left << setw(pointTitleWidth) << "Points" << endl;
    
    separatorLength = numberSpacing.size() + playerTitleWidth + spacing + pointTitleWidth;
    printSeparator(separatorLength);
    
    //list awarded achievements
    for(int i = 0; i < playerAchievements.size(); i++){
        cout << i+1 << ". " << left << setw(playerTitleWidth + spacing)
        << playerAchievements[i].getAchievementName();
        cout << playerAchievements[i].getPoints() << " pts" << endl;
    }
    
    cout << "\n";
}

void SummarizePlayer(int playerID, vector<Player>& player_DB, vector<Game>& game_DB){
    /*
     Print record of all of player's friends, games 
     the player plays, and gamer point totals.
     */
//cout << "PlayerID: " << PlayerID << endl;
    int playerIndex = searchForPlayerID(player_DB, playerID);
    string playerName = player_DB[playerIndex].getPlayerName();
    
    cout << "Player: " << playerName << endl;
    cout << "Total Gamerscore: " << player_DB[playerIndex].getGamerScore() << endl;
    cout << "\n";
    
    vector<GamePlay> playerHistory = player_DB[playerIndex].getGameHistory();
    // find longest string for Game Name
    vector<string> gameName;
    vector<string> IGNname;
    vector<int> gamerscores;
    
    for(int i = 0; i < playerHistory.size(); i++){
        
        int gameID = playerHistory[i].getGamePlayID();
        int gameIndex = searchForGameID(game_DB, gameID);
        
        string gameNameStr = game_DB[gameIndex].getGameName();
        gameName.push_back(gameNameStr);
        
        //string playerIGNname = game_DB[gameIndex].getPlayerIGN();
        string playerIGNname = playerHistory[i].getPlayerIGN();
        //cout << "IGN: " << playerIGNname << endl;
        IGNname.push_back(playerIGNname);
        
        
        
        //for loop - get vecotr<int> gamerscores , findlongestInt
        vector<Achievement> awardedAchievements = playerHistory[i].getAwardedAchievements();
        int totalPoints = 0;
        for (int j = 0; j < awardedAchievements.size(); j++){
            totalPoints += awardedAchievements[j].getPoints();
        }
        gamerscores.push_back(totalPoints);
    }
    
    int longestGameStr = findLongestString(gameName);
    int gameTitleWidth = 4; // "Game" .size()
    
    if(gameTitleWidth < longestGameStr){
        gameTitleWidth = longestGameStr;
    }
    
    int longestgamerscoreInt = findLongestInt(gamerscores);
    int gamerscoreTitleWidth = 10; // "Gamerscore" .size()
    
    if(gamerscoreTitleWidth < longestgamerscoreInt + 4){
        // + 4 b/c of the appended " pts" to the score
        gamerscoreTitleWidth = longestgamerscoreInt;
    }
    
    int longestIGNstr = findLongestString(IGNname);
    int IGNtitleWidth = 3; // "IGN" .size()
    
    if(IGNtitleWidth < longestIGNstr){
        IGNtitleWidth = longestIGNstr;
    }
    
    int achievementTitleWidth = 12; // "achievement" .size()
    
    string numberSpacing = string(3, ' ');
    int spacing = 5; // to keep extra spacing between columns
    
    //cout << "gameTitleWidth: " << gameTitleWidth << endl;
    //cout << "longestGameStr: " << longestGameStr << endl;
    //cout << "longestIGNstr: " << longestIGNstr << endl;
    //cout << "longestgamerscoreInt: " << longestgamerscoreInt << endl;
    
    cout << numberSpacing << left << setw(gameTitleWidth + spacing) << "Game";
    cout << left << setw(achievementTitleWidth + spacing) << "Achievement";
    cout << left << setw(gamerscoreTitleWidth + spacing) << "Gamerscore";
    cout << left << setw(IGNtitleWidth) << "IGN" << endl;
    
    int separatorLength = numberSpacing.size() + gameTitleWidth + spacing
                        + achievementTitleWidth + spacing + gamerscoreTitleWidth
                        + spacing + IGNtitleWidth;
    printSeparator(separatorLength);
    
    for (int i = 0; i < game_DB.size(); i++){
        int gameID = game_DB[i].getGameID();
        int playsGame = searchforGamePlayID(playerHistory, gameID);
        
        if (playsGame >= 0){
            //get total # Achieve
            vector<Achievement> possibleAchievements = game_DB[i].getAchievementVector();
            int totalAchievements = possibleAchievements.size();
            string totalAchieveStr = to_string(totalAchievements);
            
            //get total # trophies
            vector<Achievement> awardedAchievements = playerHistory[playsGame].getAwardedAchievements();
            int totalTrophies = awardedAchievements.size();
            string totalTrophiesStr = to_string(totalTrophies);
      
            //get gs total for game
            int gamerscore = 0;
            for(int j = 0; j < awardedAchievements.size(); j++){
                gamerscore += awardedAchievements[j].getPoints();
            }
            
            string gameGamerscore = to_string(gamerscore);
            gameGamerscore.append(" pts");
            
            string gameNameStr = game_DB[i].getGameName();
            cout << i+1 << ". " << left << setw(gameTitleWidth +  spacing) << gameNameStr;
            
            string achievmentFraction = totalTrophiesStr;
            achievmentFraction.append("/");
            achievmentFraction.append(totalAchieveStr);
            
            cout << left << setw(achievementTitleWidth + spacing) << achievmentFraction;
            
            cout << left << setw(gamerscoreTitleWidth + spacing) << gameGamerscore;
            
            string playerIGN = playerHistory[playsGame].getPlayerIGN();
            cout << left << setw(IGNtitleWidth) << playerIGN << endl;
        }
    }
    
    cout << "\n";
    
    //print friends, and total gamerscore
    vector<Player> rankedPlayerDB = player_DB;
    vector<string> vecPlayerName;
    // sort the vector according to Gamerscores
    for (int i = 0; i < rankedPlayerDB.size(); i++){
        
        Player currPlayer = rankedPlayerDB[i];
        int gamerScore = currPlayer.getGamerScore();
        
        //used to find correct setw() for column Friend
        string currName = rankedPlayerDB[i].getPlayerName();
        vecPlayerName.push_back(currName);
        
        int index = i;
        int prevGamerScore = rankedPlayerDB[index - 1].getGamerScore();
        
        for(; index > 0 && (gamerScore > prevGamerScore); index--){
            rankedPlayerDB[index] = rankedPlayerDB[index - 1];
        }
        rankedPlayerDB[index] = currPlayer;
    }
    
    int longestStr = findLongestString(vecPlayerName);
    int playerTitleWidth = 6; // "Player" .size()
    
    if(playerTitleWidth < longestStr){
        playerTitleWidth = longestStr;
    }
    gamerscoreTitleWidth = 10; // "Gamerscore" .size()
    
    cout << numberSpacing << left << setw(playerTitleWidth + spacing) << "Player";
    cout << left << setw(gamerscoreTitleWidth) << "Gamerscore" << endl;
    
    separatorLength = numberSpacing.size() + playerTitleWidth + spacing + gamerscoreTitleWidth;
    printSeparator(separatorLength);
    
    vector<int> friendsList = player_DB[playerIndex].getFriendsList();
    
    for(int i = 0; i < friendsList.size(); i++){
        int playerID = friendsList[i];
        int playerIndex = searchForPlayerID(player_DB, playerID);
        
        Player currPlayer = player_DB[playerIndex];
        
        string currPlayerName = currPlayer.getPlayerName();
        int gamerscore = currPlayer.getGamerScore();
        string currGamerscore = to_string(gamerscore);
        currGamerscore.append(" pts");
        
        cout << i+1 << ". " << left << setw(playerTitleWidth) << currPlayerName;
        cout << left << setw(gamerscoreTitleWidth) << currGamerscore << endl;
    }
    cout << "\n";
}

void SummarizeGame(int gameID, vector<Game>& game_DB, vector<Player>& player_DB){
    
    int gameIndex = searchForGameID(game_DB, gameID);
    string gameStr = game_DB[gameIndex].getGameName();

    cout << "Game: " << gameStr << endl;
    
    vector<string> vecStr;
    vector<Player> playersOfGame;
    //find out who plays store in vector<String>
    for(int i = 0; i < player_DB.size(); i++){
        Player currPlayer = player_DB[i];
        vector<GamePlay> currGameHistory = currPlayer.getGameHistory();
        
        int playsGame = searchforGamePlayID(currGameHistory, gameID);
        if(playsGame >= 0){
            string playerName = currPlayer.getPlayerName();
            vecStr.push_back(playerName);
            
            playersOfGame.push_back(currPlayer);
        }
    }
    
    int longestStr = findLongestString(vecStr);
    
    string numberSpacing = string(3, ' ');
    cout << numberSpacing << "Player" << endl;
    
    int separatorLength = numberSpacing.size() + longestStr;
    printSeparator(separatorLength);
    
    for(int i = 0; i < vecStr.size(); i++){
        cout << i+1 << ". " << vecStr[i] << endl;
    }
    cout << "\n";
    
    //Achivements and number of times acheived
    // i think that it is useful to print all possible achievments
    // and place a 0 if it was never achieved
    
    //need to find out correct setw() lengths for corresponding
    //columns Achievement and # of times achieved
    vecStr.clear();
    
    vector<Achievement> possibleAchievements = game_DB[gameIndex].getAchievementVector();
    
    for(int i = 0; i < possibleAchievements.size(); i++){
        string currAchievmentName = possibleAchievements[i].getAchievementName();
        vecStr.push_back(currAchievmentName);
    }
    
    longestStr = findLongestString(vecStr);
    
    int achievementTitleWidth = 14;
    if ( achievementTitleWidth < longestStr){
        achievementTitleWidth = longestStr;
    }
    
    int spacing = 5;
    
    cout << numberSpacing << left << setw(achievementTitleWidth + spacing) << "Achievement";
    cout << "# of times Achieved" << endl; // 19 chars in this string
    
    separatorLength = achievementTitleWidth + spacing + 19;
    printSeparator(separatorLength);
    
    int numTimesAchieved;
    //loop through to find number of times each achievement was achieved and print info
    for(int i = 0; i < possibleAchievements.size(); i++){
        int achievementID = possibleAchievements[i].getAchievementID();
        
        int numTimesAchieved = 0;
        //iterate through each player that plays the game to see if they recieved achievement
        for(int j = 0; j < playersOfGame.size(); j++){
            vector<GamePlay> gameHistory = playersOfGame[j].getGameHistory();
            int gamePlayIndex = searchforGamePlayID(gameHistory, gameID);
            
            vector<Achievement> awardedAchievements = gameHistory[gamePlayIndex].getAwardedAchievements();
            int achieveSuccess = searchIfAchievedID(awardedAchievements, achievementID);
            
            if (achieveSuccess >= 0){
                ++numTimesAchieved;
            }
        }
        string achievementName = possibleAchievements[i].getAchievementName();
        cout << i+1 << ". " << left << setw(achievementTitleWidth + spacing) << achievementName;
        cout << numTimesAchieved << endl;
    }
    cout << "\n";
    
}

void SummarizeAchievement(int gameID, int achievementID, vector<Player>& player_DB, vector<Game>& game_DB){
    
    int gameIndex = searchForGameID(game_DB, gameID);
    string gameName = game_DB[gameIndex].getGameName();
    
    vector<Achievement> possibleAchievements = game_DB[gameIndex].getAchievementVector();
    int achievementIndex = searchIfAchievedID(possibleAchievements, achievementID);
    string achievementName = possibleAchievements[achievementIndex].getAchievementName();
    
    cout << "Game: " << gameName << endl;
    cout << "Achievement: " << achievementName << endl;
    
    string numberSpacing = string(3, ' ');
    
    vector<string> playersWithAchievement;
    // get all players that have gotten the achievement
    for(int i = 0; i < player_DB.size(); i++){
        Player currPlayer = player_DB[i];

        vector<GamePlay> playerHistory = currPlayer.getGameHistory();
        int gamePlayIndex = searchforGamePlayID(playerHistory, gameID);
        
        if (gamePlayIndex >= 0){
            // if here currPlayer has played the game
            // now check that player has received achievement
            vector<Achievement> playerAchievements = playerHistory[gamePlayIndex].getAwardedAchievements();
            
            int playerAchieved = searchIfAchievedID(playerAchievements, achievementID);
            if( playerAchieved >= 0){
                string currPlayerName = currPlayer.getPlayerName();
                playersWithAchievement.push_back(currPlayerName);
            }
        }
    }
    
    // find correct width for function setw()
    int longestStr = findLongestString(playersWithAchievement);
    
    int playerTitleWidth = 23; // "Player with Achievement" .size()
    if ( playerTitleWidth < longestStr){
        playerTitleWidth = longestStr;
    }
    
    cout << numberSpacing << setw(playerTitleWidth) << "Player with Achievement" << endl;
    
    int separatorLength = numberSpacing.size() + playerTitleWidth;
    printSeparator(separatorLength);
    
    for(int i = 0; i < playersWithAchievement.size(); i++){
        cout << i+1 << ". " << playersWithAchievement[i] << endl;
    }
    
    //print percentage of players that have achieved this
    double numPlayersAchieved = playersWithAchievement.size();
    double numTotalPlayers = player_DB.size();
    
    double percentage = numPlayersAchieved / numTotalPlayers;
    percentage *= 100; // correctly format
    
    cout << "% of players that play and have achievement: " << percentage << "%" << endl;
    
    cout << "\n";
}

void AchievementRanking(vector<Player>& player_DB){

    vector<int> gamerScores;
    int longestStr = 0;
    // find the longest playername and longest gamerscore in terms of chars
    // this is needed to set the correct width in funciton setw()
    
    for(int i = 0; i < player_DB.size(); i++){
        string playerName = player_DB[i].getPlayerName();
        
        int playerNameLength = playerName.size();
        if (playerNameLength > longestStr)
            longestStr = playerNameLength;
        
        int gamerScore = player_DB[i].getGamerScore();
        gamerScores.push_back(gamerScore);
    }
    int longestGamerScore = findLongestInt(gamerScores);
    
    int playerTitleWidth = 6; // "Player" .size()
    if( playerTitleWidth < longestStr){
        playerTitleWidth = longestStr;
    }
    
    int gamerScoreTitleWidth = 10; // "Gamerscore" .size()
    if ( gamerScoreTitleWidth < longestGamerScore){
        gamerScoreTitleWidth = longestGamerScore;
    }
    
    int spacing = 5; // spacing between columns
    string numberSpacing = string(3, ' '); // spacing at beginning for correct alignment
    
    cout << numberSpacing << left << setw(playerTitleWidth + spacing) << "Player";
    cout << left << setw(gamerScoreTitleWidth) << "Gamerscore" << endl;
    
    int separatorLength = numberSpacing.size() + playerTitleWidth + spacing + gamerScoreTitleWidth;
    printSeparator(separatorLength);
    
    //find a way to print increasing order by gamerscore
    vector<Player> rankedPlayerDB = player_DB;
    // sort the vector according to Gamerscores
    for (int i = 0; i < rankedPlayerDB.size(); i++){
        
        Player currPlayer = rankedPlayerDB[i];
        int gamerScore = currPlayer.getGamerScore();
        
        int index = i;
        int prevGamerScore = rankedPlayerDB[index - 1].getGamerScore();
        
        for(; index > 0 && (gamerScore > prevGamerScore); index--){
            rankedPlayerDB[index] = rankedPlayerDB[index - 1];
        }
        rankedPlayerDB[index] = currPlayer;
    }
    
    for(int i = 0; i < rankedPlayerDB.size(); i++){
        string playerName = rankedPlayerDB[i].getPlayerName();
        int gamerScore = rankedPlayerDB[i].getGamerScore();
        cout << i+1 << ". " << left << setw(playerTitleWidth + spacing) << playerName;
        string gamerScoreStr = to_string(gamerScore);
        gamerScoreStr.append(" pts");
        cout << left << setw(gamerScoreTitleWidth) << gamerScoreStr << endl;
    }
    cout << "\n";
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
                //cin >> playerIGN;
                getline(cin, playerIGN);
                if(cin.fail()) throw runtime_error("ERROR PLAYS: Incorrect input for PlayerIGN\n");
                
                playerIGN = truncQuotes(playerIGN);
                
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
                
                SummarizePlayer(playerID, player_DB, game_DB);
            }
            else if (cmd == "SummarizeGame"){
                int gameID;
                
                cin >> gameID;
                if(cin.fail()) throw runtime_error("ERROR SUMMARIZEGAME: Incorrect input for GameID\n");
                
                SummarizeGame(gameID, game_DB, player_DB);
            }
            else if (cmd == "SummarizeAchievement"){
                int gameID;
                int achievementID;
                
                cin >> gameID;
                if(cin.fail()) throw runtime_error("ERROR SUMMARIZEGAME: Incorrect input for GameID\n");
                cin >> achievementID;
                if(cin.fail()) throw runtime_error("ERROR SUMMARIZEGAME: Incorrect input for AchievementID\n");
                
                SummarizeAchievement(gameID, achievementID, player_DB, game_DB);
            }
            else if (cmd == "AchievementRanking"){
                    AchievementRanking(player_DB);
            }
            else if(cmd == ""){
                break;
            }
            else{
                throw runtime_error("ERROR COMMAND: Incorrect command re-run and try again.\n");
            }
            cmd = "";
        }
        
        
        
       
        
        // ****************** Need to delete
        
        
        cout << "\n\n\n";
        cout << "GAMES: "<<endl;
        //print game_db
        for(int i = 0; i < game_DB.size(); ++i){
            cout << "- " << game_DB[i].getGameName() << "\n";
            //check if game has achievements
            vector<Achievement> vec_Ach = game_DB[i].getAchievementVector();
            if (vec_Ach.size() > 0){
                for (int j = 0; j < vec_Ach.size(); j++)
                    cout << "\tAchievement: " << vec_Ach[j].getAchievementID() << "; "
                         << vec_Ach[j].getAchievementName() <<endl;
            }
         
        }
        
        cout << "\n\nPLAYERS: "<< endl;
        //print player_db
        for(int i = 0; i < player_DB.size(); ++i){
            cout << player_DB[i].getPlayerName() << "\n";
            cout << "GS: " << player_DB[i].getGamerScore() << endl;
            //print gamehistory
            vector<GamePlay> vec_GP = player_DB[i].getGameHistory();
            if (vec_GP.size() > 0){
                for (int j = 0; j < vec_GP.size(); j++){
                    cout << "\tGameHistory: " << vec_GP[j].getPlayerIGN() << "; "
                         << vec_GP[j].getGamePlayID() << endl;
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
        
        
          // ****************** Need to delete
        
        
        
        
        
        
        
        
        return 0;
    }
    catch (const runtime_error& e){
        cout << e.what();
        return 1;
    }
}












