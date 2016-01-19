/*
    Brandon Ellis
    csce 315-503
    individual project 1 - acheivement tracker
*/

#include <iostream>
using namespace std;

int main(int argc, char *argv[] ){
   
    // figuring out c++ command line arguements
    cout << argc << "\n";
    for (int i = 1; i < argc; ++i) {
        cout << argv[i] << "\n";
    }
    return 0;
}