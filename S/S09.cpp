#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <functional>
using namespace std;
#define int long long
priority_queue<int, vector<int>, greater<int> > minpq;

vector<char> replace(vector<char> s, vector<char> p){
	int n = s.size();
	vector<char> ns(n);
	for (int i = 0; i < n; i++){
		ns[p[i] - '0'] = s[i];
	}
	return ns;
}

int toint(vector<char> s){
	int n = s.size(), sum = 0;
	const char* cs;
	string ns;
	for (int i = 0; i < n; i++) sum = sum * 10 + s[i] - '0';
	return sum;
	//return atoi(ns.c_str());
}

int ntz(int n, int m){
	int i;
	for (i = 0; i < m; i++) if ((n >> i) & 1) return i;
}

void rec(vector<char> s, int i, int bit, vector<vector<char>> p){
	int m = p.size(), mask, dummy = bit;
	//for (int i = 0; i < m; i++) cout << ((dummy >> i) & 1);
	//cout << " -> ";
	vector<char> ns = replace(s, p[i]);
	//for (int i = 0; i < m; i++) cout << ns[i];
	//cout << endl;
	//cout << toint(ns) << endl;
	minpq.push(toint(ns));
	while (dummy){
		mask = (~dummy + 1) & dummy;
		rec(ns, ntz(mask, m), bit & ~mask, p);
		dummy = dummy & ~mask;
	}
}

signed main(void){
	int n, m, all, min, mm;
	string ss;
	cin >> n;
	vector<char> s(n);
	for (int i = 0; i < n; i++){
		cin >> ss;
		s[i] = atoi(ss.c_str()) + '0' - 1;
	}
	cin >> m;
	all = (1 << m) - 1;
	vector<vector<char>> p(m, vector<char>(n));
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cin >> ss;
			p[i][j] = atoi(ss.c_str()) + '0' - 1;
		}
	}
	for (int i = 0; i < m; i++) rec(s, i, all & ~(1 << i), p);
	min = minpq.top();
	for (int j = n - 1; j >= 0; j--){
		if (j != n - 1) cout << " ";
		mm = min;
		for (int i = 0; i < j; i++) mm /= 10;
		cout << mm % 10 + 1;
	}
}
