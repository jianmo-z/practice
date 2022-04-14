package RotateString

import (
	"github.com/stretchr/testify/assert"
	"strings"
	"testing"
)

//给定两个字符串, s 和 goal。如果在若干次旋转操作之后，s 能变成 goal ，那么返回 true 。
//
// s 的 旋转操作 就是将 s 最左边的字符移动到最右边。
//
//
// 例如, 若 s = 'abcde'，在旋转一次之后结果就是'bcdea' 。
//
//
//
//
// 示例 1:
//
//
//输入: s = "abcde", goal = "cdeab"
//输出: true
//
//
// 示例 2:
//
//
//输入: s = "abcde", goal = "abced"
//输出: false
//
//
//
//
// 提示:
//
//
// 1 <= s.length, goal.length <= 100
// s 和 goal 由小写英文字母组成
//
// Related Topics 字符串 字符串匹配 👍 241 👎 0

//leetcode submit region begin(Prohibit modification and deletion)
func rotateString(s string, goal string) bool {
	if len(s) != len(goal) {
		return false
	}

	size := len(goal)
	s = s + s

	for i := 0; i <= size; i++ {
		a := s[i : size+i]
		if strings.Compare(a, goal) == 0 {
			return true
		}
	}

	return false
}

//leetcode submit region end(Prohibit modification and deletion)

func TestRotateString(t *testing.T) {
	assert.True(t, rotateString("aba", "aba"))
	assert.True(t, rotateString("abcde", "bcdea"))
	assert.True(t, rotateString("abcde", "cdeab"))
	assert.False(t, rotateString("abcde", "abced"))
	assert.False(t, rotateString("aaaa", "aaab"))
}
