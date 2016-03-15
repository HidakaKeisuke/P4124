#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <algorithm>
using namespace std;
int main(void){
	int X, Y, Z;
	string cell;
	cin >> X >> Y >> Z;
	vector<bitset<50>> v;
	bitset<50> cells(0);
	for (int i = 0; i < Z; i++){
		cells.reset();
		for (int j = 0; j < X; j++){
			cin >> cell;
			for (int k = 0; k < Y; k++){
				if (cell[k] == '#') cells.set(k);
			}
		}
		cin >> cell;
		v.push_back(cells);
	}
	for (int i = Z - 1; i >= 0; i--){
		for (int k = 0; k < Y; k++){
			if(v[i][k])cout << '#';
			else cout << '.';
		}
		cout << endl;
	}
}