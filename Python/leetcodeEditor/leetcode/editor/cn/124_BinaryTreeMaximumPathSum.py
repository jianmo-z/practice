from typing import *
from functools import *
import sys


# 路径 被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中 至多出现一次 。该路径 至少包含一个 节点，且不
# 一定经过根节点。 
# 
#  路径和 是路径中各节点值的总和。 
# 
#  给你一个二叉树的根节点 root ，返回其 最大路径和 。 
# 
#  
# 
#  示例 1： 
# 
#  
# 输入：root = [1,2,3]
# 输出：6
# 解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6 
# 
#  示例 2： 
# 
#  
# 输入：root = [-10,9,20,null,null,15,7]
# 输出：42
# 解释：最优路径是 15 -> 20 -> 7 ，路径和为 15 + 20 + 7 = 42
#  
# 
#  
# 
#  提示： 
# 
#  
#  树中节点数目范围是 [1, 3 * 10⁴] 
#  -1000 <= Node.val <= 1000 
#  
#  Related Topics 树 深度优先搜索 动态规划 二叉树 👍 1349 👎 0
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# leetcode submit region begin(Prohibit modification and deletion)
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        self.maxNum = -sys.maxsize

        def dp(root: Optional[TreeNode]):
            if not root:
                return -sys.maxsize
            left_sum = max(0, dp(root.left))
            right_sum = max(0, dp(root.right))
            self.maxNum = max(self.maxNum, root.val + left_sum + right_sum)
            return root.val + max(left_sum, right_sum)

        dp(root)
        return self.maxNum


# leetcode submit region end(Prohibit modification and deletion)


def test_solution():
    pass
