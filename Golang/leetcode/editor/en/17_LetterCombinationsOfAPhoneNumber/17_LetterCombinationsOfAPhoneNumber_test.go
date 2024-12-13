package leetcode

import (
	"fmt"
	"testing"
)

/*
 * @lc app=leetcode.cn id=17 lang=golang
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (60.86%)
 * Likes:    2963
 * Dislikes: 0
 * Total Accepted:    992.3K
 * Total Submissions: 1.6M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent. Return the answer in
 * any order.
 *
 * A mapping of digits to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 *
 *
 * Example 1:
 *
 *
 * Input: digits = "23"
 * Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
 *
 *
 * Example 2:
 *
 *
 * Input: digits = ""
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: digits = "2"
 * Output: ["a","b","c"]
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= digits.length <= 4
 * digits[i] is a digit in the range ['2', '9'].
 *
 *
 */

// @lc code=start

var letterMap = map[string]string{
	"2": "abc",
	"3": "def",
	"4": "ghi",
	"5": "jkl",
	"6": "mno",
	"7": "pqrs",
	"8": "tuv",
	"9": "wxyz",
}

func letterCombinations(digits string) []string {
	return allLetter("", digits)
}

func allLetter(prefix, digits string) []string {
	result := []string{}
	if digits == "" {
		if prefix == "" {
			return nil
		}
		return []string{prefix}
	}

	letter := letterMap[digits[0:1]]
	for i := 0; i < len(letter); i++ {
		res := allLetter(prefix+string(letter[i]), digits[1:])

		result = append(result, res...)
	}

	return result
}

// @lc code=end

func TestLetterCombinations(t *testing.T) {
	res := letterCombinations("23")
	fmt.Println(res)
}
