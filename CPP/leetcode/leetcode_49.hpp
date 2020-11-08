/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: leetcode_49
 * 时间: 7/10/19-4:02 PM
 * 作者: pip
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    /**
     * 思路：
     *     1. 遍历strs，对字符串进行排序，然后作为key，原始字符串作为value，存入multimap中
     *     2. 遍历multimap，相同的key必定连续，遍历分组
     * */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        multimap<string, string> mmap;
        vector<vector<string>> ret;
        string tmp;

        if(strs.empty()) {
            return ret;
        }

        // 排序后的数据作为key，原数据为value存入Multimap中
        for(string & it : strs) {
            tmp = it;
            sort(it.begin(), it.end());
            mmap.insert(make_pair(move(it), move(tmp)));
        }

        vector<string> v;
        string str;

        // 拿出第一个元素
        v.push_back(mmap.begin()->second);
        str = mmap.begin()->first;

        auto it = mmap.begin();
        ++it;

        // 进行遍历，multimap数据中相同的key必定连续
        for(;it != mmap.end(); ++it) {
            if(it->first == str) {
                v.push_back(move(it->second));
            } else {
                ret.push_back(move(v));
                v.clear();

                v.push_back(move(it->second));
                str = move(it->first);
            }
        }


        ret.push_back(v);

        return ret;
    }

};

void test() {
    vector<string> strs={};
    Solution s;
    for(auto i: s.groupAnagrams(strs)) {
        for(auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}