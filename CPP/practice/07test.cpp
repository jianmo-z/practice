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

namespace Test07 {
    class Solution {
    public:
        pair<bool, int> binarySearch(vector<int> &arr, int aim) {
            int begin = 0;
            int end = arr.size() - 1;

            pair<bool, int> ret;

            while (begin <= end) {
                // a + (b - a) / 2 ->
                int mid = ((begin ) / 2 + end / 2);
                if(arr[mid] > aim) {
                    end = mid - 1;
                } else if(arr[mid] < aim) {
                    begin = mid + 1;
                } else {
                    ret.first = true;
                    ret.second = mid;
                    break;
                }
            }
            return ret;
        }
    };


    TEST(Test07, test01) {
        Solution s;
        vector<int> arr{1, 4, 6, 8, 10};
        auto ret = s.binarySearch(arr, 6);
        if (ret.first) {
            cout << arr[ret.second] << endl;
        } else {
            cout << "not found" << endl;
        }
    }


    TEST(Test07, test02) {
        Solution s;
        vector<int> arr{1, 4, 6, 8, 10};
        auto ret = s.binarySearch(arr, 1);
        if (ret.first) {
            cout << arr[ret.second] << endl;
        } else {
            cout << "not found" << endl;
        }
    }

    TEST(Test07, test03) {
        Solution s;
        vector<int> arr{1, 4, 6, 8, 10};
        auto ret = s.binarySearch(arr, 10);
        if (ret.first) {
            cout << arr[ret.second] << endl;
        } else {
            cout << "not found" << endl;
        }
    }

    TEST(Test07, test04) {
        Solution s;
        vector<int> arr{1, 4, 6, 8, 10};
        auto ret = s.binarySearch(arr, 11);
        if (ret.first) {
            cout << arr[ret.second] << endl;
        } else {
            cout << "not found" << endl;
        }
    }
}