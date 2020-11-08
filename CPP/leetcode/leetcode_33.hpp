//
// Created by pip on 19-3-10.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	// 8 ms	9.7 MB
	int search(vector<int>& nums, int target) {
		int index = -1;

		if(nums.size() == 0) {
			return index;
		} else if(nums.size() == 1) {
			return nums[0] == target ? 0 : -1;
		}
		if(nums[0] > nums[nums.size() - 1]) { // 旋转排序
			if(target >= nums[0]) {
				for (int i = 0; i < nums.size(); ++i) {
					if(nums[i] ==  target) {
						index = i;
						break;
					} else if(nums[i] > nums[i + 1]) {
						break;
					}
				}
			} else {
				for (int i = nums.size() - 1; i > 0 ; --i) {
					if(nums[i] > nums[0]) {
						break;
					} else if(nums[i] ==  target) {
						index = i;
						break;
					}
				}
			}
		} else { // 升排序
			int i = 0;
			for(i = 0; i < nums.size(); ++i) {
				if(nums[i] == target) {
					break;
				}
			}
			index = i == nums.size() ? -1 : i;
		}
		return index;
	}

};

void test() {
	Solution s;
	vector<int> nums = {3, 5, 1};
	int target = 5;
	cout << s.search(nums, target) << endl;
}