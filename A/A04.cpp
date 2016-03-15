#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
int main(void){
	int L, n, m, vm, f, t;
	bool flag = true;
	cin >> L >> n >> m;
	map<int, int> dummy;
	vector<map<int, int>> v(n);
	map<int, int>::iterator v_itr;
	for (int i = 0; i < m; i++){
		cin >> vm >> f >> t;
		v[vm - 1][L - f] = L - t;
		v[vm][L - t] = -(L - f);
	}
	vm = f = 0;
	while (flag){
		flag = false;
		for (v_itr = v[vm].begin(); v_itr != v[vm].end(); v_itr++){
			if (v_itr->first > f){
				f = abs(v_itr->second);
				vm += v_itr->second / f;
				flag = true;
				break;
			}
		}
	}
	cout << vm + 1;
}