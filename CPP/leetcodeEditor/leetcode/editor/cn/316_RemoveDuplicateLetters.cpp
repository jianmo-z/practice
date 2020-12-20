//给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。 
//
// 注意：该题与 1081 https://leetcode-cn.com/problems/smallest-subsequence-of-distinct
//-characters 相同 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "bcabc"
//输出："abc"
// 
//
// 示例 2： 
//
// 
//输入：s = "cbacdcbc"
//输出："acdb" 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 104 
// s 由小写英文字母组成 
// 
// Related Topics 栈 贪心算法 字符串 
// 👍 389 👎 0


#include <bits/stdc++.h>
#include "../googletest/include/gtest/gtest.h"

namespace RemoveDuplicateLetters {
    using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
    public:
        string removeDuplicateLetters(string s) {
            bool vis[26] = {false};
            int times[26] = {0};
            for (char c : s) {
                ++times[c - 'a'];
            }

            string stk;
            for (char c : s) {
                if (!vis[c - 'a']) {
                    while (!stk.empty() && stk.back() > c && times[stk.back() - 'a'] > 0) {
                        vis[stk.back() - 'a'] = false;
                        stk.pop_back();
                    }
                    stk.push_back(c);
                    vis[c - 'a'] = true;
                }
                --times[c - 'a'];
            }
            return stk;
        }

    };
//leetcode submit region end(Prohibit modification and deletion)


    TEST(RemoveDuplicateLetters, test01) {
        Solution s;
        ASSERT_EQ(s.removeDuplicateLetters("bcabc"), "abc");
    }

    TEST(RemoveDuplicateLetters, test02) {
        Solution s;
        ASSERT_EQ(s.removeDuplicateLetters(""), "");
    }

    TEST(RemoveDuplicateLetters, test03) {
        Solution s;
        ASSERT_EQ(s.removeDuplicateLetters("cbacdcbc"), "acdb");
    }
}