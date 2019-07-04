/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: leetcode_39.hpp
 * 时间: 7/4/19-9:08 PM
 * 作者: pip
 */

#include <bits/stdc++.h>

using namespace std;

/*
 * Given a set of candidate numbers (candidates) (without duplicates) and a target number (target),
 * find all unique combinations in candidates where the candidate numbers sums to target.
 *
 * The same repeated number may be chosen from candidates unlimited number of times.
 *
 * Note:
 *      All numbers (including target) will be positive integers.
 *      The solution set must not contain duplicate combinations.
 *
 * Example 1:
 * Input: candidates = [2,3,6,7], target = 7,
 *      A solution set is:
 *      [
 *        [7],
 *        [2,2,3]
 *      ]
 *
 * Example 2:
 * Input: candidates = [2,3,5], target = 8,
 * A solution set is:
 * [
 *   [2,2,2,2],
 *   [2,3,3],
 *   [3,5]
 * ]
 *
 * */

/// TODO 重复计算 且 太多结果重复
/// FIXME 需要进行优化

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        vector<int> ans;
        dfs(ret, candidates, ans, target);
        return ret;
    }

    void dfs(vector<vector<int>> &ret, vector<int> &candidates, vector<int> ans, int target) {
        if (target == 0) {
            ret.push_back(ans);
        }

        for (auto it:candidates) {
            if (target < it) {
                return;
            }
            auto tmp = ans;
            tmp.push_back(it);
            dfs(ret, candidates, tmp, target - it);
        }

    }

};

void test() {
    Solution s;
    vector<int> candidates{2, 3, 4};
    int target = 7;
    auto ret = s.combinationSum(candidates, target);
    for (auto i:ret) {
        for (auto j:i) {
            cout << j << " ";
        }
        cout << endl;
    }

}