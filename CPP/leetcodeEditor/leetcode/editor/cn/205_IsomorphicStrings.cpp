//给定两个字符串 s 和 t，判断它们是否是同构的。 
//
// 如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。 
//
// 所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。 
//
// 示例 1: 
//
// 输入: s = "egg", t = "add"
//输出: true
// 
//
// 示例 2: 
//
// 输入: s = "foo", t = "bar"
//输出: false 
//
// 示例 3: 
//
// 输入: s = "paper", t = "title"
//输出: true 
//
// 说明: 
//你可以假设 s 和 t 具有相同的长度。 
// Related Topics 哈希表 
// 👍 295 👎 0


#include <bits/stdc++.h>
#include "../googletest/include/gtest/gtest.h"

namespace IsomorphicStrings {
    using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            unordered_map<char,char> mapping;
            unordered_set<char> mapping_set;

            for (int i = 0; i < s.size(); ++i) {
                if (mapping.find(s[i]) != mapping.end()) {
                    if(mapping[s[i]] != t[i]) {
                        return false;
                    }
                } else {
                    if (mapping_set.find(t[i]) != mapping_set.end()) {
                        return false;
                    }
                    mapping[s[i]] = t[i];
                    mapping_set.insert(t[i]);
                }
            }
            return true;
        }
    };
//leetcode submit region end(Prohibit modification and deletion)


    TEST(IsomorphicStrings, test01) {
        Solution s;
        ASSERT_TRUE(s.isIsomorphic("egg", "add"));
    }

    TEST(IsomorphicStrings, test02) {
        Solution s;
        ASSERT_FALSE(s.isIsomorphic("foo", "bar"));
    }

    TEST(IsomorphicStrings, test03) {
        Solution s;
        ASSERT_TRUE(s.isIsomorphic("paper", "title"));
    }

    TEST(IsomorphicStrings, test04) {
        Solution s;
        ASSERT_TRUE(s.isIsomorphic("ab", "ca"));
    }

    TEST(IsomorphicStrings, test05) {
        Solution s;
        ASSERT_FALSE(s.isIsomorphic("ab", "aa"));
    }
}