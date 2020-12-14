//给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。 
//
// 示例: 
//
// 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
//输出:
//[
//  ["ate","eat","tea"],
//  ["nat","tan"],
//  ["bat"]
//] 
//
// 说明： 
//
// 
// 所有输入均为小写字母。 
// 不考虑答案输出的顺序。 
// 
// Related Topics 哈希表 字符串 
// 👍 600 👎 0


#include <bits/stdc++.h>
#include "../googletest/include/gtest/gtest.h"

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> result;

        for (string &it : strs) {
            string tmp = it;
            sort(tmp.begin(), tmp.end());
            if (result.find(tmp) == result.end()) {
                result[tmp] = {};
            }
            result[tmp].push_back(it);
        }

        vector<vector<string>> ret;

        for (auto &it: result) {
            ret.push_back(move(it.second));
        }

        return ret;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


TEST(GroupAnagrams, test01) {
    Solution s;
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};

    for (auto& it : s.groupAnagrams(strs)) {
        for(string& s : it) {
            cout << s << " ";
        }
        cout << endl;
    }
}