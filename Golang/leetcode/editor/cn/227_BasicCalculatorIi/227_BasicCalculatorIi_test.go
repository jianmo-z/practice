package BasicCalculatorIi

import (
	"github.com/stretchr/testify/assert"
	"strconv"
	"strings"
	"testing"
)

//给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。
//
// 整数除法仅保留整数部分。
//
// 你可以假设给定的表达式总是有效的。所有中间结果将在 [-2³¹, 2³¹ - 1] 的范围内。
//
// 注意：不允许使用任何将字符串作为数学表达式计算的内置函数，比如 eval() 。
//
//
//
// 示例 1：
//
//
//输入：s = "3+2*2"
//输出：7
//
//
// 示例 2：
//
//
//输入：s = " 3/2 "
//输出：1
//
//
// 示例 3：
//
//
//输入：s = " 3+5 / 2 "
//输出：5
//
//
//
//
// 提示：
//
//
// 1 <= s.length <= 3 * 10⁵
// s 由整数和算符 ('+', '-', '*', '/') 组成，中间由一些空格隔开
// s 表示一个 有效表达式
// 表达式中的所有整数都是非负整数，且在范围 [0, 2³¹ - 1] 内
// 题目数据保证答案是一个 32-bit 整数
//
// Related Topics 栈 数学 字符串 👍 550 👎 0

//leetcode submit region begin(Prohibit modification and deletion)
// 逆波兰表达式
func calculate(s string) int {
	nums := []int{}
	ops := []string{}

	str := s
	result := ""
	for {
		result, str = nextChar(str)
		if result == "" {
			break
		}

		switch result {
		case "*", "/":
			for len(nums) >= 2 && len(ops) > 0 {
				if ops[len(ops)-1] == "*" || ops[len(ops)-1] == "/" {
					nums, ops = doOnceCalc(nums, ops)
				} else {
					break
				}
			}

			ops = append(ops, result)
		case "+", "-":
			for len(nums) >= 2 && len(ops) > 0 {
				nums, ops = doOnceCalc(nums, ops)
			}

			ops = append(ops, result)
		default:
			num, err := strconv.Atoi(result)
			if err != nil {
				panic(err)
			}
			nums = append(nums, num)
		}
	}

	for len(ops) > 0 {
		nums, ops = doOnceCalc(nums, ops)
	}
	return nums[0]
}

func doOnceCalc(nums []int, ops []string) ([]int, []string) {
	numsLen := len(nums)
	opLen := len(ops)

	nums[numsLen-2] = op(nums[numsLen-2], nums[numsLen-1], ops[opLen-1])

	return nums[:numsLen-1], ops[:opLen-1]
}

func op(a, b int, op string) int {
	switch op {
	case "+":
		return a + b
	case "-":
		return a - b
	case "*":
		return a * b
	case "/":
		return a / b
	}

	panic("op")
}

func nextChar(str string) (string, string) {
	str = strings.TrimSpace(str)
	if len(str) == 0 {
		return "", ""
	}

	result := ""
	index := 0

outer:
	for ; index < len(str); index++ {
		switch str[index] {
		case '+', '-', '*', '/':
			break outer
		case ' ':
			if len(result) != 0 {
				break outer
			}
		default:
			result += str[index : index+1]
		}
	}

	if len(result) == 0 {
		result += str[index : index+1]
		index += 1
	}

	return result, str[index:]
}

//leetcode submit region end(Prohibit modification and deletion)

func TestNextChar(t *testing.T) {
	result, str := nextChar("30 +2*2")
	assert.Equal(t, "30", result)
	assert.Equal(t, " +2*2", str)

	result, str = nextChar(str)
	assert.Equal(t, "+", result)
	assert.Equal(t, "2*2", str)

	result, str = nextChar(str)
	assert.Equal(t, "2", result)
	assert.Equal(t, "*2", str)

	result, str = nextChar(str)
	assert.Equal(t, "*", result)
	assert.Equal(t, "2", str)

	result, str = nextChar(str)
	assert.Equal(t, "2", result)
	assert.Equal(t, "", str)
}

func TestBasicCalculatorIi(t *testing.T) {
	assert.Equal(t, 7, calculate("3+2*2"))
	assert.Equal(t, 1, calculate(" 3/2 "))
	assert.Equal(t, 5, calculate(" 3+5 / 2 "))
	assert.Equal(t, 9, calculate("3+2*2+2"))
	assert.Equal(t, 1, calculate("1-1+1"))
	assert.Equal(t, 2, calculate("2/2*2"))
}
