#include <iostream>
#include <vector>
using namespace std;
int main(void){
	int N;
	int price, change;
	vector<int> coin{ 500, 100, 50, 10 }, v(4), in(4), down(4);
	for (int j = 0; j < 4; j++)cin >> v[j];
	cin >> N;
	for (int i = 0; i < N; i++){
		cin >> price;
		for (int j = 0; j < 4; j++) cin >> in[j];
		change = 500 * in[0] + 100 * in[1] + 50 * in[2] + 10 * in[3] - price;
		for (int j = 0; j < 4; j++){
			down[j] = 0;
			if (j > 1 && change >= 100) break;
			while (change >= coin[j] && down[j] < v[j]){
				change -= coin[j];
				down[j]++;
			}
			//cout << coin[j] << " : " << down[j] << endl;
			//if (change == 0) break;
		}
		if (change == 0){
			for (int j = 0; j < 4; j++){
				if (j > 0) cout << " ";
				cout << down[j];
				v[j] = v[j] - down[j] + in[j];
			}
			cout << endl;
		}
		else cout << "impossible" << endl;
	}
	return 0;
}