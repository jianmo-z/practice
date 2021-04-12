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

namespace Test05 {
    class Solution {
    public:
        vector<vector<int>> func(vector<int> arr) {
            unordered_map<int, vector<int>> hash;

            for (int i = 0; i < arr.size(); ++i) {
                if (hash.find(arr[i]) == hash.end()) {
                    hash[arr[i]] = {};
                }
                hash[arr[i]].push_back(i);
            }

            vector<vector<int>> ret;

            for (int i = 0; i < arr.size(); ++i) {
                if (hash.find(100 - arr[i]) != hash.end()) {
                    for (int j : hash[100 - arr[i]]) {
                        if (i != j && j < i) {
                            ret.push_back({i, j});
                        }
                    }
                }
            }

            return ret;
        }
    };

    void printVector(vector<vector<int>> arr) {
        for (auto i : arr) {
            cout << i[0] << "," << i[1] << endl;
        }
    }

    TEST(Test05, test01) {
        Solution s;
        printVector(s.func({}));
    }

    TEST(Test05, test02) {
        Solution s;
        printVector(s.func({20, 30, 40, 60, 54, 70, 70, 78}));
    }

    TEST(Test05, test03) {
        Solution s;
        printVector(s.func({50, 50, 50, 50, 50, 50, 50}));
    }

    TEST(Test05, test04) {
        Solution s;
        printVector(s.func({50, 50, 50, 50, 50, 50}));
    }


}