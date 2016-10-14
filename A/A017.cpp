#include <iostream>
#include <vector>
using namespace std;

int main(void){
	int H, W, N, h, w, x, bh;
	cin >> H >> W >> N;
	vector<vector<char>> space(H + 1, vector<char>(W));
	for (int i = 0; i < W; i++) space[0][i] = '#';
	for (int i = 1; i < H + 1; i++){
		for (int j = 0; j < W; j++){
			space[i][j] = '.';
		}
	}
	for (int i = 0; i < N; i++){
		cin >> h >> w >> x;
		bh = H;
		while (bh > -1){
			for (int i2 = x; i2 < x + w; i2++){
				if (space[bh][i2] == '#') {
					for (int j = bh + 1; j < bh + h + 1; j++){
						for (int k = x; k < x + w; k++){
							space[j][k] = '#';
						}
					}
					i2 = x + w;
					bh = 0;
				}
			}
			bh--;
		}
	}
	for (int i = H; i >= 1; i--){
		for (int j = 0; j < W; j++){
			cout << space[i][j];
		}
		cout << endl;
	}
}
