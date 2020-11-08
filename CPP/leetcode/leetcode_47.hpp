/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: leetcode_47
 * 时间: 7/7/19-9:30 PM
 * 作者: pip
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 *
 * Example:
 *    Input: [1,1,2]
 *    Output:
 *    [
 *      [1,1,2],
 *      [1,2,1],
 *      [2,1,1]
 *    ]
 * */
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<vector<int>> ret(0);
        if(nums.size() <= 1) {
            ret.push_back(nums);
            return ret;
        }

        vector<int> ans;
        vector<bool> visited(nums.size(), false);

        sort(nums.begin(), nums.end());

        dp(ret, ans, nums, visited);

        return ret;
    }

    void dp(vector<vector<int>> &ret, vector<int> &ans, vector<int> &nums, vector<bool> &visited) {
        // 回归条件
        if (ans.size() == nums.size()) {
            ret.push_back(ans);
            return;
        }

        vector<int> tmp = ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (!visited[i]) {

                /// 该if判断保证不会枚举相同的数在同一个位置上，因为数据已经经过排序所以相同数必定连续
                if (!(i && nums[i] == nums[i - 1] && !visited[i - 1])) {
                    visited[i] = true;
                    ans.push_back(nums[i]);
                    dp(ret, ans, nums, visited);

                    visited[i] = false;
                    ans.pop_back();
                }
            }

        }
    }

};

void test() {
    Solution s;
    vector<int> nums{1};
    for (auto i:s.permuteUnique(nums)) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}