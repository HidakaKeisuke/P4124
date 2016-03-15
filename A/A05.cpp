#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;
int main(void) {
	int a, b, n, p, flag, count;
	bool first = true;
	string pc;
	cin >> a >> b >> n;
	vector<int> point;
	vector<int> score(a, 0);
	for (int i = 0; i < n; i++) {
		cin >> pc;
		if (pc == "G") p = 0;
		else p = atoi(pc.c_str());
		point.push_back(p);
	}
	count = flag = 0;
	for (int i = 0; i < point.size(); i++) {
		if (count == a - 1) {
			if (flag == 1 && (point[i] == b || point[i - 1] + point[i] == b)) score[a - 1] += point[i + 1];
			else if (point[i] == b) score[a - 1] += point[i + 1] + point[i + 2];
			flag++;
			score[a - 1] += point[i];
		}
		else if (first) {
			if (point[i] == b) score[count++] = point[i] + point[i + 1] + point[i + 2];
			else first = false;
		}
		else {
			if (point[i - 1] + point[i] == b) score[count] += point[i + 1];
			score[count++] += point[i - 1] + point[i];
			first = true;
		}
	}
	p = 0;
	for (int i = 0; i < a; i++) p += score[i];
	cout << p;
}