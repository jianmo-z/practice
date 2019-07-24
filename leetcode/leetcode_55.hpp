/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: leetcode_55
 * 时间: 7/17/19-10:05 PM
 * 作者: pip
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * Input: [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
 *
 *
 * Input: [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its maximum
 *              jump length is 0, which makes it impossible to reach the last index.
 * */
class Solution {
public:
    bool canJump(vector<int>& nums) {
        bool ret = false;
        this->jump(nums, 0, 0, ret);
        return ret;
    }
    void jump(vector<int>& nums, int current_pos, int steps,  bool &arrived) {
        if(-1 == steps) {  // 递归出口
            return;
        } else if(steps >= nums.size() - current_pos) {
            arrived = true;
        }
        // 已经到达不需要再递归
        if(arrived) {
            return;
        }
        // 选择当前数
        jump(nums, current_pos + 1, nums[current_pos] - 1, arrived);

        // 不选择下一个数,当steps==0时必须选择当前数字
        if(steps > 0) {
            jump(nums, current_pos + 1, steps - 1, arrived);
        }
    }

};

void test() {
//    vector<int> nums{2,3,1,1,4};
    vector<int> nums{2, 4, 0, 0};
    Solution s;
    cout << s.canJump(nums);
}