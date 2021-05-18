//给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。 
//
// 注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [10,2]
//输出："210" 
//
// 示例 2： 
//
// 
//输入：nums = [3,30,34,5,9]
//输出："9534330"
// 
//
// 示例 3： 
//
// 
//输入：nums = [1]
//输出："1"
// 
//
// 示例 4： 
//
// 
//输入：nums = [10]
//输出："10"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 100 
// 0 <= nums[i] <= 109 
// 
// Related Topics 排序 
// 👍 655 👎 0


#include <bits/stdc++.h>
//#include "../googletest/include/gtest/gtest.h"
#include "gtest/gtest.h"

namespace LargestNumber {
    using namespace std;
    
//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> trans;
        for (int i : nums) {
            trans.push_back(std::to_string(i));
        }
        sort(trans.begin(), trans.end(), [](string &a, string &b) -> bool {

            return a + b > b + a;
        });
        string ret;
        for (string & it : trans) {
            ret += it;
        }

        // 去除前缀零，但是需要保留一位有效位
        int i = 0;
        for (; i < ret.length(); ++i) {
            if (!(ret[i] == '0' && i != ret.length() - 1)) {
                break;
            }
        }
        return ret.substr(i);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


    TEST(LargestNumber, test01) {
        Solution s;
        vector<int> nums{10,2};
        ASSERT_EQ(s.largestNumber(nums), "210");
    }

    TEST(LargestNumber, test02) {
        Solution s;
        vector<int> nums{3,30,34,5,9};
        ASSERT_EQ(s.largestNumber(nums), "9534330");
    }

    TEST(LargestNumber, test03) {
        Solution s;
        vector<int> nums{2};
        ASSERT_EQ(s.largestNumber(nums), "2");
    }

    TEST(LargestNumber, test04) {
        Solution s;
        vector<int> nums{10};
        ASSERT_EQ(s.largestNumber(nums), "10");
    }

    TEST(LargestNumber, test05) {
        Solution s;
        vector<int> nums{10,2,9,39,17};
        ASSERT_EQ(s.largestNumber(nums), "93921710");
    }

    TEST(LargestNumber, test06) {
        Solution s;
        vector<int> nums{8308,8308,830};
        ASSERT_EQ(s.largestNumber(nums), "83088308830");
    }

    TEST(LargestNumber, test07) {
        Solution s;
        vector<int> nums{0,0};
        ASSERT_EQ(s.largestNumber(nums), "0");
    }
}