#include <iostream>
#include <utility>
#include <string>
using namespace std;
int main(void){
	int w, h, n, x, y, m;
	string dir;
	pair<int, int> p;
	cin >> w >> h >> n >> x >> y;
	p = make_pair(x, y);
	for (int i = 0; i < n; i++){
		cin >> dir >> m;
		if (dir == "U") p.second += m;
		else if (dir == "D") p.second -= m;
		else if (dir == "R") p.first += m;
		else p.first -= m;
	}
	if (p.first%w < 0) p.first = w + p.first%w;
	else p.first = p.first % w;
	if (p.second%h < 0) p.second = h + p.second%h;
	else p.second = p.second % h;
	cout << p.first << " " << p.second;
}