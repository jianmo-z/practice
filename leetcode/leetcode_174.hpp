/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: leetcode_174.hpp
 * 时间: 9/3/2019-12:52 PM
 * 作者: Pip
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * 问题链接：https://leetcode.com/problems/dungeon-game/
 * 解题思路：https://www.youtube.com/watch?v=pt-xIS6huIg&list=PLLuMmzMTgVK7vEbeHBDD42pqqG36jhuOr&index=83&t=0s
 */

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {


        const vector<vector<int>> & Dungeon = dungeon;
        const int m = Dungeon.size();
        const int n = Dungeon[0].size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
        dp[m][n - 1]  = dp[m - 1][n] = 1;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                     // 当dp[i][j] < 0时，表示多余的hp，则需要重置为1
                    dp[i][j] = max(1, min(dp[i + 1][j], dp[i][j + 1]) - Dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
};

void test() {
    vector<vector<int>> v = {
            {-2, -3, 3},
            {-5, -10, 1},
            {10, 30, -5},
    };
    v = {
            {2, 1}
    };
    Solution s;
    cout << s.calculateMinimumHP(v) << endl;
}