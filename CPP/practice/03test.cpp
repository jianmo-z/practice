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
 * 作者：归航holly
 * 链接：https://www.nowcoder.com/discuss/584148?channel=666&source_id=feed_index_nctrack
 * 来源：牛客网
 *
 * M*N 二维数组所有平衡线
 * 输入：
 * a[M][N] =
 * 1,2,3
 * 5,3,1
 * 0,1,2 <--- 平衡线
 * 3,6,2
 * 3,-1,2
 * (对每列来说，如果在第X行上、下部分元素的和都相等，则X行为平衡线，输出平衡线行下标)
 */

namespace Test03 {
    class Solution {
    public:
        int getSort(vector<vector<int>> arr) {
            int m = arr.size();
            if (m <= 1) {
                return 0;
            }
            int n = arr[0].size();

            for (int i = 1; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    arr[i][j] += arr[i - 1][j];
                }
            }

            int ret = -1;
            for (int i = 1; i < m && ret == -1; ++i) {
                int cur = arr[i][0] - arr[i - 1][0];
                if (arr[i][0] - cur != arr[m - 1][0] - arr[i][0]) {
                    continue;
                }
                for (int j = 1; j < n; ++j) {
                    int curJ = arr[i][j] - arr[i - 1][j];
                    if (arr[i][j] - curJ != arr[m - 1][j] - arr[i][j]) {
                        ret = -1;
                        break;
                    }
                    ret = i;
                }
            }
            return ret;

        }
    };

    TEST(Test03, test01) {
        vector<vector<int>> arr{
                {1, 2,  3},
                {5, 3,  1},
                {0, 1,  2},
                {3, 6,  2},
                {3, -1, 2}
        };

        Solution s;
        ASSERT_EQ(s.getSort(arr), 2);
    }

    TEST(Test03, test02) {
        vector<vector<int>> arr{
                {1, 2,  3}
        };

        Solution s;
        ASSERT_EQ(s.getSort(arr), 0);
    }

    TEST(Test03, test03) {
        vector<vector<int>> arr{
                {}
        };

        Solution s;
        ASSERT_EQ(s.getSort(arr), 0);
    }
}