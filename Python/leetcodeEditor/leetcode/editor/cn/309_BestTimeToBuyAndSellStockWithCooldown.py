from typing import *
from functools import *
import pytest


# 给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。
# 
#  设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）: 
# 
#  
#  你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。 
#  卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。 
#  
# 
#  示例: 
# 
#  输入: [1,2,3,0,2]
# 输出: 3 
# 解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出] 
#  Related Topics 数组 动态规划 👍 997 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        """
        sold: can't buy can't sell
        holding: can't buy, can sell
        cooldown: can buy, can't sell
        """

        def dp(i: int) -> Tuple[int, int, int]:
            if i < 0:
                return -10 ** 9, -10 ** 9, 0
            sold, holding, cooldown = dp(i - 1)
            return max(sold,  # do nothing
                       holding + prices[i]  # sell stock
                       ), \
                   max(holding,  # do nothing
                       cooldown - prices[i]  # buy stock
                       ), \
                   max(cooldown,  # do nothing
                       sold)  # yesterday sold

        return max(dp(len(prices) - 1))


# leetcode submit region end(Prohibit modification and deletion)


def test_solution():
    s = Solution()
    s.maxProfit([1, 2, 3, 0, 2]) == 3
