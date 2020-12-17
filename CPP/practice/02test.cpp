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
/**
 * https://www.nowcoder.com/discuss/579382
 *
 * 把数组元素按照正负序重排列
 * 给定一个数组，数组它按照下面的规则重排列后的数组：
 *  1. 数组中的正负数相互间隔
 *  2. 符号相同的数字相对顺序不变
 *  3. 如果某种符号的数字多余，放到数组最后
 * 例如：-1,3,2,4,5,-6,7,-9
 * 重排：3,-1,2,-6,4,-9,5,7
 *
 * 要求：空间复杂度要求O(1)
 */

namespace getSort {
    class Solution {
    public:
        vector<int> getSort(vector<int> arr) {
            int positive = 0;
            int size = arr.size();

            // 统计个数
            for (int i = 0; i < size; ++i) {
                if (arr[i] > 0) {
                    ++positive;
                }
            }

            if (positive == arr.size() || positive == 0) {
                return arr;
            }

            // 正数的个数
            positive = arr.size() - positive - 1;

            int offset = 0;
           // 多余的数字放在末尾
            while (true) {
                if (offset == size) {
                    break;
                }

                vector<int>::reverse_iterator it;

                // 找到需要调整的那个数字
                if (positive > 0) {
                    // 正数多
                    it = find_if(arr.rbegin() + offset, arr.rend(), [](int i) {return i > 0;});
                    --positive;
                } else {
                    // 负数多
                    it = find_if(arr.rbegin() + offset, arr.rend(), [](int i) {return i < 0;});
                    ++positive;
                }


                int num = *it;
                // 移动数据
                while (it != arr.rbegin() + offset) {
                    *it = *(it - 1);
                    --it;
                }
                ++offset;
                *it = num;
            }

            return arr;
        }
    };

    TEST(getSort, test01) {
        Solution s;
        for(int i : s.getSort({-1, 3, 2, 4, 5, -6, 7, -9})) {
            cout << i << ' ';
        }
        cout << endl;

        for(int i : s.getSort({-1, -3, -2, -4, -5, -6, -7, -9})) {
            cout << i << ' ';
        }
        cout << endl;

        for(int i : s.getSort({1, 3, 2, 4, 5, 6, 7, 9})) {
            cout << i << ' ';
        }
        cout << endl;

        for(int i : s.getSort({-1, 2})) {
            cout << i << ' ';
        }
        cout << endl;

        for(int i : s.getSort({})) {
            cout << i << ' ';
        }
        cout << endl;
    }
}