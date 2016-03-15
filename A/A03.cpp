#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int main(void){
	int i, j, bow, counti, n, x, y, sumb, sumw;
	char p;
	vector<vector<int>> v(8, vector<int>(8, 0));
	v[3][3] = -1;
	v[4][4] = -1;
	v[3][4] = 1;
	v[4][3] = 1;
	cin >> n;
	for (int k = 0; k < n; k++){
		cin >> p >> x >> y;
		if (p == 'B') bow = 1;
		else bow = -1;
		v[x - 1][y - 1] = bow;
		for (int ix = -1; ix <= 1; ix++){
			for (int iy = -1; iy <= 1; iy++){
				if (ix == 0 && iy == 0) continue;
				counti = 0;
				i = x - 1 + ix;
				j = y - 1 + iy;
				while (i < 8 && i > -1 && j < 8 && j > -1){
					counti++;
					if (v[i][j] == bow){
						for (int c = 1; c < counti; c++) v[x - 1 + ix * c][y - 1 + iy * c] *= -1;
						break;
					}
					if (v[i][j] == 0) break;
					i += ix;
					j += iy;
				}
			}
		}
	}
	sumb = sumw = 0;
	for (int k = 0; k < 8; k++) sumb += count((v[k]).begin(), (v[k]).end(), 1);
	cout << setw(2) << setfill('0') << sumb << "-";
	for (int k = 0; k < 8; k++) sumw += count((v[k]).begin(), (v[k]).end(), -1);
	cout << setw(2) << setfill('0') << sumw;
	if (sumb > sumw) cout << " The black won!";
	else if (sumb < sumw) cout << " The white won!";
	else cout << " Draw!";
}