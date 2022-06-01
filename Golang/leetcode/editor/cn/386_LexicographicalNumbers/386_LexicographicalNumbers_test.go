package LexicographicalNumbers

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

//给你一个整数 n ，按字典序返回范围 [1, n] 内所有整数。
//
// 你必须设计一个时间复杂度为 O(n) 且使用 O(1) 额外空间的算法。
//
//
//
// 示例 1：
//
//
//输入：n = 13
//输出：[1,10,11,12,13,2,3,4,5,6,7,8,9]
//
//
// 示例 2：
//
//
//输入：n = 2
//输出：[1,2]
//
//
//
//
// 提示：
//
//
// 1 <= n <= 5 * 10⁴
//
// Related Topics 深度优先搜索 字典树 👍 366 👎 0

//leetcode submit region begin(Prohibit modification and deletion)
// TODO:俺是废物，待理解，这个是抄来的答案
func lexicalOrder(n int) []int {
	ans := make([]int, n)
	num := 1
	for i := range ans {
		ans[i] = num
		if num*10 <= n {
			num *= 10
		} else {
			for num%10 == 9 || num+1 > n {
				num /= 10
			}
			num++
		}
	}
	return ans
}

//leetcode submit region end(Prohibit modification and deletion)

func TestLexicographicalNumbers(t *testing.T) {
	//assert.Equal(t, []int{1, 2}, lexicalOrder(20))
	assert.Equal(t, []int{1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9}, lexicalOrder(13))
}
