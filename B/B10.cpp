#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
	char T;
	int U, dist, md;
	map<int, int> mapA, mapB;
	vector<int> XA, XB;
	map<int, int>::iterator it;
	vector<int> p;
	cin >> T >> U;
	for (int i = 0; i < 22; i++){
		cin >> dist;
		if (i < 11){
			mapA[dist] = i;
			XA.push_back(dist);
		}
		else {
			mapB[dist] = i - 11;
			XB.push_back(dist);
		}
	}
	if (T == 'A'){
		sort(XB.begin(), XB.end());
		md = max(XB[9], XA[U - 1]);
		for (it = mapA.begin(); it != mapA.end(); it++) {
			if (it->first > md && it->first >=55) p.push_back(it->second + 1);
		}
	}
	else {
		sort(XA.begin(), XA.end());
		md = min(XA[1], XB[U - 1]);
		for (it = mapB.begin(); it != mapB.end(); it++) {
			if (it->first < md && it->first <= 55) p.push_back(it->second + 1);
		}
	}
	sort(p.begin(), p.end());
	for (int i = 0; i < p.size(); i++) cout << p[i] << endl;
	if (p.empty())cout << "None";
}
