/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 *
 * 文件: 02test
 * 时间: 2020/12/15-23:03
 * 作者: Pip
 */


#include <bits/stdc++.h>
#include "../googletest/include/gtest/gtest.h"

using namespace std;

namespace Test04 {
    class Solution {
    public:
        vector<string> func(string &str) {
            vector<int> index;

            for (int i = 0; i < str.size(); ++i) {
                if (str[i] == '?') {
                    index.push_back(i);
                }
            }

            int count = index.size();
            int end= pow(2, count);
            vector<string> ret;
            for (int i = 0; i < end; ++i) {
                string tmp = str;
                int bit = i;
                for (int j = 0; j < count; ++j) {
                    tmp[index[j]] = (bit & 1) + '0';
                    bit >> 1;
                }

                ret.push_back(tmp);
            }

            return ret;
        }
    };

    TEST(Test04, test01) {
        Solution s;
        string str = "0?01?0";
        for(auto str : s.func(str)) {
            cout << str << endl;
        }
    }


    TEST(Test04, test02) {
        Solution s;
        string str = "01";
        for(auto str : s.func(str)) {
            cout << str << endl;
        }
    }



    TEST(Test04, test03) {
        Solution s;
        string str = "";
        for(auto str : s.func(str)) {
            cout << str << endl;
        }
    }


}