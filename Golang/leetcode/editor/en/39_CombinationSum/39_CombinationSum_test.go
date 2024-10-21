package CombinationSum

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

//给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的
// 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。
//
// candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。
//
// 对于给定的输入，保证和为 target 的不同组合数少于 150 个。
//
//
//
// 示例 1：
//
//
//输入：candidates = [2,3,6,7], target = 7
//输出：[[2,2,3],[7]]
//解释：
//2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
//7 也是一个候选， 7 = 7 。
//仅有这两种组合。
//
// 示例 2：
//
//
//输入: candidates = [2,3,5], target = 8
//输出: [[2,2,2,2],[2,3,3],[3,5]]
//
// 示例 3：
//
//
//输入: candidates = [2], target = 1
//输出: []
//
//
//
//
// 提示：
//
//
// 1 <= candidates.length <= 30
// 1 <= candidates[i] <= 200
// candidate 中的每个元素都 互不相同
// 1 <= target <= 500
//
//
// 👍 2130 👎 0

//leetcode submit region begin(Prohibit modification and deletion)

func combinationSum(candidates []int, target int) [][]int {
	return dp(candidates, []int{}, 0, target)
}

func dp(candidates, list []int, index, target int) [][]int {
	if target == 0 {
		return [][]int{list}
	} else if target < 0 || index >= len(candidates) {
		return nil
	}

	result := make([][]int, 0)

	// 选择当前数字
	curList := dp(candidates, append(append([]int{}, candidates[index]), list...), index, target-candidates[index])
	if curList != nil {
		result = append(result, curList...)
	}

	// 跳过
	emptyList := dp(candidates, append([]int{}, list...), index+1, target)
	if emptyList != nil {
		result = append(result, emptyList...)
	}

	return result
}

//leetcode submit region end(Prohibit modification and deletion)

func TestCombinationSum(t *testing.T) {
	assert.Equal(t, [][]int{{2, 2, 3}, {7}}, combinationSum([]int{2, 3, 6, 7}, 7))
	assert.Equal(t, [][]int{{2, 2, 2, 2}, {2, 3, 3}, {3, 5}}, combinationSum([]int{2, 3, 5}, 8))
	assert.Equal(t, [][]int{}, combinationSum([]int{2}, 1))
}
