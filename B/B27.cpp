#include <iostream>
#include <vector>

using namespace std;
int main(void) {
	int H, W, N, L, a, b, c, d;
	cin >> H >> W >> N;
	vector< vector<int> > t(H, vector<int>(W));
	vector<int> p(N, 0);
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> t[i][j];
		}
	}
	cin >> L;
	int k = 0;
	for (int l = 0; l < L; l++) {
	    cin >> a >> b >> c >> d;
	    if ( t[a - 1][b - 1] == t[c - 1][d - 1]) p[k] += 2;
	    else k = (k + 1) % N;
	}

	for(int i = 0; i < N; i++) cout << p[i] << endl;
}