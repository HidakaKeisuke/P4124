#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main(void){
	const int max = 202;
	const int MAX = 2 * max + 1;
	int N, i, j, k, go;
	cin >> N;
	vector< vector<int> > fd(MAX, vector<int>(MAX)), fd2(MAX, vector<int>(MAX, -1));
	vector<pair<int, int>> ch(N);
	pair<int, int> p;
	vector<int> wl, remo;
	int dd[5] = { 1, 0, -1, 0, 1 };
	for (int i = 0; i < N; i++){
		cin >> ch[i].second >> ch[i].first;
		ch[i].first += max;
		ch[i].second += max;
		fd2[ch[i].second][ch[i].first] = 0;
		wl.push_back(i);
	}
	i = j = go = 0;
	k = 1;
	int x, y;
	while (wl.size()){
		if (j == k){
			if (go & 1) k++;
			go++;
			j = 0;
		}
		fd = fd2;
		for (auto itr : wl){
			ch[itr].first += dd[go % 4 + 1];
			ch[itr].second += dd[go % 4];
			if (fd[ch[itr].second][ch[itr].first] == -1) fd2[ch[itr].second][ch[itr].first]--;
		}
		for (auto itr : wl){
			if (fd2[ch[itr].second][ch[itr].first] == -2) {
				fd2[ch[itr].second][ch[itr].first] = i + 1;
			}
			else remo.push_back(itr);
		}
		for (auto x : remo) wl.erase(remove(wl.begin(), wl.end(), x), wl.end());
		j++;
		i++;
		//for (int ii = 195; ii < 205; ii++){
		//	for (int jj = 185; jj < 210; jj++){
		//		cout << setw(3) << fd2[jj][ii];
		//	}
		//	cout << endl;
		//}
	}
	cout << i - 1 << endl;
}
