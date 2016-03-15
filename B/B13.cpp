#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
int main(void){
	int a, b, c, N, h, m, maxtime;
	cin >> a >> b >> c >> N;
	for (int i = 0; i < N; i++){
		cin >> h >> m;
		if (h * 60 + m + b + c < 540) maxtime = h * 60 + m;
		else break;
	}
	maxtime -= a;
	if(maxtime % 60 > 9) cout << "0" << maxtime / 60 << ":" << maxtime % 60;
	else cout << "0" << maxtime / 60 << ":" << "0" << maxtime % 60;
}
