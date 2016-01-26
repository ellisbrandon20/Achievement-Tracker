#include <iostream>
#include <string>


using namespace std;

string truncQuotes(string str){
    
    str.erase(str.begin(), str.begin()+4);
    str.erase(str.end()-3, str.end());
    
    return str;
}

int main(){
    string str = "";
    cin >> str;
    //string str = " \"COD\"";
    cout << "before:" << str << endl;
    cout << "str.size():" << str.size() << endl;
    string temp = truncQuotes(str);
    //str.erase(str.begin(), str.begin()+2);
    //str.erase(str.end()-1, str.end());
    cout << "after:" << temp << endl;
    
    cout << "str.size():" << str.size() << endl;
    
    
    
    return 0;
}