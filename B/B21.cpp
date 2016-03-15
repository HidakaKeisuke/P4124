#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(void){
	int N, flag, s;
	vector<char> es{ 's', /*"sh", "ch", */'o', 'x' };
	vector<char> ies{'a', 'i', 'u', 'e', 'o' };
	string word;
	cin >> N;
	for (int i = 0; i < N; i++){
		flag = 0;
		cin >> word;
		s = word.size() - 1;
		for (int j = 0; j < es.size(); j++){
			//if (word.find_last_of(es[j]) == word.size() - 1) flag = 1;
			if (word[s] == es[j]) flag = 1;
		}
		if (word[s - 1] == 's' && word[s] == 'h') flag = 1;
		if (word[s - 1] == 'c' && word[s] == 'h') flag = 1;
		if (flag == 1) word += "es";
		else if (word[s] == 'f'){
			word.erase(word.end() - 1);
			word += "ves";
		}
		else if (word[s - 1] == 'f' && word[s] == 'e'){
			word.erase(word.end() - 1);
			word.erase(word.end() - 1);
			word += "ves";
		}
		else if (word[s] == 'y'){
			for (int j = 0; j < ies.size(); j++){
				if (word[s - 1] == ies[j]) flag = 1;
			}
			if (flag == 0){
				word.erase(word.end() - 1);
				word += "ies";
			}
			else  word += "s";
		}
		else word += "s";
		cout << word << endl;
	}
}