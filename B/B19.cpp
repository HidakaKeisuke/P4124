#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int N, K, sum;
    cin >> N >> K;
    vector<vector<int>> v(N, vector<int>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> v[i][j];
    }
    for(int i = 0; i < N/K; i++){
        for(int j = 0; j < N/K; j++){
            sum = 0;
            if(j != 0) cout << " ";
            for(int b = 0; b < K; b++){
                for(int a = 0; a < K; a++){
                    sum += v[i * K + b][j * K + a];
                }
            }
            sum /= K * K;
            cout << sum;
        }
        cout << endl;
    }
    
}
