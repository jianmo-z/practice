package ValidParentheses

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
//
// 有效字符串需满足：
//
//
// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。
//
//
//
//
// 示例 1：
//
//
//输入：s = "()"
//输出：true
//
//
// 示例 2：
//
//
//输入：s = "()[]{}"
//输出：true
//
//
// 示例 3：
//
//
//输入：s = "(]"
//输出：false
//
//
// 示例 4：
//
//
//输入：s = "([)]"
//输出：false
//
//
// 示例 5：
//
//
//输入：s = "{[]}"
//输出：true
//
//
//
// 提示：
//
//
// 1 <= s.length <= 10⁴
// s 仅由括号 '()[]{}' 组成
//
// Related Topics 栈 字符串 👍 3291 👎 0

//leetcode submit region begin(Prohibit modification and deletion)
func isValid(s string) bool {
	stack := make([]byte, 0, len(s))
	chMap := map[byte]byte{
		')': '(',
		']': '[',
		'}': '{',
	}

	for _, ch := range s {
		if ch == '(' || ch == '[' || ch == '{' {
			stack = append(stack, byte(ch))
			continue
		}
		size := len(stack)
		if size == 0 {
			return false
		}
		wantCh, ok := chMap[byte(ch)]
		if !ok || stack[size-1] != wantCh {
			return false
		}

		stack = stack[:size-1]
	}

	return len(stack) == 0
}

//leetcode submit region end(Prohibit modification and deletion)

func TestValidParentheses(t *testing.T) {
	assert.True(t, isValid("()"))
	assert.True(t, isValid("()[]{}"))
	assert.False(t, isValid("(]"))
	assert.False(t, isValid("({[]}"))
	assert.True(t, isValid("{[]}"))
}
