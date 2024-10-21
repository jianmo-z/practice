package ReverseInteger

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

//给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。
//
// 如果反转后整数超过 32 位的有符号整数的范围 [−2³¹, 231 − 1] ，就返回 0。
//假设环境不允许存储 64 位整数（有符号或无符号）。
//
//
//
// 示例 1：
//
//
//输入：x = 123
//输出：321
//
//
// 示例 2：
//
//
//输入：x = -123
//输出：-321
//
//
// 示例 3：
//
//
//输入：x = 120
//输出：21
//
//
// 示例 4：
//
//
//输入：x = 0
//输出：0
//
//
//
//
// 提示：
//
//
// -2³¹ <= x <= 2³¹ - 1
//
// Related Topics 数学 👍 3534 👎 0

//leetcode submit region begin(Prohibit modification and deletion)
func reverse(x int) int {
	ret := 0
	positive := x > 0
	if !positive {
		x = -x
	}

	for x > 0 {
		if ret > (0x7FFF_FFFF-x%10)/10 {
			return 0
		}
		ret = ret*10 + x%10

		x /= 10
	}

	if ret > 0x7FFF_FFFF {
		return 0
	}

	if !positive {
		ret = -ret
	}

	return ret
}

//leetcode submit region end(Prohibit modification and deletion)

func TestReverseInteger(t *testing.T) {
	assert.Equal(t, 0, reverse(1534236469))
	assert.Equal(t, 123, reverse(321))
	assert.Equal(t, -123, reverse(-321))
	assert.Equal(t, 21, reverse(120))
	assert.Equal(t, -21, reverse(-120))
	assert.Equal(t, 0, reverse(0))
}
