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
			if(cursum > max){
				max = cursum;
			}
			if (cursum < 0){
				cursum = 0;
			}
		}
		return max;
	}

	// 动态规划的方式:DP
    int maxSubArray1(vector<int>& nums) {
        vector<int> res(nums.size(), 0);

        res[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            res[i] = res[i - 1] > 0 ? nums[i] + res[i - 1] : nums[i];
        }
        return *max_element(res.begin(), res.end());
	}
};

void test() {
	vector<int> nums {-2,1,-3,4,-1,2,1,-5,4};
	Solution s;
	cout << s.maxSubArray1(nums) << endl;
}
