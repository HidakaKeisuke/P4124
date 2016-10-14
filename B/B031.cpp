#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	int i, N, start, end, count = 0;
	string s;
	cin >> N >> s;
	start = 0;
	end = N - 1;
	while (end > start){
		for (i = start + 1; i < N; i++){
			if (s[i - 1] == 'b' && s[i] == 'w' || s[i - 1] == 'w' && s[i] == 'b') break;
		}
		start = i;
		for (i = end - 1; i >= 0; i--){
			if (s[i + 1] == 'b' && s[i] == 'w' || s[i + 1] == 'w' && s[i] == 'b') break;
		}
		end = i;
		for (int i = start; i <= end; i++){
			if (s[i] == 'b') s[i] = 'w';
			else s[i] = 'b';
		}
	}
	for (int i = 0; i < N; i++){
		if (s[i] == 'b') count++;
	}
	cout << count << endl;
}