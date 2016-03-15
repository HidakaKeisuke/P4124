#include <iostream>
#include <cmath>
#define PI 3.1415926536
using namespace std;
double round2(double in, int len){
	double out;
	out = in * pow(10.0, len);
	out = (double)(int)(out + 0.5);
	return out * pow(10.0, -len);
}

int main(void){
	double oy, ms, sita, x, y, a, orbit;
	cin >> oy >> ms >> sita >> x >> y >> a;
	sita = sita * PI / 180.0;
	orbit = oy + x * tan(sita) - (9.8 * pow(x, 2)) / (2.0 * pow(ms * cos(sita), 2));
	if (abs(y - orbit) <= a / 2.0) cout << "Hit " << round2(abs(y - orbit), 1);
	else cout << "Miss";
}