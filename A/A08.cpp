#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
	int p, q, N, M, d, dq, rem, mindays;
	cin >> N >> M;
	rem = N;
	mindays = M + 1;
	vector<int> count(N + 1), days(M);
	for (int i = 0; i < M; i++){
		cin >> d;
		days[i] = d;
	}
	p = 0;
	q = 0;
	while (1){
		while (rem != 0 && q < M){
			dq = days[q++];
			count[dq]++;
			if (count[dq] == 1)rem--;
			//cout << dq << " -> " << count[dq] << endl;
		}
		if (q == M && rem != 0) break;
		while (count[dq] != 0){
			dq = days[p++];
			count[dq]--;
		}
		rem++;
		//cout << q - p + 1 << endl;
		mindays = min(mindays, q - p + 1);
	}
	cout << mindays << endl;
}
