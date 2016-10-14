#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

#define int unsigned long long

int s2i(string x[8], int len){
	int sum = 0;
	vector<int> top(len), bot(len);
	for (int i = 0; i < len; i++){
		if (x[0][i] == '|') top[i] = 1;
		else top[i] = 0;
	}
	for (int j = 0; j < 5; j++){
		for (int i = 0; i < len; i++){
			if (x[j + 3][i] == '|') bot[i] = j;
		}
	}
	for (int i = 0; i < len; i++){
		sum = 10 * sum + top[i] * 5 + bot[i];
	}
	return sum;
}

void i2s(int sum, int len, vector<string> &s){
	int dig;
	string sa = "";
	for (int i = 0; i < len; i++) sa += '*';
	for (int i = 0; i < 8; i++) s[i] = sa;
	for (int i = len - 1; i >= 0; i--){
		dig = sum % 10;
		sum /= 10;
		if (dig / 5) s[0][i] = '|';
		else s[1][i] = '|';
		s[dig % 5 + 3][i] = '|';
	}
	sa = "";
	for (int i = 0; i < len; i++) sa += '=';
	s[2] = sa;
}

signed main() {
	int W, aa, bb;
	cin >> W;
	string a[8], b[8];
	vector<string> ss(8);
	for (int i = 0; i < 8; i++) cin >> a[i];
	for (int i = 0; i < 8; i++) cin >> b[i];
	aa = s2i(a, W);
	bb = s2i(b, W);
	i2s(aa + bb, W, ss);
	for (int i = 0; i < 8; i++) cout << ss[i] << endl;
}