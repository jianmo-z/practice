package leetcode

import (
	"testing"

	"github.com/samber/lo"
	"github.com/stretchr/testify/assert"
)

/*
 * @lc app=leetcode.cn id=72 lang=golang
 *
 * [72] Edit Distance
 *
 * https://leetcode.cn/problems/edit-distance/description/
 *
 * algorithms
 * Medium (63.27%)
 * Likes:    3548
 * Dislikes: 0
 * Total Accepted:    574.4K
 * Total Submissions: 907.9K
 * Testcase Example:  '"horse"\n"ros"'
 *
 * Given two strings word1 and word2, return the minimum number of operations
 * required to convert word1 to word2.
 *
 * You have the following three operations permitted on a word:
 *
 *
 * Insert a character
 * Delete a character
 * Replace a character
 *
 *
 *
 * Example 1:
 *
 *
 * Input: word1 = "horse", word2 = "ros"
 * Output: 3
 * Explanation:
 * horse -> rorse (replace 'h' with 'r')
 * rorse -> rose (remove 'r')
 * rose -> ros (remove 'e')
 *
 *
 * Example 2:
 *
 *
 * Input: word1 = "intention", word2 = "execution"
 * Output: 5
 * Explanation:
 * intention -> inention (remove 't')
 * inention -> enention (replace 'i' with 'e')
 * enention -> exention (replace 'n' with 'x')
 * exention -> exection (replace 'n' with 'c')
 * exection -> execution (insert 'u')
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= word1.length, word2.length <= 500
 * word1 and word2 consist of lowercase English letters.
 *
 *
 */

// @lc code=start
func minDistance(word1 string, word2 string) int {
	if word1 == "" || word2 == "" {
		return lo.Max([]int{len(word1), len(word2)})
	}

	if word1[0] == word2[0] {
		return minDistance(word1[1:], word2[1:])
	}

	return lo.Min(
		[]int{
			minDistance(word1[:], word2[1:]) + 1,
			minDistance(word1[1:], word2[1:]) + 1,
			minDistance(word1[1:], word2[:]) + 1,
		},
	)
}

// @lc code=end

func TestMinDistance(t *testing.T) {
	distance := minDistance("horse", "ros")
	assert.Equal(t, 3, distance)

	distance = minDistance("horse", "horse")
	assert.Equal(t, 0, distance)

	distance = minDistance("intention", "execution")
	assert.Equal(t, 5, distance)
}
