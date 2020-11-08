/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: leetcode_139.hpp
 * 时间: 9/10/2019-11:07 AM
 * 作者: Pip
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * 问题链接：https://leetcode.com/problems/word-break/
 * 解题思路：https://www.youtube.com/watch?v=il8Oi21WZN0&list=PLLuMmzMTgVK7vEbeHBDD42pqqG36jhuOr&index=77
 */

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // 先对wordDict做hash，方便查找
        unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());
        int n = s.length();
        vector<int> tag(s.length() + 1);
        s = " " + s;
        tag[0] = 1;

        // 二维dp
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (tag[j] == 1) {
                    string new_s = s.substr(j + 1, i - (j + 1) +1);
                    if (dict.count(new_s)) {
                        tag[i] = true;
                        break;
                    }
                }
            }
        }
        return tag[n];
    }
};

void test() {
    string str = "leetcode";
    vector<string> wordDict{
        "leet",
        "code",
    };
    Solution s;
    cout << s.wordBreak(str, wordDict) << endl;
}