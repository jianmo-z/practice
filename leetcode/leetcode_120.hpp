/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: leetcode_120.hpp
 * 时间: 9/4/2019-11:53 AM
 * 作者: Pip
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * 问题链接：https://leetcode.com/problems/triangle/
 * 解题思路：https://www.youtube.com/watch?v=ITV2CglqkWU&list=PLLuMmzMTgVK7vEbeHBDD42pqqG36jhuOr&index=78
 *
 * [                  [
 * [2],                    [2],
 * [3,4],                 [3,4],
 * [6,5,7],              [6,5,7],
 * [4,1,8,3],           [4,1,8,3],
 * ]                 ]
 */

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> v(m, vector<int>(m, INT_MAX));

        // i,j应该看做为v的坐标
        v[0][0] = triangle[0][0];
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j <= i; ++j) {
                // 只与上一行有关，空间复杂度可以优化
                if(0 == j) {
                    v[i][j] = v[i - 1][j] + triangle[i][j];
                } else if(j == i) {
                    v[i][j] = v[i - 1][j - 1] + triangle[i][j];
                } else {
                    v[i][j] = min(v[i -1][j - 1], v[i -1][j]) + triangle[i][j];
                }
            }
        }
        return *min_element(v.back().begin(), v.back().end());
    }

    // 空间优化
    int minimumTotal2(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> v(2, vector<int>(m, INT_MAX));
        // v[0] 上一次结果，v[1] 当前结果，然后交换

        v[0][0] = triangle[0][0];
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j <= i; ++j) {
                if(0 == j) {
                    v[1][j] = v[0][j] + triangle[i][j];
                } else if(j == i) {
                    v[1][j] = v[0][j - 1] + triangle[i][j];
                } else {
                    v[1][j] = min(v[0][j - 1], v[0][j]) + triangle[i][j];
                }
            }
            swap(v[0], v[1]);
        }
        return *min_element(v[0].begin(), v[0].end());
    }
};

void test() {
    Solution s;
    vector<vector<int>> triangle = {
            {2},
            {3,4},
            {6,5,7},
            {4,1,8,3},
    };
    cout << s.minimumTotal(triangle) << endl;
}