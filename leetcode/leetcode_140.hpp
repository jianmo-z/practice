/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: leetcode_140.hpp
 * 时间: 9/10/2019-11:54 AM
 * 作者: Pip
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * 问题链接：https://leetcode.com/problems/word-break-ii/
 * 解题思路：https://www.youtube.com/watch?v=JqOIRBC0_9c&list=PLLuMmzMTgVK7vEbeHBDD42pqqG36jhuOr&index=75
 */

class Solution {
public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {

        vector<string> ret;
        multimap<int, string> resA;
        multimap<int, string> resB;
        unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());
        int n = s.length();
        s = s + " ";

/*
   for (auto it : res) {  // 等于sign[j] == 1
       if (it.first > 0) {
           continue;
       }
       string new_s = s.substr(j + 1, i - (j + 1) + 1);
       if (dict.count(new_s)) {
           res.erase(res.find(it.first));
       }
    }

        for (auto it : res) {  // 等于sign[j] == 1
        if (it.first != j) {
            continue;
        }
        string new_s = s.substr(j + 1, i - (j + 1) + 1);
        if (dict.count(new_s)) {
            res.erase(res.find(it.first));
        }
    }
 * */
        // 跑完第一次循环
        for (int k = 0; k < n; ++k) {
            string new_s = s.substr(0, k);
            if (dict.count(new_s)) {
                resA.insert(make_pair(k, new_s));
            }
        }

        for (int i = 0; i < n;) {
            if (resA.find(i) != resA.end()) {
                for (int j = 0; i + j < n; ++j) {
                    string new_s = s.substr(i, j);
                    if (dict.count(new_s)) {
                        new_s = (*resA.find(i)).second + " " + new_s;
                        resB.insert(make_pair(i + j, new_s));
                    }
                }
            } else {
                ++i;
                resB.insert(resA.begin(), resA.end());
                resA = move(resB);
            }
        }
        for (auto it:resA) {
            // cout << it.second <<endl;
            ret.emplace_back(it.second);
        }
        return ret;
    }
};

void test() {
    Solution s;
    string str = "pineapplepenapple";
    vector<string> wordDict{
            "apple", "pen", "applepen", "pine", "pineapple"
    };
    for (auto it : s.wordBreak(str, wordDict)) {
        cout << it << endl;
    }
}