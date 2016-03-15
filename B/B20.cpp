#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(void){
	string str;
	int n;
	stack<string> st;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; i++){
		getline(cin, str);
		if (str[0] == 'g'){
			str.erase(0, 6);
			st.push(str);
		}
		else st.pop();
		cout << st.top() << endl;
	}
	return 0;
}