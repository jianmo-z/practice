//
// Created by pip on 19-3-10.
//

/* 问题描述：
 * 给定一个数组和一个值，找出数组中那两个数之和等于该数
 * */

#include <bits/stdc++.h>

using namespace std;
int len;

// 递归方式求解
void dp(vector<int> & arr, int aim, vector<int> ans, int index) {
	if(aim == 0 && ans.size() == len) {
		for(int i : ans)
			cout << i << " ";
		cout << endl;
	}
	if(ans.size() == len || arr.size() == index) {
		return ;
	}
	// 选
	if(arr[index] <= aim) {
		ans.push_back(arr[index]);
		dp(arr, aim - arr[index], ans, index + 1);
		ans.pop_back();
	}
	// 不选
	dp(arr, aim, ans, index + 1);
}



void test() {
	vector<int> arr={8, 13, 7, 10, 4, 1};
	int aim = 18;
	len = 3;
	vector<int> ans;

	dp(arr, aim, ans, 0);
}