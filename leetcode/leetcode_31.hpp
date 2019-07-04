/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: leetcode_31.hpp
 * 时间: 7/4/19-3:28 PM
 * 作者: pip
 */

#include <bits/stdc++.h>

using namespace std;

/*
 * Implement next permutation, which rearranges numbers into the lexicographically
 * next greater permutation of numbers.
 * If such arrangement is not possible, it must rearrange it as the lowest possib-
 * le order (ie, sorted in ascending order).
 * The replacement must be in-place and use only constant extra memory.
 * Here are some examples. Inputs are in the left-hand column and its correspondi-
 * ng outputs are in the right-hand column.
 */

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        if (nums.size() <= 1) {
            return;
        }
//        } else if(nums.size() == 2) {
//            swap(nums[0], nums[1]);
//            return;
//        }

        if(this->isLower(nums, 0, nums.size())) {
            // 降序 ---> 最大值 ---> 排序为升序
            sort(nums.begin(), nums.end());
        } else {
            for(int i = nums.size() - 2; i >= 0; --i) {
                if(!isLower(nums, i, nums.size())){
                    for(int j = nums.size() - 1 ; j > i; --j) {
                        if(nums[j] > nums[i]) {
                            swap(nums[j], nums[i]);
                            sort(nums.begin() + i + 1, nums.end());
                            return;
                        }
                    }

                }
            }

        }
    }
    /// @brief 判断是否为降序
    bool isLower(vector<int>& nums, int begin, int end) {
        bool ret = true;
        /// FIXED 注意边界，别越界了
        // end - 1:注意边界，别越界了
        for (int i = begin; i < end - 1; ++i) {
            if(nums[i] < nums[i + 1]) {
                ret = false;
                break;
            }
        }
        return ret;
    }
};

void test() {
    Solution s;
//    vector<int> nums{4,2,0,2,3,2,0};
    vector<int> nums{1, 1};
    s.nextPermutation(nums);
    for(int &it : nums) {
        cout << it << " ";
    }
    // input    [4,2,0,2,3,2,0]
    // Expected [4,2,0,3,0,2,2]
}