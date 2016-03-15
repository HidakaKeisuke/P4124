#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <vector>
using namespace std;
#define int long long int
signed main(void){
	int sum = 0;
	bool before_di = false;
	string s;
	map<char, int> mp;
	map<char, int>::iterator m;
	vector<int> stack;
	vector<int>::iterator st;
	for (int i = 0; i < 26; i++) mp['a' + i] = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == '('){
			stack.push_back(sum);
			sum = 0;
		}
		else if (s[i] == ')'){
			stack.pop_back();
		}
		else if (isdigit(s[i])){
			sum = 10 * sum + s[i] - '0';
		}
		else {
			if (i > 0) if (isdigit(s[i - 1])) before_di = true;
			if (before_di) stack.push_back(sum);
			int st_sum = 1;
			for (st = stack.begin(); st != stack.end(); ++st) st_sum *= *st;
			mp[s[i]] += st_sum;
			if (before_di){
				stack.pop_back();
				before_di = false;
			}
			sum = 0;
		}
	}
	for (m = mp.begin(); m != mp.end(); m++) cout << m->first << " " << m->second << endl;
}
