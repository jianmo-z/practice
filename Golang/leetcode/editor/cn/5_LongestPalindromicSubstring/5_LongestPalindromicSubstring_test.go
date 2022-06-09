package LongestPalindromicSubstring

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

//给你一个字符串 s，找到 s 中最长的回文子串。
//
//
//
// 示例 1：
//
//
//输入：s = "babad"
//输出："bab"
//解释："aba" 同样是符合题意的答案。
//
//
// 示例 2：
//
//
//输入：s = "cbbd"
//输出："bb"
//
//
//
//
// 提示：
//
//
// 1 <= s.length <= 1000
// s 仅由数字和英文字母组成
//
// Related Topics 字符串 动态规划 👍 5305 👎 0

//leetcode submit region begin(Prohibit modification and deletion)
func longestPalindrome(s string) string {
	size := len(s)
	if size == 0 {
		return ""
	}

	start := 0
	maxLen := 0
	getLen := func(begin, end int) int {
		for begin >= 0 && end < size && s[begin] == s[end] {
			begin--
			end++
		}
		return end - begin - 1
	}
	for i := 0; i < size; i++ {
		cur := max(getLen(i, i), getLen(i, i+1))
		if cur > maxLen {
			maxLen = cur
			start = i - (cur-1)/2
		}

	}

	return s[start : start+maxLen]
}

func max(a, b int) int {
	if a > b {
		return a
	}

	return b
}

//leetcode submit region end(Prohibit modification and deletion)

func TestLongestPalindromicSubstring(t *testing.T) {
	assert.Equal(t, "bb", longestPalindrome("cbbd"))
	assert.Equal(t, "bab", longestPalindrome("bab"))
	assert.Equal(t, "bab", longestPalindrome("babad"))
}
