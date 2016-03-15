#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
int main(void){
    int pmax = 0, pmin = 5;
    map<char, int> map;
    string h;
    cin >> h;
    for(int i = 0; i < 4; i++) map[h[i]]++;
    for(int i = 0; i < 4; i++){
        if(h[i] != '*'){
            pmax = max(pmax, map[h[i]]);
            pmin = min(pmin, map[h[i]]);
        }
    }
    if(pmax * pmin == 4)cout << "TwoPair";
    else {
        pmax += map['*'];
        switch(pmax){
            case 1:
                cout << "NoPair";
                break;
            case 2:
                cout << "OnePair";
                break;
            case 3:
                cout << "ThreeCard";
                break;
            case 4:
                cout << "FourCard";
                break;
        }
    }
}
