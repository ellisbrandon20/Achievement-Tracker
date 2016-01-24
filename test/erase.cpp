#include <iostream>
#include <string>

using namespace std;

int main(){
    
    string str = " \"COD\"";
    cout << "before:" << str << endl;
    cout << "str.size():" << str.size() << endl;
    str.erase(str.begin(), str.begin()+2);
    str.erase(str.end()-1, str.end());
    cout << "after:" << str << endl;
    
    cout << "str.size():" << str.size() << endl;
    
    
    
    return 0;
}