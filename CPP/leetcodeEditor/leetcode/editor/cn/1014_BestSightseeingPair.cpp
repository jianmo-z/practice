#include <bits/stdc++.h>
#include "../googletest/include/gtest/gtest.h"

//给你一个正整数数组 values，其中 values[i] 表示第 i 个观光景点的评分，并且两个景点 i 和 j 之间的 距离 为 j - i。 
//
// 一对景点（i < j）组成的观光组合的得分为 values[i] + values[j] + i - j ，也就是景点的评分之和 减去 它们两者之间的距离
//。 
//
// 返回一对观光景点能取得的最高分。 
//
// 
//
// 示例 1： 
//
// 
//输入：values = [8,1,5,2,6]
//输出：11
//解释：i = 0, j = 2, values[i] + values[j] + i - j = 8 + 5 + 0 - 2 = 11
// 
//
// 示例 2： 
//
// 
//输入：values = [1,2]
//输出：2
// 
//
// 
//
// 提示： 
//
// 
// 2 <= values.length <= 5 * 10⁴ 
// 1 <= values[i] <= 1000 
// 
// Related Topics 数组 动态规划 👍 261 👎 0


namespace WordLadder {
    using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
    class Solution {
    private:
        /**
         *
         * @param j
         * @param values
         * @return vector<int> {max(values[i] + i) + (values[j] - j), max(values[j - 1] + (j - 1))}
         */
        vector<int> dp(int j, vector<int> &values) {
            if (j < 0) {
                return {INT_MIN, INT_MIN};
            }
            vector<int> data = dp(j - 1, values);
            return {max(data[0], data[1] + values[j] - j), max(data[1], values[j] + j)};
        }
        /**
         * values[i] + values[j] + i - j  => (values[i] + i) + (values[j] - j)
         * @param values
         * @return
         */
    public:
        int maxScoreSightseeingPair(vector<int> &values) {
            return this->dp(values.size() - 1, values)[0];
        }
    };
//leetcode submit region end(Prohibit modification and deletion)


    TEST(WordLadder, test01) {
        Solution s;
        vector<int> values{8,1,5,2,6};
        ASSERT_EQ(s.maxScoreSightseeingPair(values), 11);
    }
}