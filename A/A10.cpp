#include <iostream>
#include <map>
#include <utility>
#include <cmath>
#include <algorithm>
using namespace std;
int main(void){
	int N, x, y, r, maxsum = -1, sum = 0;
	cin >> N;
	map<long long int, int> mp, plusmp;
	map<long long int, int>::iterator mpit;
	for (int i = 0; i < N; i++){
		cin >> x >> y >> r;
		if (y * y == r * r){
			if (mp.count(10000 * x) == 0) mp[10000 * x] = 0;
			plusmp[10000 * x]++;
		}
		else {
			mp[10000 * x - 10000 * sqrt(r * r - y * y)]++;
			mp[10000 * x + 10000 * sqrt(r * r - y * y)]--;
		}
		//cout << x << " " << y << " " << r << endl;
		//cout << x - sqrt(r * r - y * y) << " : " << x + sqrt(r * r - y * y) << endl;
	}
	for (mpit = mp.begin(); mpit != mp.end(); mpit++) {
		//cout << mpit->first << " -> " << mpit->second << endl;
		sum += mpit->second;
		maxsum = max(maxsum, sum + plusmp[mpit->first]);
	}
	cout << maxsum << endl;
}
