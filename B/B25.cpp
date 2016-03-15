#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int N, M, K, r, flag, k;
    cin >> N >> M >> K;
    vector<int> rad(N);
    vector<bool> in(N);
    for(int j = 0; j < M; j++){
        cin >> r;
        rad[j] = r - 1;
        in[r - 1] = true;
    }
    cin >> N >> M >> K;
    for(int i = 0; i < K; i++){
        for(int j = 0; j < M; j++){
            flag = 0;
            k = rad[j];
            while(flag == 0){
                k++;
                if(!in[k % N]){
                    in[rad[j]] = false;
                    in[k % N] = true;
                    rad[j] = k % N;
                    flag = 1;
                }
            }
        }
    }
    for(int j = 0; j < M; j++) cout << rad[j] + 1 << endl;
}
