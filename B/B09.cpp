#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
int main(void){
	int n, t, start = 600, end;
	bool first = true;
	string mem;
	vector<int> vt;
	vector<string> vm;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> mem >> t;
		vm.push_back(mem);
		vt.push_back(t);
	}
	for (int i = 0; i < n; i++){
		end = start + vt[i];
		if (end  > 720 && first) {
			start += 50;
			end += 50;
			first = false;
		}
		cout << start / 60 << ":" << setw(2) << setfill('0') << start % 60;
		cout << " - " << end / 60 << ":" << setw(2) << setfill('0') << end % 60;
		cout << " " << vm[i] << endl;
		start = end + 10;
	}
}
