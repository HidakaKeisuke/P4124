#include <iostream>
#include <vector>
#include <algorithm>
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
using namespace std;
char c[22][22];

int main(void){
	int H, W, N, ai, bi, Ai, Bi;
	int a, b, A, B;
	bool sflag;
	char t[2];
	t[0] = t[1] = '.';
	cin >> H >> W >> N;
	for (int i = 1; i <= H; i++){
		for (int j = 1; j <= W; j++) cin >> c[i][j];
	}
	for (int i = 0; i <= H + 1; i++){
		c[i][0] = '.';
		c[i][W + 1] = '.';
	}
	for (int i = 0; i <= W + 1; i++){
		c[0][i] = '.';
		c[H + 1][i] = '.';
	}
	for (int i = 0; i < N; i++){
		if (i != 0){
			swap(t[0], c[a][b]);
			swap(t[1], c[A][B]);
		}
		cin >> ai >> bi >> Ai >> Bi;
		a = ai; b = bi; A = Ai; B = Bi;
		if (ai > Ai) swap(ai, Ai);
		if (bi > Bi) swap(bi, Bi);
		swap(t[0], c[a][b]);
		swap(t[1], c[A][B]);
		if (t[0] != t[1]){
			cout << "no" << endl;
			continue;
		}
		sflag = true;
		if (bi == Bi){ // 1
			FOR(i, ai, Ai + 1) if (c[i][bi] != '.') sflag = false;
			if (sflag){
				cout << "yes" << endl;
				continue;
			}
		}
		sflag = true;
		if (ai == Ai){ // 2
			FOR(i, bi, Bi + 1) if (c[ai][i] != '.') sflag = false;
			if (sflag){
				cout << "yes" << endl;
				continue;
			}
		}
		
		FOR(i, 0, W + 2){ // 3
			sflag = true;
			FOR(j, ai, Ai + 1) if (c[j][i] != '.') sflag = false;
			if (sflag) {
				if ((a > A && b > B) || (a < A && b < B)){
					if (Bi > i) FOR(j, i, Bi + 1) if (c[Ai][j] != '.') sflag = false;
					else FOR(j, Bi, i + 1) if (c[Ai][j] != '.') sflag = false;
					if (bi < i) FOR(j, bi, i + 1) if (c[ai][j] != '.') sflag = false;
					else FOR(j, i, bi + 1) if (c[ai][j] != '.') sflag = false;
				}
				else {
					if (Bi > i) FOR(j, i, Bi + 1) if (c[ai][j] != '.') sflag = false;
					else FOR(j, Bi, i + 1) if (c[ai][j] != '.') sflag = false;
					if (bi < i) FOR(j, bi, i + 1) if (c[Ai][j] != '.') sflag = false;
					else FOR(j, i, bi + 1) if (c[Ai][j] != '.') sflag = false;
				}
			}
			if (sflag) break; 
		}
		if (sflag){
			cout << "yes" << endl;
			continue;
		}
		
		FOR(i, 0, H + 2){ // 4
			sflag = true;
			FOR(j, bi, Bi + 1) if (c[i][j] != '.') sflag = false;
			if (sflag) {
				if ((a > A && b > B) || (a < A && b < B)){
					if (Ai > i) FOR(j, i, Ai + 1) if (c[j][Bi] != '.') sflag = false;
					else FOR(j, Ai, i + 1) if (c[j][Bi] != '.') sflag = false;
					if (ai < i) FOR(j, ai, i + 1) if (c[j][bi] != '.') sflag = false;
					else FOR(j, i, ai + 1) if (c[j][bi] != '.') sflag = false;
				}
				else {
					if (Ai > i) FOR(j, i, Ai + 1) if (c[j][bi] != '.') sflag = false;
					else FOR(j, Ai, i + 1) if (c[j][bi] != '.') sflag = false;
					if (ai < i) FOR(j, ai, i + 1) if (c[j][Bi] != '.') sflag = false;
					else FOR(j, i, ai + 1) if (c[j][Bi] != '.') sflag = false;
				}
			}
			if (sflag) break;
		}
		if (sflag){
			cout << "yes" << endl;
			continue;
		}
		else cout << "no" << endl;
	}
}
