from typing import *
from functools import *
import pytest


# 给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。
# 
#  注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。 
# 
#  
# 
#  示例 1： 
# 
#  
# 输入: s = "leetcode", wordDict = ["leet", "code"]
# 输出: true
# 解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
#  
# 
#  示例 2： 
# 
#  
# 输入: s = "applepenapple", wordDict = ["apple", "pen"]
# 输出: true
# 解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
#      注意，你可以重复使用字典中的单词。
#  
# 
#  示例 3： 
# 
#  
# 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
# 输出: false
#  
# 
#  
# 
#  提示： 
# 
#  
#  1 <= s.length <= 300 
#  1 <= wordDict.length <= 1000 
#  1 <= wordDict[i].length <= 20 
#  s 和 wordDict[i] 仅有小写英文字母组成 
#  wordDict 中的所有字符串 互不相同 
#  
#  Related Topics 字典树 记忆化搜索 哈希表 字符串 动态规划 👍 1334 👎 0


# leetcode submit region begin(Prohibit modification and deletion)
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        words = set(wordDict)

        def dp(s: str) -> bool:
            if s in words: return True
            for i in range(min(len(s), 20)):
                if s[:i] in words and dp(s[i:]):
                    return True
            return False

        return dp(s)


# leetcode submit region end(Prohibit modification and deletion)


def test_solution():
    s = Solution()
    assert s.wordBreak("leetcode", ["leet", "code"])
    assert s.wordBreak("applepenapple", ["apple", "pen"])
    assert not s.wordBreak("catsandog", ["cats", "dog", "sand", "and", "cat"])
