/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: leetcode_303.hpp
 * 时间: 9/3/2019-3:39 PM
 * 作者: Pip
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * 问题链接：https://leetcode.com/problems/range-sum-query-immutable/
 * 解题思路：https://www.youtube.com/watch?v=awS9dn_XCmI&list=PLLuMmzMTgVK7vEbeHBDD42pqqG36jhuOr&index=81
 */

class NumArray {
public:
    // preSum 第i个元素存储，nums[0, i];
    vector<int> preSum;
    NumArray(vector<int>& nums) {
        preSum.resize(nums.size() + 1);

        preSum[0] = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            preSum[i + 1] = sum;
        }
    }

    int sumRange(int i, int j) {
        return preSum[j + 1] - preSum[i];
    }
};

void test() {
    vector<int> nums {-2, 0, 3, -5, 2, -1};
    NumArray n(nums);
    cout << n.sumRange(0, 5) << endl;
}