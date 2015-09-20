#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include<iostream>
#include<fstream>
using namespace std;
long long ary[100001];
long long magicNum = 0, N;
int main() {
	// your code goes here
	int numC = 0;
	ifstream cin("input.txt");
	cin >> numC;

	for (int cases = 0; cases<numC; cases++) {
		magicNum = 0;
		cin >> N;
		for (int i = 0; i < N; i++)cin >> ary[i];
		bool pos = true;
		for (int i = N-1; i > 0; i--) {
			long long val = ary[i]+magicNum;
			if ((ary[i] % i == 0) || (i - (ary[i] % i) <= magicNum)) {
				magicNum += val / i;
			}
			else {
				pos = false;
				break;
			}
		}
		if (pos)cout << "POSSIBLE" << endl;
		else cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}
