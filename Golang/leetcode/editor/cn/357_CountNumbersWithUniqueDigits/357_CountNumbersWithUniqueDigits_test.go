package CountNumbersWithUniqueDigits

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

//给你一个整数 n ，统计并返回各位数字都不同的数字 x 的个数，其中 0 <= x < 10ⁿ 。
//
//
//
//
// 示例 1：
//
//
//输入：n = 2
//输出：91
//解释：答案应为除去 11、22、33、44、55、66、77、88、99 外，在 0 ≤ x < 100 范围内的所有数字。
//
//
// 示例 2：
//
//
//输入：n = 0
//输出：1
//
//
//
//
//
//
// 提示：
//
//
// 0 <= n <= 8
//
// Related Topics 数学 动态规划 回溯 👍 264 👎 0

//leetcode submit region begin(Prohibit modification and deletion)
func countNumbersWithUniqueDigits(n int) int {
	nums := []int{
		1,
		9,
		9 * 9,
		9 * 9 * 8,
		9 * 9 * 8 * 7,
		9 * 9 * 8 * 7 * 6,
		9 * 9 * 8 * 7 * 6 * 5,
		9 * 9 * 8 * 7 * 6 * 5 * 4,
		9 * 9 * 8 * 7 * 6 * 5 * 4 * 3,
	}

	result := 0
	for i := range nums {
		if i > n {
			break
		}
		result += nums[i]
	}

	return result
}

//leetcode submit region end(Prohibit modification and deletion)

func TestCountNumbersWithUniqueDigits(t *testing.T) {
	assert.Equal(t, 1, countNumbersWithUniqueDigits(0))
	assert.Equal(t, 91, countNumbersWithUniqueDigits(2))
}
