#include <iostream>
#include <string>
using namespace std;

string invert(string str){
    if(str.length() == 1){
        if(str == "1"){
            return "0";
        }
        if(str == "0"){
            return "1";
        }
    }
    return invert(str.substr(0, 1)) + invert(str.substr(1, str.length()));
}

string reverse(string str){
    if(str.length() == 1){
        return str;
    }
    return reverse(str.substr(1, str.length()-1)) + str.substr(0, 1);
}

string func(int n){
    if(n == 1){
        return "0";
    }
    return func(n-1) + "1" + reverse(invert(func(n-1)));
}

string founder(string str, int k){
    if(str.length() == k){
        return str.substr(str.length()-1);
    }
    return founder(str.substr(0,str.length()-1), k);
}

int main(){
    int n;
    int k;
    cin >> n >> k;
    cout << founder(func(n),k);
}