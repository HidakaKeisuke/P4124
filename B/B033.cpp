#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>

using namespace std;

int main(){
	int W, H;
	cin >> W;
	string printer;
	vector<string> c(W);
	vector<int> m(W, -1);
	for (int i = 0; i < W; i++){
		cin >> c[i];
		m[i] = max(m[i], (int)c[i].size());
	}
	cin >> H;
	vector<vector<string>> r(H, vector<string>(W));
	for (int i = 0; i < H; i++){
		for (int j = 0; j < W; j++){
			cin >> r[i][j];
			m[j] = max(m[j], (int)r[i][j].size());
		}
	}
	printer = "";
	for (int j = 0; j < W; j++){
		printer += "| ";
		printer += c[j];
		for (int k = 0; k < m[j] - c[j].size() + 1; k++) printer += ' ';
	}
	printer += '|';
	cout << printer << endl;
	printer = "";
	for (int j = 0; j < W; j++){
		printer += "|-";
		for (int k = 0; k < m[j] + 1; k++) printer += '-';
	}
	printer += '|';
	cout << printer << endl;
	for (int i = 0; i < H; i++){
		printer = "";
		for (int j = 0; j < W; j++){
			printer += "| ";
			printer += r[i][j];
			for (int k = 0; k < m[j] - r[i][j].size() + 1; k++) printer += ' ';
		}
		printer += '|';
		cout << printer << endl;
	}
}