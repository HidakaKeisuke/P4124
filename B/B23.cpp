#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
using namespace std;
int main(void){
	int numi, numj;
	string ss, s;
	vector<long long int> ans;
	vector<vector<int>> plus(10);
	vector<vector<int>> minus(10);
	vector<vector<int>> trans(10);
	vector<int>::iterator iti, itj, itt;
	plus[0].push_back(8);
	plus[1].push_back(7);
	plus[3].push_back(9);
	plus[5].push_back(6);
	plus[5].push_back(9);
	plus[6].push_back(8);
	plus[9].push_back(8);
	minus[6].push_back(5);
	minus[7].push_back(1);
	minus[8].push_back(0);
	minus[8].push_back(6);
	minus[8].push_back(9);
	minus[9].push_back(5);
	minus[9].push_back(3);
	trans[0].push_back(6);
	trans[0].push_back(9);
	trans[2].push_back(3);
	trans[3].push_back(2);
	trans[3].push_back(5);
	trans[5].push_back(3);
	trans[6].push_back(0);
	trans[6].push_back(9);
	trans[9].push_back(0);
	trans[9].push_back(6);
	cin >> ss;
	s = ss;
	for (int i = 0; i < s.size(); i++){
		numi = ss[i] - '0';
		for (itt = trans[numi].begin(); itt != trans[numi].end(); ++itt) {
			s = ss;
			s[i] = *(to_string(*itt).data());
			ans.push_back((long long int)atof(s.c_str()));
		}
		for (int j = 0; j < s.size(); j++){
			if (i == j) continue;
			numj = ss[j] - '0';
			for (iti = minus[numi].begin(); iti != minus[numi].end(); ++iti) {
				s = ss;
				s[i] = *(to_string(*iti).data());
				for (itj = plus[numj].begin(); itj != plus[numj].end(); ++itj) {
					s[j] = *(to_string(*itj).data());
					ans.push_back((long long int)atof(s.c_str()));
				}
			}
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) cout << setw(ss.size()) << setfill('0') << ans[i] << endl;
	if (ans.empty()) cout << "none" << endl;
}