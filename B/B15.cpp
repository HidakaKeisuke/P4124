#include <iostream>
#include <vector>
#include <map>
#include <utility> 
using namespace std;

int pow(vector<bool> bit){
	int s = 0, pow = 1;
	for (int i = 6; i >= 0; i--){
		if (bit[i]) s += pow;
		pow *= 2;
	}
	return s;
}

int main(void){
	int bit, sa, sb;
	vector<bool> segA(7), segB(7);
	map<int, bool> map;
	map[126/*1111110*/] = true;
	map[48/*0110000*/] = true;
	map[109/*1101101*/] = true;
	map[121/*1111001*/] = true;
	map[51/*0110011*/] = true;
	map[91/*1011011*/] = true;
	map[95/*1011111*/] = true;
	map[114/*1110010*/] = true;
	map[127/*1111111*/] = true;
	map[123/*1111011*/] = true;
	for (int i = 0; i < 7; i++){
		cin >> bit;
		if (bit) segA[i] = true;
	}
	for (int i = 0; i < 7; i++){
		cin >> bit;
		if (bit) segB[i] = true;
	}
	if (map[pow(segA)] & map[pow(segB)]) cout << "Yes" << endl;
	else cout << "No" << endl;
	swap(segA[1], segA[5]);
	swap(segA[2], segA[4]);
	swap(segB[1], segB[5]);
	swap(segB[2], segB[4]);
	if (map[pow(segA)] & map[pow(segB)]) cout << "Yes" << endl;
	else cout << "No" << endl;
	swap(segA[0], segA[3]);
	swap(segA[1], segA[2]);
	swap(segA[4], segA[5]);
	swap(segB[0], segB[3]);
	swap(segB[1], segB[2]);
	swap(segB[4], segB[5]);
	if (map[pow(segA)] & map[pow(segB)]) cout << "Yes" << endl;
	else cout << "No" << endl;
}
