//
// Created by pip on 19-3-10.
//
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	// https://blog.csdn.net/ns_code/article/details/20942045
	int maxSubArray(vector<int>& nums) {
		int max = nums[0], cursum = 0;
		for(int &i: nums) {
			cursum += i;
			cout << cursum << " ";
			if(cursum > max){
				max = cursum;
			}
			if (cursum < 0){
				cursum = 0;
			}
		}
		return max;
	}
};

void test() {
	vector<int> nums {-2,1,-3,4,-1,2,1,-5,4};
	Solution s;
	cout << "max:" << s.maxSubArray(nums) << endl;
}
