//
// Created by pip on 19-3-10.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	// 24 ms	10.7 MB
	int removeDuplicates(vector<int> &nums) {
		if (0 == nums.size()) {
			return 0;
		}

		int ret = 1;
		int pre = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			if (nums[i] != pre) {
				pre = nums[i];
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
	vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
	cout << "ret=" << s.removeDuplicates(nums) << endl;
	for(int it:nums) {
		cout << it << endl;
	}
}