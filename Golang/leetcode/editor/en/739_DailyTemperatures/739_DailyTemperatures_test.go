/*
 * @lc app=leetcode.cn id=739 lang=golang
 *
 * [739] Daily Temperatures
 *
 * https://leetcode.cn/problems/daily-temperatures/description/
 *
 * algorithms
 * Medium (69.19%)
 * Likes:    1861
 * Dislikes: 0
 * Total Accepted:    651.5K
 * Total Submissions: 941.6K
 * Testcase Example:  '[73,74,75,71,69,72,76,73]'
 *
 * Given an array of integers temperatures represents the daily temperatures,
 * return an array answer such that answer[i] is the number of days you have to
 * wait after the i^th day to get a warmer temperature. If there is no future
 * day for which this is possible, keep answer[i] == 0 instead.
 *
 *
 * Example 1:
 * Input: temperatures = [73,74,75,71,69,72,76,73]
 * Output: [1,1,4,2,1,1,0,0]
 * Example 2:
 * Input: temperatures = [30,40,50,60]
 * Output: [1,1,1,0]
 * Example 3:
 * Input: temperatures = [30,60,90]
 * Output: [1,1,0]
 *
 *
 * Constraints:
 *
 *
 * 1 <= temperatures.length <= 10^5
 * 30 <= temperatures[i] <= 100
 *
 *
 */

package leetcode

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

// @lc code=start
func dailyTemperaturesByFor(temperatures []int) []int {

	res := make([]int, len(temperatures))

	for i := 0; i < len(temperatures); i++ {
		for j := i + 1; j < len(temperatures); j++ {
			if temperatures[j] > temperatures[i] {
				res[i] = j - i
				break
			}
		}
	}

	return res
}

// @lc code=start
func dailyTemperatures(temperatures []int) []int {

	//
	maxTemp := make([]int, 0, len(temperatures))
	res := make([]int, len(temperatures))

	for i := 0; i < len(temperatures); i++ {
		if len(maxTemp) == 0 ||
			temperatures[maxTemp[len(maxTemp)-1]] >= temperatures[i] {

			maxTemp = append(maxTemp, i)
			continue
		}

		for len(maxTemp) > 0 &&
			temperatures[maxTemp[len(maxTemp)-1]] < temperatures[i] {

			idx := maxTemp[len(maxTemp)-1]
			maxTemp = maxTemp[:len(maxTemp)-1]

			res[idx] = i - idx
		}

		maxTemp = append(maxTemp, i)
	}

	return res
}

// @lc code=end

func TestDailyTemperatures(t *testing.T) {
	temperatures := []int{73, 74, 75, 71, 69, 72, 76, 73}
	expect := []int{1, 1, 4, 2, 1, 1, 0, 0}
	assert.Equal(t, expect, dailyTemperatures(temperatures))

	temperatures = []int{30, 40, 50, 60}
	expect = []int{1, 1, 1, 0}
	assert.Equal(t, expect, dailyTemperatures(temperatures))
}
