#include <iostream>
using namespace std;
int main(void){
    int N, M, a, profit, sum = 0;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        profit = 0;
        for(int j = 0; j < N; j++){
            cin >> a;
            profit += a;
        }
        if(profit > 0) sum += profit; 
    }
    cout << sum;
}
