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

        // 当为一个值或者为空时
        if(candidates.empty()) {
            return ret;
        }
        else if(candidates.size() == 1 && (target % candidates[0] == 0)) {
            ret.push_back(vector<int>(target / candidates[0], candidates[0]));
            return ret;
        }

        dfs(ret, candidates, ans, 0, target);
        return ret;
    }

    void dfs(vector<vector<int>> &ret, vector<int> &candidates, vector<int> ans, int index, int target) {
        if (target == 0) {
            ret.push_back(ans);
            return;
        }
        if(target < candidates[index]) {
            return;
        }

        // 选择当前值
        {
            auto tmp = ans;
            tmp.push_back(candidates[index]);
            dfs(ret, candidates, tmp, index, target - candidates[index]);
        }

        // 不选择当前值
        if ((index + 1) < candidates.size()) {
            auto tmp = ans;
            dfs(ret, candidates, tmp, index + 1, target);
        }


    }

};



void test() {
    Solution s;
    vector<int> candidates{2, 3, 5};
    int target = 8;
    auto ret = s.combinationSum(candidates, target);
    for (auto i:ret) {
        for (auto j:i) {
            cout << j << " ";
        }
        cout << endl;
    }

}