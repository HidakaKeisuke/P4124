#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main(){
	int H, W, sx, sy, N;
	char c;
	cin >> H >> W;
	vector<vector<char>> field(H, vector<char>(W));
	string gi;
	
	for (int i = 0; i < H; i++){
		cin >> gi;
		for (int j = 0; j < W; j++) field[i][j] = gi[j];
	}

	cin >> sx >> sy >> N;
	sx--;
	sy--;
	for (int i = 0; i < N; i++){
		cin >> c;
		if (c == 'U'){
			if (0 <= sy - 1 && sy < H) sy--;
			while (0 <= sy - 1 && sy < H && field[sy][sx] == '#') sy--;
		}
		else if (c == 'R'){
			if (0 <= sx && sx + 1 < W) sx++;
			while (0 <= sx && sx + 1 < W && field[sy][sx] == '#') sx++;
		}
		else if (c == 'D'){
			if (0 <= sy && sy + 1 < H) sy++;
			while (0 <= sy && sy + 1 < H && field[sy][sx] == '#') sy++;
		}
		else if (c == 'L'){
			if (0 <= sx - 1 && sx < W) sx--;
			while (0 <= sx - 1 && sx < W && field[sy][sx] == '#') sx--;
		}
	}
	cout << sx + 1 << " " << sy + 1 << endl;
}