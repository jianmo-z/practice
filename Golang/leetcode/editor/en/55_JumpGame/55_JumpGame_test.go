package JumpGame

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

//给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
//
// 数组中的每个元素代表你在该位置可以跳跃的最大长度。
//
// 判断你是否能够到达最后一个下标。
//
//
//
// 示例 1：
//
//
//输入：nums = [2,3,1,1,4]
//输出：true
//解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。
//
//
// 示例 2：
//
//
//输入：nums = [3,2,1,0,4]
//输出：false
//解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标。
//
//
//
//
// 提示：
//
//
// 1 <= nums.length <= 3 * 10⁴
// 0 <= nums[i] <= 10⁵
//
//
// 👍 1971 👎 0

//leetcode submit region begin(Prohibit modification and deletion)
func canJump(nums []int) bool {
	if len(nums) == 0 {
		return true
	}
	size := len(nums)
	maxRange := 0
	for i := range nums {
		if i <= maxRange {
			if maxRange < i+nums[i] {
				maxRange = i + nums[i]
			}
			if maxRange >= size-1 {
				return true
			}
		} else {
			return false
		}
	}

	return false
}

//leetcode submit region end(Prohibit modification and deletion)

func TestJumpGame(t *testing.T) {
	assert.True(t, canJump([]int{0}))
	assert.False(t, canJump([]int{2, 0, 6, 9, 8, 4, 5, 0, 8, 9, 1, 2, 9, 6, 8, 8, 0, 6, 3, 1, 2, 2, 1, 2, 6, 5, 3, 1, 2,
		2, 6, 4, 2, 4, 3, 0, 0, 0, 3, 8, 2, 4, 0, 1, 2, 0, 1, 4, 6, 5, 8, 0, 7, 9, 3, 4, 6, 6, 5, 8, 9, 3, 4, 3, 7, 0, 4, 9, 0, 9, 8, 4, 3, 0, 7, 7, 1, 9, 1, 9, 4, 9, 0, 1, 9, 5, 7, 7, 1, 5, 8, 2, 8, 2, 6, 8, 2, 2, 7, 5, 1, 7, 9, 6}))
	assert.True(t, canJump([]int{1}))
	assert.True(t, canJump([]int{2, 3, 1, 1, 4}))
	assert.False(t, canJump([]int{3, 2, 1, 0, 4}))
}
