#include <iostream>
#include <string>
#include <vector>
using namespace std;

void founder(string name, string search){
    int n = search.length();
    int m = name.length();
    if(n == 0){
        cout << "-1" << endl;
    }
    if(n < m){
        cout << "-1" << endl;
        return;
    }
    string check = search.substr(n - m, m);
    if(check == name){
        cout << check << endl;
        return;
    }
    founder(name, search.substr(0, n - 1));

}


int main(){
    vector<string> dictionary;    
    vector<string> spacelessStrings;
    string dict;
    string spacelessString;
    while(cin >> dict){
        if(dict == "###"){
            break;
        }
        dictionary.push_back(dict);
    }
    
    while(cin >> spacelessString){
        spacelessStrings.push_back(spacelessString);
    }

    for(string i: dictionary){
        for(string h:spacelessStrings){
            founder(i, h);
        }
        cout << "***" << endl;
    }
}