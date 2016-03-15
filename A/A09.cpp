#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(void){
	int i, j, ig, jg, H, W, count = 0;
	string s;
	cin >> H >> W;
	vector<vector<char>> v(H, vector<char>(W));
	for (i = 0; i < H; i++){
		cin >> s;
		for (j = 0; j < W; j++) v[i][j] = s[j];
	}
	i = j = 0;
	ig = 0;
	jg = 1;
	while (i < H && i > -1 && j < W && j > -1){
		count++;
		if (v[i][j] == '/'){
			if (ig == 0){
				ig = (-1) * jg;
				jg = 0;
			}
			else {
				jg = (-1) * ig;
				ig = 0;
			}
		}
		else if (v[i][j] == '\\'){
			if (ig == 0){
				ig = jg;
				jg = 0;
			}
			else {
				jg = ig;
				ig = 0;
			}
		}
		i += ig;
		j += jg;
	}
	cout << count;
}
