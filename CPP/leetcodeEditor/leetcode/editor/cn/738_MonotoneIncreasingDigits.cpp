//给定一个非负整数 N，找出小于或等于 N 的最大的整数，同时这个整数需要满足其各个位数上的数字是单调递增。 
//
// （当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。） 
//
// 示例 1: 
//
// 输入: N = 10
//输出: 9
// 
//
// 示例 2: 
//
// 输入: N = 1234
//输出: 1234
// 
//
// 示例 3: 
//
// 输入: N = 332
//输出: 299
// 
//
// 说明: N 是在 [0, 10^9] 范围内的一个整数。 
// Related Topics 贪心算法 
// 👍 151 👎 0


#include "../googletest/include/gtest/gtest.h"


//leetcode submit region begin(Prohibit modification and deletion)
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

namespace MonotoneIncreasingDigits {
    class Solution {
    public:
        int monotoneIncreasingDigits(int N) {
            char num[11] = "";

            int len = 0;

            // itoa
            while (N > 0) {
                num[len] = N % 10 + '0';
                N /= 10;
                ++len;
            }
            reverse(num, num + len);

            for (int i = 0; i < len - 1; ++i) {
                if (num[i] > num[i + 1]) {
                    --num[i];
                    for (int j = i + 1; j < len; ++j) {
                        num[j] = '9';
                    }

                    if (i > 0) {
                        i = i - 2;  // 因为++i
                    } else {
                        break;
                    }
                }
            }

            int ret = 0;
            for (int i = 0; i < len; ++i) {
                ret = ret * 10 + num[i] - '0';
            }
            return ret;
        }
    };
//leetcode submit region end(Prohibit modification and deletion)
    TEST(MonotoneIncreasingDigits, test01) {
        Solution s;
        ASSERT_EQ(s.monotoneIncreasingDigits(12342), 12339);
        ASSERT_EQ(s.monotoneIncreasingDigits(2333332), 2299999);
        ASSERT_EQ(s.monotoneIncreasingDigits(1234321), 1233999);
    }
}


