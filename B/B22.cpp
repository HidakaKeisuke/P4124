#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
	int M, N, K, speech, maxit = -1;
	cin >> M >> N >> K;
	vector<int> cand(M + 1, 0);
	vector<int>::iterator it;
	cand[M] = N;
	for (int i = 0; i < K; i++){
		cin >> speech;
		speech--;
		for (int j = 0; j < M + 1; j++){
			if (cand[j] > 0 && j != speech){
				cand[j]--;
				cand[speech]++;
			}
		}
	}
	for (int i = 0; i < M; i++){
		maxit = max(maxit, cand[i]);
	}
	for (int i = 0; i < M; i++){
		if (maxit == cand[i]) cout << i + 1 << endl;
	}
}
