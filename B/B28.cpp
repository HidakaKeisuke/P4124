#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void){
    int n, g, m, k, mem, s, c, t;
    cin >> n >> g >> m;
    vector<vector<int>> group(g + 1);
    vector<vector<string>> log(n + 1);
    vector<int>::iterator it;
    vector<string>::iterator its;
    string msg;
    for(int i = 1; i < g + 1; i++){
        cin >> k;
        for(int j = 0; j < k; j++){
            cin >> mem;
            group[i].push_back(mem);
        }
    }
    for(int i = 0; i < m ; i++){
        cin >> s >> c >> t >> msg;
        if(c){
            for (it = group[t].begin() ; it != group[t].end(); ++it) {
                log[*it].push_back(msg);
            }
        }
        else {
            log[s].push_back(msg);
            log[t].push_back(msg);
        }
    }
    for(int i = 1; i < n + 1 ; i++){
        if(i > 1)cout << "--" << endl;
        for (its = log[i].begin() ; its != log[i].end(); ++its) {
            cout << *its << endl;
        }
    }
}
