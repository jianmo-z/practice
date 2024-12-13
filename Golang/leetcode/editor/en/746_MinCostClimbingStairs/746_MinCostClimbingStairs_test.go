package leetcode

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

/*
 * @lc app=leetcode.cn id=746 lang=golang
 *
 * [746] Min Cost Climbing Stairs
 *
 * https://leetcode.cn/problems/min-cost-climbing-stairs/description/
 *
 * algorithms
 * Easy (67.48%)
 * Likes:    1572
 * Dislikes: 0
 * Total Accepted:    507K
 * Total Submissions: 751.3K
 * Testcase Example:  '[10,15,20]'
 *
 * You are given an integer array cost where cost[i] is the cost of i^th step
 * on a staircase. Once you pay the cost, you can either climb one or two
 * steps.
 *
 * You can either start from the step with index 0, or the step with index 1.
 *
 * Return the minimum cost to reach the top of the floor.
 *
 *
 * Example 1:
 *
 *
 * Input: cost = [10,15,20]
 * Output: 15
 * Explanation: You will start at index 1.
 * - Pay 15 and climb two steps to reach the top.
 * The total cost is 15.
 *
 *
 * Example 2:
 *
 *
 * Input: cost = [1,100,1,1,1,100,1,1,100,1]
 * Output: 6
 * Explanation: You will start at index 0.
 * - Pay 1 and climb two steps to reach index 2.
 * - Pay 1 and climb two steps to reach index 4.
 * - Pay 1 and climb two steps to reach index 6.
 * - Pay 1 and climb one step to reach index 7.
 * - Pay 1 and climb two steps to reach index 9.
 * - Pay 1 and climb one step to reach the top.
 * The total cost is 6.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= cost.length <= 1000
 * 0 <= cost[i] <= 999
 *
 *
 */

// @lc code=start
func minCostClimbingStairs(cost []int) int {
	m := make([]int, len(cost)+1)

	res := dp(cost, m, len(cost))
	return res
}

func dp(cost []int, m []int, idx int) int {
	if idx <= 1 {
		return 0
	}
	if m[idx] > 0 {
		return m[idx]
	}

	a := dp(cost, m, idx-1) + cost[idx-1]
	b := dp(cost, m, idx-2) + cost[idx-2]

	m[idx] = a
	if a > b {
		m[idx] = b
	}

	return m[idx]

}

// @lc code=end

func TestMinCostClimbingStairs(t *testing.T) {
	exp := minCostClimbingStairs([]int{10, 15, 20})
	assert.Equal(t, exp, 15)
}
