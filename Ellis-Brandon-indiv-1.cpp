/*
Brandon Ellis
csce 315-503
individual project 1 - achievement tracker
 
 Notes about structure:
    
    reading this file from tope down I have sectioned off the code into 3 segments
        - HELPER FUNCITONS: functions that I used to help do calculations and things like that
        - COMMAND FUNCTION: functions used by the core of the program
        - MAIN: where everything is initially run untill needed to move to either a helper
                function or a command function
 
    playerDB and gameDB are ordered by the player/game IDs stored in side the objects
        so I can easily search for a specific object by using the binary search algorithm
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
    
    // all strings are in the format: " string" (w/ quotes)
    str.erase(str.begin(), str.begin()+2);
    str.erase(str.end()-1, str.end());
    return str;
}

int searchForGameID(vector<Game> &gameDB, int targetGameID){
    //-1 = nonexistent
    
    if (gameDB.size() == 0)
        return -1;
    
    int mid = 0, low = 0, high = gameDB.size();
    while(low <= high){
        mid = low + (high-low)/2;
            if (gameDB[mid].getGameID() == targetGameID){
                return mid;
            }
            else if (gameDB[mid].getGameID() < targetGameID){
                low = mid + 1;
            }
            else if (gameDB[mid].getGameID() > targetGameID){
                high = mid - 1;
            }
    }
    return -1;
}

int searchForPlayerID(vector<Player> &playerDB, int targetPlayerID){
    //-1 = nonexistent
    
    if (playerDB.size() == 0)
        return -1;
    
    int mid = 0, low = 0, high = playerDB.size();
    while(low <= high){
        mid = low + (high-low)/2;
        if (playerDB[mid].getPlayerID() == targetPlayerID){
            return mid;
        }
        else if (playerDB[mid].getPlayerID() < targetPlayerID){
            low = mid + 1;
        }
        else if (playerDB[mid].getPlayerID() > targetPlayerID){
            high = mid - 1;
        }
    }
    return -1;
}

int searchForFriend(vector<int> friendsList, int playerID2){
    //-1 = nonexistent
    
    if(friendsList.size() == 0)
        return -1;
    
    int mid = 0, low = 0, high = friendsList.size();
    while(low <= high){
        mid = low + (high-low)/2;
        if (friendsList[mid] == playerID2){
            return mid;
        }
        else if (friendsList[mid] < playerID2){
            low = mid + 1;
        }
        else if (friendsList[mid] > playerID2){
            high = mid - 1;
        }
    }
    return -1;
}

int searchforGamePlayID(vector<GamePlay>& playerHistory, int targetGameID){
    //-1 = nonexistent
    
    if (playerHistory.size() == 0)
        return -1;
    
    int mid = 0, low = 0, high = playerHistory.size();
    while(low <= high){
        mid = low + (high-low)/2;
        if (playerHistory[mid].getGamePlayID() == targetGameID){
            return mid;
        }
        else if (playerHistory[mid].getGamePlayID() < targetGameID){
            low = mid + 1;
        }
        else if (playerHistory[mid].getGamePlayID() > targetGameID){
            high = mid - 1;
        }
    }
    return -1;
}

int searchIfAchievedID(vector<Achievement>& possibleAchievements, int targetAchievementID){
    
    if (possibleAchievements.size() == 0)
        return -1;
    
    int mid = 0, low = 0, high = possibleAchievements.size();
    while(low <= high){
        mid = low + (high-low)/2;
        if (possibleAchievements[mid].getAchievementID() == targetAchievementID){
            return mid;
        }
        else if (possibleAchievements[mid].getAchievementID() < targetAchievementID){
            low = mid + 1;
        }
        else if (possibleAchievements[mid].getAchievementID() > targetAchievementID){
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
        int currInt = vecInt[i];

        while( currInt != 0 ){
            length++;
            currInt /= 10;
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

int getGamerScore(int playerID, int gameID, vector<Player>& playerDB){
    
    int playerIndex = searchForPlayerID(playerDB, playerID);
    
    vector<GamePlay> playerHistory = playerDB[playerIndex].getGameHistory();
    
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

void AddPlayer(int playerID, string playerName, vector<Player> &playerDB){
    
    int PlayerIDexistence = searchForPlayerID(playerDB, playerID);
    
    if (PlayerIDexistence != -1){
        throw runtime_error("ERROR AddPlayer: PlayerID already exist in the database.");
    }
    
    Player tempPlayer(playerID, playerName);
    playerDB.push_back(tempPlayer);
    sort(playerDB.begin(), playerDB.end());
}

void AddGame(int gameID, string gameName, vector<Game> &gameDB){

    int GameIDexistence = searchForGameID(gameDB, gameID);
    
    if(GameIDexistence != -1){
        throw runtime_error("ERROR AddGame: GameID already exist in the database.");
    }
    
    Game tempGame(gameID, gameName);
    gameDB.push_back(tempGame);
    sort(gameDB.begin(), gameDB.end());
}

void AddAchievement(int targetGameID, int achievementID, string achievementName, int achievementPoints, vector<Game> &gameDB){
    
    int gameIndex = searchForGameID(gameDB, targetGameID);
    
    if(gameIndex == -1){
        throw runtime_error("ERROR AddAchievement: the GameID is not in the database." );
    }

    Achievement tempAchieve(achievementID, achievementName, achievementPoints);
    gameDB[gameIndex].pushBackAchievement(tempAchieve);
}

void Plays(int playerID, int gameID, string playerIGN, vector<Player> &playerDB, vector<Game> &gameDB){

    int playerIDindex = searchForPlayerID(playerDB, playerID);
    int gameIDindex = searchForGameID(gameDB, gameID);

    if (playerIDindex < 0){
        throw runtime_error("ERROR Plays: the PlayerID does not exist in the database.");
    }
    else if (gameIDindex < 0){
        throw runtime_error("ERROR Plays: the GameID does not exist in the database.");
    }
    
    GamePlay tempGamePlay(gameID, playerIGN);
    playerDB[playerIDindex].pushBackGamePlay(tempGamePlay);
}

void AddFriends(int playerID1, int playerID2, vector<Player>& playerDB){
    
    int playerID1Index = searchForPlayerID(playerDB, playerID1);
    int playerID2Index = searchForPlayerID(playerDB, playerID2);
    
    if (playerID1Index < 0){
        throw runtime_error("ERROR Plays: the PlayerID does not exist in the database.");
    }
    else if (playerID2Index < 0){
        throw runtime_error("ERROR Plays: the PlayerID does not exist in the database.");
    }
    
    vector<int> friendsList = playerDB[playerID1Index].getFriendsList();
    int friendExistence = searchForFriend(friendsList, playerID2);
    
    if (friendExistence != -1){
        throw runtime_error("ERROR AddFriends: Players are already friends.");
    }
    
    playerDB[playerID1Index].pushBackFriend(playerID2);
    playerDB[playerID2Index].pushBackFriend(playerID1);
}

void Achieve(int playerID, int gameID, int achievementID, vector<Player>& playerDB, vector<Game>& gameDB){
    
    int playerIDindex = searchForPlayerID(playerDB, playerID);
    int gameIDindex = searchForGameID(gameDB, gameID);
    
    if (playerIDindex < 0){
        throw runtime_error("ERROR Achieve: the PlayerID does not exist in the database.");
    }
    else if (gameIDindex < 0){
        throw runtime_error("ERROR Achieve: the GameID does not exist in the database.");
    }
    
    int AchievementExistenceInGame = gameDB[gameIDindex].checkForAchievementID(achievementID);
    
    if (AchievementExistenceInGame == -1){
        throw runtime_error("ERROR Achieve: the AchievementID does not exist in the Game.");
    }
    
    Achievement trophy = gameDB[gameIDindex].getAchievementByID(achievementID);
    playerDB[playerIDindex].pushBackAchievement(gameID, trophy);
}

void FriendsWhoPlay(int playerID, int gameID, vector<Player>& playerDB, vector<Game>& gameDB){
    
    cout << "Friends Who Play " << endl;
    int playerIDindex = searchForPlayerID(playerDB, playerID);
    int gameIDindex = searchForGameID(gameDB, gameID);
    
    if (playerIDindex < 0){
        throw runtime_error("ERROR FriendsWhoPlay: the PlayerID does not exist in the database.");
    }
    else if (gameIDindex < 0){
        throw runtime_error("ERROR FriendsWhoPlay: the GameID does not exist in the database.");
    }
    
    // spacing to keep text above actual column of results and not the nubmering system
    string numberSpacing = string(3, ' ');
    string game = gameDB[gameIDindex].getGameName();
    
    cout << "Player: " << playerDB[playerIDindex].getPlayerName() << endl;
    cout << "Game: " << gameDB[gameIDindex].getGameName() << endl;
    cout << "\n";
    cout << numberSpacing <<"Friends that Play: " << game << endl;
    
    int separatorLength = numberSpacing.size() + 19 + game.size();
    //19 is number of chars in the title in previous line
    printSeparator(separatorLength);
    
    vector<int> friendsList = playerDB[playerIDindex].getFriendsList();
    
    for (int i = 0; i < friendsList.size(); i++){
        int friendID = friendsList[i];
        int playerIndex = searchForPlayerID(playerDB, friendID);
        int playsGame = searchForGameID(gameDB, gameID);
        if ( playsGame >= 0 ){
            cout << i+1 << ". " << playerDB[playerIndex].getPlayerName() << endl;
        }
    }
    cout << "\n";
}

void ComparePlayers(int playerID1, int playerID2, int gameID, vector<Player>& playerDB, vector<Game>& gameDB){
    
    cout << "Compare Players " << endl;
    int playerID1index = searchForPlayerID(playerDB, playerID1);
    int playerID2index = searchForPlayerID(playerDB, playerID2);
    int gameIDindex = searchForGameID(gameDB, gameID);
    
    if (playerID1index < 0 || playerID2index < 0){
        throw runtime_error("ERROR FriendsWhoPlay: the PlayerID does not exist in the database.");
    }
    else if (gameIDindex < 0){
        throw runtime_error("ERROR FriendsWhoPlay: the GameID does not exist in the database.");
    }
    
    string playerName1 = playerDB[playerID1index].getPlayerName();
    string playerName2 = playerDB[playerID2index].getPlayerName();
    
    vector<string> vNames;
    vNames.push_back(playerName1);
    vNames.push_back(playerName2);
    
    int longestStr = findLongestString(vNames);
    // the purpose of this value is to use it for the setw() functions to properly
    // align the text

    int player1score = getGamerScore(playerID1, gameID, playerDB);
    int player2score = getGamerScore(playerID2, gameID, playerDB);
    
    vector<int> vInts;
    vInts.push_back(player1score);
    vInts.push_back(player2score);
    
    int longestGamerScore = findLongestInt(vInts);
    // same purpose as the value longestStr
    
    //compare the lengths to the respective titles and print title information
    //"Player" to longestStr - the max will be the arguement for setw()
    //    This process is repeated in same context with other command functions
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
        
        string score = to_string(vInts[i]);
        score.append(" pts"); // must append so format is printed correctly
        
        cout << left << setw(gamerScoreWidth + spacing) << score << endl;
    }
    vNames.clear();
    vInts.clear();

    cout << "\n";
    
    //retrieve player 1 achievements for the deisred game
    vector<GamePlay> gameHistory = playerDB[playerID1index].getGameHistory();
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
    title.append(playerName1);
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
    gameHistory = playerDB[playerID2index].getGameHistory();
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
    title.append(playerName2);
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

void SummarizePlayer(int playerID, vector<Player>& playerDB, vector<Game>& gameDB){

    cout << "Summarize Player" << endl;
    int playerIndex = searchForPlayerID(playerDB, playerID);
    string playerName = playerDB[playerIndex].getPlayerName();
    
    cout << "Player: " << playerName << endl;
    cout << "Total Gamerscore: " << playerDB[playerIndex].getGamerScore() << endl;
    cout << "\n";
    
    vector<GamePlay> playerHistory = playerDB[playerIndex].getGameHistory();
    // find longest string for Game Name
    vector<string> gameName;
    vector<string> IGNname;
    vector<int> gamerscores;
    
    for(int i = 0; i < playerHistory.size(); i++){
        
        int gameID = playerHistory[i].getGamePlayID();
        int gameIndex = searchForGameID(gameDB, gameID);
        
        string gameNameStr = gameDB[gameIndex].getGameName();
        gameName.push_back(gameNameStr);
        
        //string playerIGNname = gameDB[gameIndex].getPlayerIGN();
        string playerIGNname = playerHistory[i].getPlayerIGN();
        IGNname.push_back(playerIGNname);
        
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
    
    cout << numberSpacing << left << setw(gameTitleWidth + spacing) << "Game";
    cout << left << setw(achievementTitleWidth + spacing) << "Achievement";
    cout << left << setw(gamerscoreTitleWidth + spacing) << "Gamerscore";
    cout << left << setw(IGNtitleWidth) << "IGN" << endl;
    
    int separatorLength = numberSpacing.size() + gameTitleWidth + spacing
                        + achievementTitleWidth + spacing + gamerscoreTitleWidth
                        + spacing + IGNtitleWidth;
    printSeparator(separatorLength);
    
    for (int i = 0; i < gameDB.size(); i++){
        int gameID = gameDB[i].getGameID();
        int playsGame = searchforGamePlayID(playerHistory, gameID);
        
        if (playsGame >= 0){
            //get total # Achieve
            vector<Achievement> possibleAchievements = gameDB[i].getAchievementVector();
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
            
            string gameNameStr = gameDB[i].getGameName();
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
    vector<int> friendsList = playerDB[playerIndex].getFriendsList();
    vector<Player> rankedPlayerDB;
    vector<string> vecPlayerName;
    
    for(int i = 0; i < friendsList.size(); i++){
        int playerID = friendsList[i];
        int playerIndex = searchForPlayerID(playerDB, playerID);
        
        Player currPlayer = playerDB[playerIndex];
        rankedPlayerDB.push_back(currPlayer);
        
        string currPlayerName = playerDB[playerIndex].getPlayerName();
        vecPlayerName.push_back(currPlayerName);
    }
    
    // sort the vector according to Gamerscores
    for(int i = 0; i < rankedPlayerDB.size(); i++){
        int j = i;
        
        while( j > 0 && rankedPlayerDB[j].getGamerScore() > rankedPlayerDB[j-1].getGamerScore()){
            Player temp = rankedPlayerDB[j];
            rankedPlayerDB[j] = rankedPlayerDB[j-1];
            rankedPlayerDB[j-1] = temp;
            j--;
        }
    }
    
    int longestStr = findLongestString(vecPlayerName);
    int playerTitleWidth = 6; // "Player" .size()
    
    if(playerTitleWidth < longestStr){
        playerTitleWidth = longestStr;
    }
    gamerscoreTitleWidth = 10; // "Gamerscore" .size()
    
    cout << numberSpacing << left << setw(playerTitleWidth + spacing) << "Friend";
    cout << left << setw(gamerscoreTitleWidth) << "Gamerscore" << endl;
    
    separatorLength = numberSpacing.size() + playerTitleWidth + spacing + gamerscoreTitleWidth;
    printSeparator(separatorLength);
    
    for(int i = 0; i < rankedPlayerDB.size(); i++){
        int playerID = rankedPlayerDB[i].getPlayerID();
        int playerIndex = searchForPlayerID(playerDB, playerID);
        
        string currPlayerName = playerDB[playerIndex].getPlayerName();
        int gamerscore = playerDB[playerIndex].getGamerScore();
        
        string currGamerscore = to_string(gamerscore);
        currGamerscore.append(" pts");
        
        cout << i+1 << ". " << left << setw(playerTitleWidth + spacing) << currPlayerName;
        cout << left << setw(gamerscoreTitleWidth) << currGamerscore << endl;
    }
    cout << "\n";
}

void SummarizeGame(int gameID, vector<Game>& gameDB, vector<Player>& playerDB){
    
    cout << "Summarize Game " << endl;
    int gameIndex = searchForGameID(gameDB, gameID);
    string gameStr = gameDB[gameIndex].getGameName();

    cout << "Game: " << gameStr << endl;
    
    vector<string> vecStr;
    vector<Player> playersOfGame;
    
    //find out who plays store in vector<String>
    for(int i = 0; i < playerDB.size(); i++){
        Player currPlayer = playerDB[i];
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
    
    vector<Achievement> possibleAchievements = gameDB[gameIndex].getAchievementVector();
    
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

void SummarizeAchievement(int gameID, int achievementID, vector<Player>& playerDB, vector<Game>& gameDB){
    
    cout << "Summarize Achievement " << endl;
    int gameIndex = searchForGameID(gameDB, gameID);
    string gameName = gameDB[gameIndex].getGameName();
    
    vector<Achievement> possibleAchievements = gameDB[gameIndex].getAchievementVector();
    int achievementIndex = searchIfAchievedID(possibleAchievements, achievementID);
    string achievementName = possibleAchievements[achievementIndex].getAchievementName();
    
    cout << "Game: " << gameName << endl;
    cout << "Achievement: " << achievementName << endl;
    cout << "\n";
    
    string numberSpacing = string(3, ' ');
    int spacing = 5;
    
    vector<string> playersWithAchievement;
    vector<string> playersIGNWithAchievement;
    double numPlayersAchieved = 0; // number players with acheivement
    double numTotalPlayers = 0; // number players that played game w/o acheivement
    
    // get all players that have gotten the achievement
    for(int i = 0; i < playerDB.size(); i++){
        Player currPlayer = playerDB[i];

        vector<GamePlay> playerHistory = currPlayer.getGameHistory();
        int gamePlayIndex = searchforGamePlayID(playerHistory, gameID);
        
        if (gamePlayIndex >= 0){
            ++numTotalPlayers;
            // if here currPlayer has played the game
            // now check that player has received achievement
            vector<Achievement> playerAchievements = playerHistory[gamePlayIndex].getAwardedAchievements();
            
            int playerAchieved = searchIfAchievedID(playerAchievements, achievementID);
            if( playerAchieved >= 0){
                // if here player has achieved the trophy
                ++numPlayersAchieved;
                
                string currPlayerName = currPlayer.getPlayerName();
                playersWithAchievement.push_back(currPlayerName);
                
                string playerIGN = playerHistory[gamePlayIndex].getPlayerIGN();
                playersIGNWithAchievement.push_back(playerIGN);
            }
        }
    }
    
    // find correct width for function setw()
    int longestStr = findLongestString(playersWithAchievement);
    
    int playerTitleWidth = 23; // "Player with Achievement" .size()
    if ( playerTitleWidth < longestStr){
        playerTitleWidth = longestStr;
    }
    
    longestStr = findLongestString(playersIGNWithAchievement);
    
    int playerIGNTitleWidth = 3; // "IGN" .size()
    if(playerIGNTitleWidth < longestStr){
        playerIGNTitleWidth = longestStr;
    }
    
    cout << numberSpacing << left << setw(playerTitleWidth + spacing)
         << "Player with Achievement";
    cout << left << setw(playerTitleWidth) << "IGN" << endl;;
    
    int separatorLength = numberSpacing.size() + playerTitleWidth + spacing + playerTitleWidth;
    printSeparator(separatorLength);
    
    for(int i = 0; i < playersWithAchievement.size(); i++){
        cout << i+1 << ". " << left << setw(playerTitleWidth + spacing)
             << playersWithAchievement[i];
        cout << left << setw(playerTitleWidth) << playersIGNWithAchievement[i] << endl;
        
    }
    
    //print percentage of players that have achieved this
    double percentage = numPlayersAchieved / numTotalPlayers;
    percentage *= 100; // correctly format
    
    cout << "% of players that play and have achievement: " << percentage << "%" << endl;
    cout << "\n";
}

void AchievementRanking(vector<Player>& playerDB){

    cout << "Achievement Ranking " << endl;
    vector<int> gamerScores;
    int longestStr = 0;
    // find the longest playername and longest gamerscore in terms of chars
    // this is needed to set the correct width in funciton setw()
    
    for(int i = 0; i < playerDB.size(); i++){
        string playerName = playerDB[i].getPlayerName();
        
        int playerNameLength = playerName.size();
        if (playerNameLength > longestStr)
            longestStr = playerNameLength;
        
        int gamerScore = playerDB[i].getGamerScore();
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
    vector<Player> rankedPlayerDB = playerDB;
    
    // sort the vector according to Gamerscores
    for(int i = 0; i < rankedPlayerDB.size(); i++){
        int j = i;
        
        while( j > 0 && rankedPlayerDB[j].getGamerScore() > rankedPlayerDB[j-1].getGamerScore()){
            Player temp = rankedPlayerDB[j];
            rankedPlayerDB[j] = rankedPlayerDB[j-1];
            rankedPlayerDB[j-1] = temp;
            j--;
        }
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
        vector<Player> playerDB;
        vector<Game> gameDB;
        
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
                
                AddPlayer(playerID, playerName, playerDB);
            }
            else if (cmd == "AddGame"){
                int gameID;
                string gameName;
                
                cin >> gameID;
                if(cin.fail()) throw runtime_error("ERROR ADDGAME: Incorrect input for GameID\n");
                
                getline(cin, gameName);
                gameName = truncQuotes(gameName);
                
                AddGame(gameID, gameName, gameDB);
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
                
                AddAchievement(gameID, achievementID, achievementName, achievementPoints, gameDB);
                
            }
            else if (cmd == "Plays"){
                int playerID;
                int gameID;
                string playerIGN; //not enclosed with quotation marks
                
                cin >> playerID;
                if(cin.fail()) throw runtime_error("ERROR PLAYS: Incorrect input for PlayerID\n");
                
                cin >> gameID;
                if(cin.fail()) throw runtime_error("ERROR PLAYS: Incorrect input for GameID\n");
                
                getline(cin, playerIGN);
                playerIGN = truncQuotes(playerIGN);
                
                Plays(playerID, gameID, playerIGN, playerDB, gameDB);
            }
            else if (cmd == "AddFriends"){
                int playerID1;
                int playerID2;
                
                cin >> playerID1;
                if(cin.fail()) throw runtime_error("ERROR ADDFRIENDS: Incorrect input for playerID1\n");
                
                cin >> playerID2;
                if(cin.fail()) throw runtime_error("ERROR ADDFRIENDS: Incorrect input for playerID2\n");
                
                AddFriends(playerID1, playerID2, playerDB);
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
                
                Achieve(playerID, gameID, achievementID, playerDB, gameDB);
            }
            else if (cmd == "FriendsWhoPlay"){
                int playerID;
                int gameID;
                
                cin >> playerID;
                if(cin.fail()) throw runtime_error("ERROR FRIENDSWHOPLAY: Incorrect input for PlayerID\n");
                
                cin >> gameID;
                if(cin.fail()) throw runtime_error("ERROR FRIENDSWHOPLAY: Incorrect input for GameID\n");
                
                FriendsWhoPlay(playerID, gameID, playerDB, gameDB);
            }
            else if (cmd == "ComparePlayers"){
                int playerID1;
                int playerID2;
                int gameID;
                
                cin >> playerID1;
                if(cin.fail()) throw runtime_error("ERROR COMPAREPLAYERS: Incorrect input for playerID1\n");
                
                cin >> playerID2;
                if(cin.fail()) throw runtime_error("ERROR COMPAREPLAYERS: Incorrect input for playerID2\n");
                
                cin >> gameID;
                if(cin.fail()) throw runtime_error("ERROR COMPAREPLAYERS: Incorrect input for GameID\n");
                
                ComparePlayers(playerID1, playerID2, gameID, playerDB, gameDB);
            }
            else if (cmd == "SummarizePlayer"){
                int playerID;
                
                cin >> playerID;
                if(cin.fail()) throw runtime_error("ERROR SUMMARIZEPLAYER: Incorrect input for PlayerID\n");
                
                SummarizePlayer(playerID, playerDB, gameDB);
            }
            else if (cmd == "SummarizeGame"){
                int gameID;
                
                cin >> gameID;
                if(cin.fail()) throw runtime_error("ERROR SUMMARIZEGAME: Incorrect input for GameID\n");
                
                SummarizeGame(gameID, gameDB, playerDB);
            }
            else if (cmd == "SummarizeAchievement"){
                int gameID;
                int achievementID;
                
                cin >> gameID;
                if(cin.fail()) throw runtime_error("ERROR SUMMARIZEACHIEVEMENT: Incorrect input for GameID\n");
                
                cin >> achievementID;
                if(cin.fail()) throw runtime_error("ERROR SUMMARIZEACHIEVEMENT: Incorrect input for AchievementID\n");
                
                SummarizeAchievement(gameID, achievementID, playerDB, gameDB);
            }
            else if (cmd == "AchievementRanking"){
                    AchievementRanking(playerDB);
            }
            else if(cmd == ""){
                break;
            }
            else{
                throw runtime_error("ERROR COMMAND: Incorrect command re-run and try again.\n");
            }
            cmd = "";
        }
        return 0;
    }
    catch (const runtime_error& e){
        cout << e.what();
        return 1;
    }
}
// ======================== End of Main ========================