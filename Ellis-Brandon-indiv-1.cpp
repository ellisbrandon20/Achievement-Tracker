/*
    Brandon Ellis
    csce 315-503
    individual project 1 - acheivement tracker
*/

#include <iostream>
using namespace std;



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
}

int main(){
    
    cout << "\nHello welcome to Acheivement Tracker" << endl;
    cout << "To begin type in the command you wish to run with the correct credentials" << endl;
    cout << "or type \"help\" to list the available commands." << endl;
    
    string input;
    cin >> input;
    if (input == "help") help();
    
    
    
    return 0;
}


//this is branch 1



// YAY