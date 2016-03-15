#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int d[1002][1002];
typedef pair<int, int> P;

int main(void){
	int N, M, sx, sy, gx, gy;
	cin >> M >> N;
	int dd[5] = { 0, 1, 0, -1, 0 };
	vector<vector<char>> maze(N, vector<char>(M));
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> maze[i][j];
			d[i][j] = INT_MAX;
			if (maze[i][j] == 's') {
				sx = i;
				sy = j;
			}
			if (maze[i][j] == 'g') {
				gx = i;
				gy = j;
			}
		}
	}
	queue<P> que;
	que.push(P(sx, sy));
	d[sx][sy] = 0;
	
	while (que.size()){
		P p = que.front();
		que.pop();
		if (p.first == gx && p.second == gy) break;
		for (int i = 0; i < 4; i++){
			int nx = p.first + dd[i], ny = p.second + dd[i + 1];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && maze[nx][ny] != '1' && d[nx][ny] == INT_MAX){
				que.push(P(nx, ny));
				d[nx][ny] = d[p.first][p.second] + 1;
			}
		}
	}
	if(d[gx][gy] != INT_MAX) cout << d[gx][gy] << endl;
	else cout << "Fail" << endl;
}
