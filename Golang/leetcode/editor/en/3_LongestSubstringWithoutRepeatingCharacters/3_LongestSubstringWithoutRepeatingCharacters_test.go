package LongestSubstringWithoutRepeatingCharacters

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

//给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
//
//
//
// 示例 1:
//
//
//输入: s = "abcabcbb"
//输出: 3
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
//
//
// 示例 2:
//
//
//输入: s = "bbbbb"
//输出: 1
//解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
//
//
// 示例 3:
//
//
//输入: s = "pwwkew"
//输出: 3
//解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
//
//
//
//
// 提示：
//
//
// 0 <= s.length <= 5 * 10⁴
// s 由英文字母、数字、符号和空格组成
//
// Related Topics 哈希表 字符串 滑动窗口 👍 7677 👎 0

// leetcode submit region begin(Prohibit modification and deletion)
func lengthOfLongestSubstring(s string) int {
	chSet := map[byte]int{}
	maxLength := 0
	left := 0

	for index := range s {
		pos, ok := chSet[s[index]]
		if ok && pos >= left {
			if maxLength < index-left {
				maxLength = index - left
			}
			left = pos + 1
		}

		chSet[s[index]] = index
	}
	if maxLength < len(s)-left {
		maxLength = len(s) - left
	}

	return maxLength
}

//leetcode submit region end(Prohibit modification and deletion)

func TestLongestSubstringWithoutRepeatingCharacters(t *testing.T) {
	assert.Equal(t, 2, lengthOfLongestSubstring("abba"))
	assert.Equal(t, 3, lengthOfLongestSubstring("abcabcbb"))
	assert.Equal(t, 1, lengthOfLongestSubstring("b"))
	assert.Equal(t, 1, lengthOfLongestSubstring("bb"))
	assert.Equal(t, 1, lengthOfLongestSubstring("bbbbb"))
	assert.Equal(t, 3, lengthOfLongestSubstring("pwwkew"))
	assert.Equal(t, 0, lengthOfLongestSubstring(""))
}
