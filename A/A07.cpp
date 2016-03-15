#include <iostream>
using namespace std;
int rnk[500000];
int pr[500000];

void init(int n){
	for (int i = 0; i < n; i++){
		pr[i] = i;
		rnk[i] = 0;
	}
}

int find(int x){
	if (pr[x] == x){
		return x;
	}
	else {
		return pr[x] = find(pr[x]);
	}
}

void unite(int x, int y){
	x = find(x);
	y = find(y);
	if (x == y) return;

	if (rnk[x] < rnk[y]) pr[x] = y;
	else {
		pr[y] = x;
		if (rnk[x] == rnk[y]) rnk[x]++;
	}
}

bool same(int x, int y){
	return find(x) == find(y);
}

int main(void){
	int N, M, t, a, b;
	cin >> N >> M;
	init(N);
	for (int i = 0; i < M; i++){
		cin >> t >> a >> b;
		if (t){
			if (same(a, b)) cout << "yes" << endl;
			else cout << "no" << endl;
		}
		else unite(a, b);
	}
}