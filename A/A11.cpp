//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//int main(void){
//	int i, j, d, n, a;
//	cin >> d >> n;
//	vector<int> dp(2 * d + 1, -2), newdp(2 * d + 1);
//	vector<string> lor(2 * d + 1, "");
//
//	dp[d]++;
//	for(int i = 0; i < n; i++){
//		cin >> a;
//		for(int j = 0; j < 2 * d + 1; j++){
//			if (dp[j] == i - 1){
//				if (j + a <= 2 * d){
//					newdp[j + a] = i;
//					lor[j + a] = lor[j] + 'R';
//				}
//				if (j - a >= 0){
//					newdp[j - a] = i;
//					lor[j - a] = lor[j] + 'L';
//				}
//			}
//		}
//		dp = newdp;
//	}
//	for(int j = 0; j < 2 * d + 1; j++){
//		if (dp[j] == n - 1){
//			cout << lor[j] << endl;
//			break;
//		}
//	}
//}
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(void){
	int d, n, a;
	cin >> d >> n;
	vector<int> dp(2 * d + 1, -2), newdp(2 * d + 1, -1);
	vector<string> lor(2 * d + 1, ""), newlor(2 * d + 1, "");

	dp[d]++;
	for (int i = 0; i < n; i++){
		cin >> a;
		for (int j = 0; j < 2 * d + 1; j++){
			if (dp[j] == i - 1){
				if (j + a <= 2 * d && newdp[j + a] != i){
					newlor[j + a] = lor[j] + 'R';
					newdp[j + a] = i;
				}
				if (j - a >= 0 && newdp[j - a] != i){
					newlor[j - a] = lor[j] + 'L';
					newdp[j - a] = i;
				}
			}
		}
		lor = newlor;
		dp = newdp;
	}
	for (int j = 0; j < 2 * d + 1; j++){
		if (dp[j] == n - 1){
			cout << lor[j] << endl;
			break;
		}
	}
}