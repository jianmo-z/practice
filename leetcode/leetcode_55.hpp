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
    // https://www.cnblogs.com/grandyang/p/4371526.html
    // 所以当前位置的剩余步数（dp值）和当前位置的跳力中的较大那个数决定了当前能到的最远距离，
    // 而下一个位置的剩余步数（dp值）就等于当前的这个较大值减去1，因为需要花一个跳力到达下一
    // 个位置。

    bool canJump(vector<int>& nums) {
        bool ret = true;
        if(nums.size() <= 1) {
            return ret;
        }
        vector<int> dp(nums.size(), 0);
        for(int i = 0; i< nums.size() - 1; ++i) {
            dp[i] = max(dp[i - 1], nums[i - 1]) - 1;
            if(dp[i] < 0) {
                ret = false;
                break;
            }
        }
        return ret;
    }

};

void test() {
//    vector<int> nums{2,3,1,1,4};
    vector<int> nums{0};
    Solution s;
    cout << s.canJump(nums);
}