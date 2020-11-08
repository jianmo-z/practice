/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: leetcode_40
 * 时间: 7/5/19-10:46 AM
 * 作者: pip
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        vector<int> ans;

        // 当为一个值或者为空时
        if (candidates.empty()) {
            return ret;
        } else if (candidates.size() == 1 && target == candidates[0]) {
            ret.push_back(vector<int>(1, candidates[0]));
            return ret;
        }

        dfs(ret, candidates, ans, 0, target);
        return ret;
    }

    void dfs(vector<vector<int>> &ret, vector<int> &candidates, vector<int> ans, int index, int target) {
        if (target == 0) {
            if (find_if(ret.begin(), ret.end(), [&ans](const auto &it){
                return ans == it;
            }) == ret.end()) {
                ret.push_back(ans);
            }
            return;
        }
        if (index == candidates.size() || target < candidates[index]) {
            return;
        }

        // 选择当前值
        {
            auto tmp = ans;
            tmp.push_back(candidates[index]);
            dfs(ret, candidates, tmp, index + 1, target - candidates[index]);
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
    vector<int> ans{2};
    int target = 1;
    auto ret = s.combinationSum2( ans, target);
    for(auto i :ret) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}