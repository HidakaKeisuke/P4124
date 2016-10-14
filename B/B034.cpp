#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>

using namespace std;

int main(){
	int sx, sy, N, dir, gdir, d[4];
	char mt, frbl;
	cin >> sx >> sy;
	for (int i = 0; i < 4; i++) cin >> d[i];
	int dy[4] = { 1, 0, -1, 0 };
	int dx[4] = { 0, 1, 0, -1 };
	cin >> N;
	dir = 0;
	for (int i = 0; i < N; i++){
		cin >> mt >> frbl;
		if (mt == 'm'){
			if (frbl == 'F') gdir = 0;
			else if (frbl == 'R') gdir = 1;
			else if (frbl == 'B') gdir = 2;
			else gdir = 3;
			sx += d[gdir] * dx[(gdir + dir) % 4];
			sy += d[gdir] * dy[(gdir + dir) % 4];
		}
		else {
			if (frbl == 'F') dir = dir;
			else if (frbl == 'R') dir = (dir + 1) % 4;
			else if (frbl == 'B') dir = (dir + 2) % 4;
			else dir = (dir + 3) % 4;
		}
	}
	cout << sx << " " << sy << endl;
}