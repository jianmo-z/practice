/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: leetcode_926.hpp
 * 时间: 9/2/2019-12:57 PM
 * 作者: Pip
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * 问题链接：https://leetcode.com/problems/flip-string-to-monotone-increasing/
 * 解题思路：
 */

class Solution {
public:
    int minFlipsMonoIncr(string S) {
        if (S.empty()) {
            return 0;
        }
        vector<int> LSize(S.length() + 1, 0);
        vector<int> RSize(S.length() + 1, 0);

        // 从前向后遍历，存放数据位置[1, S.size() + 1]
        for (int i = 1; i < S.size() + 1; ++i) {
            LSize[i] = LSize[i - 1] + S[i - 1] - '0';
        }

        // 从后向前遍历，存放数据位置[0, S.size()]
        for (int i = S.length() - 1; i >= 0; --i) {
            RSize[i] = RSize[i + 1] + '1' - S[i];
        }

        // 找出最小值，注意边界：当左边没有0 和 右边没有1的边界
        int ret = LSize[1] + RSize[1];
        for (int i = 0; i < S.size() + 1; ++i) {
            ret = min(ret, LSize[i] + RSize[i]);
        }
        return ret;
    }
};

void test() {
    Solution s;
    cout << s.minFlipsMonoIncr("11011") << endl;
}