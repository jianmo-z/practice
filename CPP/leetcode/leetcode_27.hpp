//
// Created by pip on 19-3-10.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	// 4 ms	9.2 MB
	int removeElement(vector<int>& nums, int val) {

		int ret = 0;
		for(int i = 0; i < nums.size(); i++) {
			if(nums[i] != val) {
				nums[ret] = nums[i];
				ret++;
			}
		}
		nums.resize(ret);
		return ret;
	}

};

void test() {
	Solution s;
	vector<int> nums = {1, 2, 3, 2, 1, 1};
	cout << "ret=" << s.removeElement(nums, 5) << endl;
	for(int it : nums) {
		cout << it << endl;
	}
}