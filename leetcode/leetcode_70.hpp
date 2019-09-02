/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: leetcode_70.hpp
 * 时间: 9/2/2019-6:38 PM
 * 作者: Pip
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * 问题链接：https://leetcode.com/problems/climbing-stairs/
 * 解题思路：
 */

class Solution {
public:
    int climbStairs(int n) {
        vector<int> v{1, 1};
        for (int i = 2; i < n + 1; ++i) {
            v.push_back(v[i - 1] + v[i - 2]);
        }
        return v[n];
    }
};

void test() {
    Solution s;
    cout << s.climbStairs(3) << endl;
}