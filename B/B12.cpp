#include <iostream>
#include <iomanip>

using namespace std;
int main(void){
    int n, sum, test;
    string a, dummy;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> setw(15) >> a >> dummy;
        sum = 0;
        for(int j = 14; j >= 0; j--){
            test = a[j] - 48;
            if(j%2 == 0) {
                if(2 * test < 10)sum += (2 * test);
                else sum +=  (2 * test) % 10 + 1;
            }
            else sum += test;
        }
        cout << (10 - sum%10)%10 << endl;
    }
}
