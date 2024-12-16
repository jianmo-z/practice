package leetcode

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

/*
 * @lc app=leetcode.cn id=647 lang=golang
 *
 * [647] Palindromic Substrings
 *
 * https://leetcode.cn/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (67.68%)
 * Likes:    1391
 * Dislikes: 0
 * Total Accepted:    367.5K
 * Total Submissions: 543K
 * Testcase Example:  '"abc"'
 *
 * Given a string s, return the number of palindromic substrings in it.
 *
 * A string is a palindrome when it reads the same backward as forward.
 *
 * A substring is a contiguous sequence of characters within the string.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 *
 *
 * Example 2:
 *
 *
 * Input: s = "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 1000
 * s consists of lowercase English letters.
 *
 *
 */

// @lc code=start
func countSubstrings(s string) int {

	count := 0

	for i := 0; i < len(s); i++ {
		begin := i
		end := i
		count += countSub(s, begin, end) +
			countSub(s, begin, end+1)
	}

	return count
}

func countSub(s string, begin, end int) int {

	count := 0
	size := len(s)

	for begin >= 0 && end < size {
		if s[begin] == s[end] {
			count++
		} else {
			break
		}

		begin--
		end++
	}

	return count
}

// @lc code=end

func TestCountSubstrings(t *testing.T) {
	assert.Equal(t, 0, countSubstrings(""))
	assert.Equal(t, 3, countSubstrings("abc"))
	assert.Equal(t, 6, countSubstrings("aaa"))
	assert.Equal(t, 6, countSubstrings("fdsklf"))
}
