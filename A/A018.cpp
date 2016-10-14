#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

struct pc{
	int x;
	int y;
	double t;
	double d;
	double r;
};
double dist(double x, double y, double x2, double y2){
	return sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y));
}

double rad(double x, double y, double x2, double y2){
	if (atan2(y2 - y, x2 - x) < 0) return 2 * M_PI + atan2(y2 - y, x2 - x);
	return atan2(y2 - y, x2 - x);
}

double c2r(double x){
	if (x < 0) x = 360 + x;
	return (x * M_PI) / 180;
}

int main(){
	int W, H, M, N, a, b;
	double d, r, radm, radp;
	bool flag;
	cin >> W >> H >> M >> N;
	W++;
	H++;
	vector<pc> c(M);
	for (int i = 0; i < M; i++){
		cin >> c[i].x >> c[i].y >> c[i].t >> c[i].d >> c[i].r;
	}

	for (int i = 0; i < N; i++){
		cin >> a >> b;
		flag = false;
		for (int j = 0; j < M; j++){
			d = dist(c[j].x, c[j].y, a, b);
			r = rad(c[j].x, c[j].y, a, b);
			radm = c2r(c[j].t - c[j].d / 2);
			radp = c2r(c[j].t + c[j].d / 2);
			//cout << d << ", " << r << ", " << radm << ", " << radp << endl;
			if (d <= c[j].r) {
				if (c[j].t - c[j].d / 2 >= 0){
					if (radm <= r && r <= radp){
						flag = true;
						break;
					}
				}
				else {
					if ((radm <= r && r <= 2 * M_PI) || (0 <= r && r <= radp)){
						flag = true;
						break;
					}
				}
			}
		}
		if (flag) cout << "yes" << endl;
		else cout << "no" << endl;
	}

}