#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t[10];
//int dp[10 + 1][954304 + 1]; //954304 = 31^4 + 31^3 + 31^2 + 31
int dp[10 + 1][923520 + 1]; //923520 = 30*31^3 + 30*31^2 + 30*31^1 + 30
int pow(int a, int i){
	int sum = 1;
	for (int j = 0; j < i; j++) sum *= a;
	return sum;
}

int numset(int v[4]){
	int num = 0;
	for (int i = 0; i < 4; i++) num += pow(31, i) * min(v[i], 30);
	return num;
}

int diff(int a, int b){
	int aa, bb, num = 0;
	for (int i = 0; i < 4; i++){
		aa = (a / pow(31, i)) % 31;
		bb = (b / pow(31, i)) % 31;
		num += pow(31, i) * max(aa - bb, 0);
	}
	return num;
}

int main(void){
	int N, M, abi[4];
	cin >> N >> M;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < 4; j++) cin >> abi[j];
		t[i] = numset(abi);
	}
	memset(dp, 120, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 0; i < N; i++){
		for (int j = 0; j <= 923520; j++){
			dp[i + 1][j] = min(dp[i][j], dp[i + 1][diff(j, t[i])] + 1);
		}
	}
	for (int i = 0; i < M; i++){
		for (int j = 0; j < 4; j++) cin >> abi[j];
		cout << dp[N][numset(abi)] << endl;
	}
}
