/*
 * @lc app=leetcode.cn id=77 lang=golang
 *
 * [77] Combinations
 *
 * https://leetcode.cn/problems/combinations/description/
 *
 * algorithms
 * Medium (77.44%)
 * Likes:    1711
 * Dislikes: 0
 * Total Accepted:    812.6K
 * Total Submissions: 1M
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * chosen from the range [1, n].
 *
 * You may return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 4, k = 2
 * Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
 * Explanation: There are 4 choose 2 = 6 total combinations.
 * Note that combinations are unordered, i.e., [1,2] and [2,1] are considered
 * to be the same combination.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1, k = 1
 * Output: [[1]]
 * Explanation: There is 1 choose 1 = 1 total combination.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 20
 * 1 <= k <= n
 *
 *
 */

package leetcode

import (
	"fmt"
	"testing"
)

// @lc code=start
func combine(n int, k int) [][]int {
	nums := make([]int, 0, n)
	for i := range n {
		nums = append(nums, i+1)
	}

	return backTracing(nums, nil, 0, k)
}

func backTracing(nums, cur []int, idx, need int) [][]int {
	if need == 0 {
		res := make([]int, len(cur))
		copy(res, cur)

		return [][]int{cur}
	}

	res := make([][]int, 0)

	for i := idx; i < len(nums); i++ {
		data := backTracing(nums, append(cur, nums[i]), i+1, need-1)
		res = append(res, data...)
	}

	return res
}

// @lc code=end

func TestCombine(t *testing.T) {
	res := combine(5, 4)
	fmt.Println(res)
}
