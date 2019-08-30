/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: leetcode_91.hpp
 * 时间: 2019/8/30-21:05
 * 作者: Pip
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * 问题链接：https://leetcode.com/problems/decode-ways/
 * 解题链接：https://www.youtube.com/watch?v=OjEHST4SXfE
 */
/*
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 * */
class Solution {
public:
    unordered_map<int, int> ways;
    int dp(int begin, int end, string& s) {
        if (ways.count(begin)) { return ways[begin]; }  // 从记录的数据中拿值
        if (s[begin] == '0') {  return 0; }  // 字符串以0开头，不合法
        if (begin >= end) { return 1; }  // 一个字符 或 空

        // 取前一个字符
        int c = dp(begin + 1, end, s);

        // 取前两个字符
        int preNum = (s[begin] - '0') * 10 + s[begin + 1] - '0';
        if (preNum <= 26 && preNum >= 1) {
            c += dp(begin + 2, end, s);
        }

        ways[begin] = c;
        return c;
    }
    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        } else {
            return dp(0, int(s.length() - 1), s);
        }
    }
};

void test() {
    Solution s;

    cout << s.numDecodings("10") << endl;
}