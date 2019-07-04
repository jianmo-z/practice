//
// Created by pip on 19-3-10.
//
#include <bits/stdc++.h>

using namespace std;

void dp(vector<int> &v, int n, int s, int & sum, int win) {
	if(s == 0) {
		sum = sum + (v.size() - win) * 2;
		return ;
	}
	if(n == 0 || n < s) {
		return ;
	}
	// 输 / 平局：n > s
	if(n >= s) {
		dp(v, n - 1, s, sum, win);
	}
	// 赢
	dp(v, n - 1, s - 1, sum, win + 1);

}
void test() {
	int n = 3, s = 2, sum = 0;
	vector<int> v{0, 1, 2};
	dp(v, n, s, sum, 0);
	cout << sum << endl;
}