//给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
//输出：6
//解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
// 
//
// 示例 2： 
//
// 
//输入：height = [4,2,0,3,2,5]
//输出：9
// 
//
// 
//
// 提示： 
//
// 
// n == height.length 
// 0 <= n <= 3 * 104 
// 0 <= height[i] <= 105 
// 
// Related Topics 栈 数组 双指针 
// 👍 1875 👎 0


#include <bits/stdc++.h>
#include "../googletest/include/gtest/gtest.h"

namespace TrappingRainWater {
    using namespace std;

    class Solution_1 {
    public:
        int trap(vector<int> &height) {
            if (height.empty()) {
                return 0;
            }
            int sum = 0;
            int l = 0;
            int r = height.size() - 1;
            int max_l = height[l];
            int max_r = height[r];

            while (l < r) {
                if (height[l] < height[r]) {
                    sum += min(max_l, max_r) - height[l];
                    ++l;
                    max_l = max(max_l, height[l]);
                } else {
                    sum += min(max_l, max_r) - height[r];
                    --r;
                    max_r = max(max_r, height[r]);
                }
            }

            return sum;
        }
    };

//leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
    public:
        int trap(vector<int> &height) {
            if (height.empty()) {
                return 0;
            }

            const int n = height.size();
            vector<int> l(n);
            vector<int> r(n);

            l[0] = height[0];
            for (int i = 1; i < n; ++i) {
                l[i] = max(height[i], l[i - 1]);
            }

            r[n - 1] = height[n - 1];
            for (int i = n - 2; i >= 0; --i) {
                r[i] = max(height[i], r[i + 1]);
            }

            int sum = 0;
            for (int i = 0; i < n; ++i) {
                sum += min(l[i], r[i]) - height[i];
            }

            return sum;
        }
    };
//leetcode submit region end(Prohibit modification and deletion)


    TEST(TrappingRainWater, test01) {
        Solution s;
        vector<int> height{4, 2, 0, 3, 2, 5};
        s.trap(height);
        ASSERT_EQ(s.trap(height), 9);
    }

    TEST(TrappingRainWater, test02) {
        Solution s;
        vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        s.trap(height);
        ASSERT_EQ(s.trap(height), 6);
    }
}