#include <iostream>
#include <cmath>
using namespace std;
int main(void){
    double r, y;
    int sum = 0;
    cin >> r;
    y = r;
    for(int i = 0; i < r; i++){
        sum += (int)(sqrt(r * r - i * i) + 1);
    }
    cout << 4 * sum;
}