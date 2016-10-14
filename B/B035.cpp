#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

bool sort_less(const pair<string, int> &left, const pair<string, int> &right){
	if (left.second != right.second) return left.second > right.second;
	else return left.first < right.first;
}

int main(){
	int N, M, T, len, day;
	map<string, int> mp, mmp;
	vector<pair<string, int>> vp, vvp;
	string name;
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++){
		cin >> name >> len;
		vp.push_back(pair<string, int>(name, len));
		mp[name] = -1;
		mmp[name] = 0;
	}
	sort(vp.begin(), vp.end(), sort_less);
	for (int i = 0; i < T; i++) mp[vp[i].first] = i;
	for (int i = 0; i < M; i++){
		cin >> day >> name >> len;
		mmp[name] += len;
	}
	for (auto it = mmp.begin(); it != mmp.end(); ++it) vvp.push_back(pair<string, int>(it->first, it->second));
	sort(vvp.begin(), vvp.end(), sort_less);
	for (int i = 0; i < T; i++){
		cout << vvp[i].first << " " << vvp[i].second << " ";
		if (mp[vvp[i].first] == -1) cout << "new" << endl;
		else if (mp[vvp[i].first] > i) cout << "up" << endl;
		else if (mp[vvp[i].first] < i) cout << "down" << endl;
		else cout << "same" << endl;
	}
}