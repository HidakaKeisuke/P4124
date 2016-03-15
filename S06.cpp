#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
#define PI 3.14159265358979323846

int main(void){
	int a, b, x, y, r, th, L;
	int ra, rb;
	double nx, ny, nth;
	cin >> a >> b >> x >> y >> r >> th >> L;
	a -= 2 * r;
	b -= 2 * r;
	x -= r;
	y -= r;
	nth = th * PI / 180.0;
	if (th > 270){ // x+, y-
		ra = (L * cos(nth) + x) / a;
		rb = (-L * sin(nth) + (b - y)) / b;
		if (ra % 2) nx = a - ((L * cos(nth) + x) - ra * a);
		else nx = ((L * cos(nth) + x) - ra * a);
		if (rb % 2) ny = ((-L * sin(nth) + (b - y)) - rb * b);
		else ny = b - ((-L * sin(nth) + (b - y)) - rb * b);
	}
	else if (th > 180){ // x-, y-
		ra = (-L * cos(nth) + (a - x)) / a;
		rb = (-L * sin(nth) + (b - y)) / b;
		if (ra % 2) nx = ((-L * cos(nth) + (a - x)) - ra * a);
		else nx = a - ((-L * cos(nth) + (a - x)) - ra * a);
		if (rb % 2) ny = ((-L * sin(nth) + (b - y)) - rb * b);
		else ny = b - ((-L * sin(nth) + (b - y)) - rb * b);
	}
	else if (th > 90){ // x-, y+
		ra = (-L * cos(nth) + (a - x)) / a;
		rb = (L * sin(nth) + y) / b;
		if (ra % 2) nx = (-L * cos(nth) + (a - x) - ra * a);
		else nx = a - (-L * cos(nth) + (a - x) - ra * a);
		if (rb % 2) ny = b - ((L * sin(nth) + y) - rb * b);
		else ny = ((L * sin(nth) + y) - rb * b);
	}
	else { // x+, y+
		ra = (L * cos(nth) + x) / a;
		rb = (L * sin(nth) + y) / b;
		if (ra % 2) nx = a - ((L * cos(nth) + x) - ra * a);
		else nx = ((L * cos(nth) + x) - ra * a);
		if (rb % 2) ny = b - ((L * sin(nth) + y) - rb * b);
		else ny = ((L * sin(nth) + y) - rb * b);
	}
	cout << fixed << setprecision(13) << nx + r << " " << ny + r << endl;
}
