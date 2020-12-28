//给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复
//的三元组。 
//
// 注意：答案中不可以包含重复的三元组。 
//
// 
//
// 示例： 
//
// 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
//
//满足要求的三元组集合为：
//[
//  [-1, 0, 1],
//  [-1, -1, 2]
//]
// 
// Related Topics 数组 双指针 
// 👍 2837 👎 0


#include <bits/stdc++.h>
#include "../googletest/include/gtest/gtest.h"

namespace ThreeSum {
    using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
    public:
        vector<vector<int>> threeSum(vector<int> &nums) {
            unordered_set<int> numSet;
            set<vector<int>> result;

            for (int i = 0; i < nums.size(); ++i) {
                numSet.insert(nums[i]);
            }

            // a + b + c = 0 -> a + b = -c
            for (int i = 0; i < nums.size(); ++i) {
                for (int j = 0; j < nums.size() && i != j; ++j) {
                    auto it = numSet.find(-nums[i] - nums[j]);
                    if (it != numSet.end()) {
                        vector<int> v{nums[i], nums[j], *it};
                        sort(v.begin(), v.end());
                        result.insert(move(v));
                    }
                }
            }

            vector<vector<int>> ret;
            for (auto &i:result) {
                ret.push_back(move(i));
            }
            return ret;

        }
    };
//leetcode submit region end(Prohibit modification and deletion)

    TEST(ThreeSum, test01) {
        Solution s;
        vector<int> nums{-1, 0, 1, 2, -1, -4};
        for (auto i : s.threeSum(nums)) {
            for (int j : i) {
                cout << j << ' ';
            }
            cout << endl;
        }
    }
}