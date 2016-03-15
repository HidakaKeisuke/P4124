#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;
int main(void){
	int x, y, k, N, xi, yi;
	double sum = 0;
	cin >> x >> y >> k >> N;
	vector<pair<int, int>> pair(N);
	for (int i = 0; i < N; i++){
		cin >> xi >> yi >> pair[i].second;
		pair[i].first = (x - xi) * (x - xi) + (y - yi) * (y - yi);
	}
	sort(pair.begin(), pair.end());
	for (int i = 0; i < k; i++) sum += pair[i].second;
	cout << floor((sum / k) + 0.5) << endl;
}
