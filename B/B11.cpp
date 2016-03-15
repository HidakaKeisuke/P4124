#include <iostream>
using namespace std;
int main(void){
    int n, m, sub, p, qq;
    cin >> n >> m;
    p = m / (2 * n);
    sub = m % (2 * n);
    if(sub == 0) {
        sub = 2 * n;
        p--;
    }
    if(sub > n){
        qq = sub - (n + 1);
        sub -= 2 * qq + 1;
    }
    else {
        qq = (n + 1) - sub;
        sub += 2 * qq - 1;
    }
    cout << sub + 2 * p * n;
}
