package LetterCombinationsOfAPhoneNumber

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

//给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
//
// 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
//
//
//
//
//
// 示例 1：
//
//
//输入：digits = "23"
//输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
//
//
// 示例 2：
//
//
//输入：digits = ""
//输出：[]
//
//
// 示例 3：
//
//
//输入：digits = "2"
//输出：["a","b","c"]
//
//
//
//
// 提示：
//
//
// 0 <= digits.length <= 4
// digits[i] 是范围 ['2', '9'] 的一个数字。
//
// Related Topics 哈希表 字符串 回溯 👍 1954 👎 0

//leetcode submit region begin(Prohibit modification and deletion)

var keybord = map[string]string{
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
	if len(digits) == 0 {
		return []string{}
	}

	return deep("", digits)
}

func deep(prefix, digits string) []string {
	if len(digits) == 0 {
		return []string{prefix}
	}

	var result []string
	for _, ele := range keybord[string(digits[0])] {
		result = append(result, deep(prefix+string(ele), digits[1:])...)
	}

	return result
}

//leetcode submit region end(Prohibit modification and deletion)

func TestLetterCombinationsOfAPhoneNumber(t *testing.T) {
	assert.Equal(t, []string{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}, letterCombinations("23"))
	assert.Equal(t, []string{}, letterCombinations(""))
	assert.Equal(t, []string{"a", "b", "c"}, letterCombinations("2"))
}
