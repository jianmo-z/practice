/*
 * @lc app=leetcode.cn id=455 lang=golang
 *
 * [455] Assign Cookies
 *
 * https://leetcode.cn/problems/assign-cookies/description/
 *
 * algorithms
 * Easy (56.09%)
 * Likes:    900
 * Dislikes: 0
 * Total Accepted:    456.3K
 * Total Submissions: 813.6K
 * Testcase Example:  '[1,2,3]\n[1,1]'
 *
 * Assume you are an awesome parent and want to give your children some
 * cookies. But, you should give each child at most one cookie.
 *
 * Each child i has a greed factor g[i], which is the minimum size of a cookie
 * that the child will be content with; and each cookie j has a size s[j]. If
 * s[j] >= g[i], we can assign the cookie j to the child i, and the child i
 * will be content. Your goal is to maximize the number of your content
 * children and output the maximum number.
 *
 *
 * Example 1:
 *
 *
 * Input: g = [1,2,3], s = [1,1]
 * Output: 1
 * Explanation: You have 3 children and 2 cookies. The greed factors of 3
 * children are 1, 2, 3.
 * And even though you have 2 cookies, since their size is both 1, you could
 * only make the child whose greed factor is 1 content.
 * You need to output 1.
 *
 *
 * Example 2:
 *
 *
 * Input: g = [1,2], s = [1,2,3]
 * Output: 2
 * Explanation: You have 2 children and 3 cookies. The greed factors of 2
 * children are 1, 2.
 * You have 3 cookies and their sizes are big enough to gratify all of the
 * children,
 * You need to output 2.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= g.length <= 3 * 10^4
 * 0 <= s.length <= 3 * 10^4
 * 1 <= g[i], s[j] <= 2^31 - 1
 *
 *
 *
 * Note: This question is the same as  2410: Maximum Matching of Players With
 * Trainers.
 *
 */
package leetcode

import (
	"sort"
	"testing"

	"github.com/stretchr/testify/assert"
)

// @lc code=start
func findContentChildren(g []int, s []int) int {
	sort.Slice(g, func(i, j int) bool { return g[i] < g[j] })
	sort.Slice(s, func(i, j int) bool { return s[i] < s[j] })

	i := len(g) - 1
	j := len(s) - 1

	cnt := 0

	for i >= 0 && j >= 0 {
		if s[j] >= g[i] {
			i--
			j--
			cnt++
		} else if s[j] < g[i] {
			i--
		}
	}

	return cnt
}

// @lc code=end

func TestGindContentChildren(t *testing.T) {
	res := findContentChildren([]int{1, 2, 3}, []int{1, 1})
	assert.Equal(t, 1, res)

	res = findContentChildren([]int{1, 2, 3}, []int{1, 2})
	assert.Equal(t, 2, res)
}
