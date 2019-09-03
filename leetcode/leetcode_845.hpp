/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: leetcode_845.hpp
 * 时间: 9/2/2019-2:54 PM
 * 作者: Pip
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * 问题链接：https://leetcode.com/problems/longest-mountain-in-array/
 * 解题思路：
 */

class Solution {
public:
    int longestMountain(vector<int>& A) {
        if (A.empty()) {
            return 0;
        }
        vector<int> inc(A.size(), 0);
        vector<int> dec(A.size(), 0);

        // 
        for (int i = 1; i < A.size(); ++i) {
            if (A[i] > A[i - 1]) {
                inc[i] = inc[i - 1] + 1;
            } 
        }
        for (int i = A.size() - 2; i > 0; --i) {
            if (A[i] > A[i + 1]) {
                dec[i] = dec[i + 1] + 1;
            }
        }

        int max = 0;
        for (int i = 0; i < inc.size(); ++i) {
            if (inc[i] && dec[i]) {
                max = max > (inc[i] + dec[i] + 1) ? max : (inc[i] + dec[i] + 1);
            }
        }
        return max;
    }
};

void test() {
    Solution s;
    vector<int> A {2, 2, 2};
    cout << s.longestMountain(A) << endl;
}