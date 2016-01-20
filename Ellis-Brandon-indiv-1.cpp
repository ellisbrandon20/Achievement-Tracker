/*
    Brandon Ellis
    csce 315-503
    individual project 1 - achievement tracker
 
    branch1
 
    sources:
        - http://stackoverflow.com/questions/16388510/evaluate-a-string-with-a-switch-in-c (switch statement)
*/



/*

        NOTES TO SELF:
        
        - use gameID and playerID to put the entries in increasing order so when you need to
            search for a specified game/player you can use a binary search.
            -- possibly achievementID as well ????



*/



#include <iostream>
#include <string>
#include <sstream>
using namespace std;



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

// ======================== Command Funcitons ========================
void AddPlayer(int PlayerID, string PlayerName){
    
}

void AddGame(int GameID, string GameName){
    
}

void AddAchievement(int GameID, int AchievementID, string AchievementName, int AchievementPoints){
    
}

void Plays(int PlayerID, int GameID, string PlayerIGN){
    
}

void AddFriends(int PlayerID_1, int PlayerID_2){
    
}

void Achieve(int PlayerID, int GameID, int AchievementID){
    
}

void FriendsWhoPlay(int PlayerID, int GameID){
    
}

void ComparePlayers(int PlayerID_1, int PlayerID_2, int GameID){
    
}

void SummarizePlayer(int PlayerID){
    
}

void SummarizeGame(int GameID){
    
}

void SummarizeAchievement(int GameID, int AchievementID){
    
}

void AchievementRanking(){
    
}
// ====================== End Command Funcitons ======================

/*
void tokenizeString(string input){
    cout << "tokenize string"<<endl;
    cout << input << endl;
    
    //removing first word == command
    string cmd;
    istringstream iss (input);
    iss >> cmd;
    cout << "\ncmd = " << cmd << endl;
    cout << "input = " << input << endl;
   // cout << "iss.rdbuf = " << iss.rdbuf() <<endl;
    
    
    // !!!!! changes value of input in main
    
}
 */


// ======================== Main ========================
int main(){
    
    cout << "\nHello welcome to Achievement Tracker" << endl;
    cout << "To begin type in the command you wish to run with the correct credentials" << endl;
    cout << "or type \"help\" to list the available commands." << endl;
    
    string cmd;
    cout << ">";
    cin >> cmd;
    
    if (cmd == "help") help();
    
    // run else if statements to find correct command, then continue to read input
    // NOTE: GameName, AchievementName, and PlayerName are enclosed with quotes ("League of Legends" or "Brandon Ellis")
    else if (cmd == "AddPlayer"){
        int PlayerID;
        string PlayerName;
        cin >> PlayerID;
        //cin >> PlayerName;
        //make this cin read into a function to use it multple times
    
        AddPlayer(PlayerID, PlayerName);
    }
    else if (cmd == "AddGame"){
        int GameID;
        string GameName;
        cin >> GameID;
        //cin >> GameName;
        // **
    
    
        AddGame(GameID, GameName);
    }
    else if (cmd == "AddAchievement"){
        int GameID;
        int AchievementID;
        string AchievementName;
        int AchievementPoints;
        cin >> GameID;
        cin >> AchievementID;
        //cin >> AchievementName
        // **
    
    
        cin >> AchievementPoints;
        AddAchievement(GameID, AchievementID, AchievementName, AchievementPoints);
        
    }
    else if (cmd == "Plays"){
        int PlayerID;
        int GameID;
        string PlayerIGN; //not enclosed with quotation marks
        cin >> PlayerID;
        cin >> GameID;
        cin >> PlayerIGN;
        Plays(PlayerID, GameID, PlayerIGN);
    }
    else if (cmd == "AddFriends"){
        int PlayerID_1;
        int PlayerID_2;
        cin >> PlayerID_1;
        cin >> PlayerID_2;
        AddFriends(PlayerID_1, PlayerID_2);

    }
    else if (cmd == "Achieve"){
        int PlayerID;
        int GameID;
        int AchievementID;
        cin >> PlayerID;
        cin >> GameID;
        cin >> AchievementID;
        Achieve(PlayerID, GameID, AchievementID);
    }
    else if (cmd == "FriendsWhoPlay"){
        int PlayerID;
        int GameID;
        FriendsWhoPlay(PlayerID, GameID);
    }
    else if (cmd == "ComparePlayers"){
        int PlayerID_1;
        int PlayerID_2;
        int GameID;
        cin >> PlayerID_1;
        cin >> PlayerID_2;
        cin >> GameID;
        ComparePlayers(PlayerID_1, PlayerID_2, GameID);
    }
    else if (cmd == "SummarizePlayer"){
        int PlayerID;
        cin >> PlayerID;
        SummarizePlayer(PlayerID);
    }
    else if (cmd == "SummarizeGame"){
        int GameID;
        cin >> GameID;
        SummarizeGame(GameID);
    }
    else if (cmd == "SummarizeAchievement"){
        int GameID;
        int AchievementID;
        cin >> GameID;
        cin >> AchievementID;
        SummarizeAchievement(GameID,AchievementID);
    }
    else if (cmd == "AchievementRanking"){
            AchievementRanking();
    }
    else{
        cerr << "Error incorrect command re-enter the command or type \"help\" to see the list of commands." << endl;
    }

    
    return 0;
}












