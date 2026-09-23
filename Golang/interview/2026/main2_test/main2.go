package interview

import (
	"sort"

	"github.com/samber/lo"
)

// MaxNumberLessThanN 算法题目：小于 n 的最大数。
//
// 给定一个数 n，如 23121；给定一组数字 digits，如 []int{2, 4, 9}；
// 求由 digits 中元素组成的、小于 n 的最大数。
// 例如：小于 23121 的最大数为 22999。
//
// 约定：
// - digits 可无序，可能包含 0。
// - 返回值不能有前导 0。
// - 如果不存在小于 n 的合法非负整数，返回 -1。
func MaxNumberLessThanN(n int, digits []int) int {
	nums := SplitNum(n)
	digits = lo.Uniq(digits)
	sort.Slice(digits, func(i int, j int) bool {
		return digits[i] < digits[j]
	})

	if len(digits) == 0 || n <= 0 {
		return -1
	}
	if len(nums) == 1 {
		return findLastMax(nums[0]-1, digits)
	}

	result := make([]int, len(nums))

	onlyMax := false

	i := 0
outer:
	for ; i < len(nums); i++ {
		num := nums[i]
		var nextNum int
		if onlyMax {
			nextNum = Max(digits)
		} else {
			nextNum = findLastMax(num, digits)
			// 没找到更小的值
			if nextNum == -1 || (i == 0 && nextNum == 0) {
				// 回退找更小的
				for j := i - 1; i > 0 && j >= 0; j-- {
					curNum := result[j]
					nextNum = findLastMax(curNum-1, digits)
					if nextNum != -1 {
						i = j
						result[j] = nextNum
						onlyMax = true
						continue outer
					}
				}
				// 这里都没有找到说明没有符合预期的值，可能需要降位
				i = 0
				break outer
			}
			if nextNum < num {
				onlyMax = true
			}
		}
		result[i] = nextNum
	}

	// 说明没找到更小的值，说明是等值的：个位数还是降
	if !onlyMax {
		// 个位数开始再找
		j := len(nums) - 1
		for ; j >= 0 && i != 0; j-- {
			num := nums[j]
			nextNum := findLastMax(num-1, digits)
			if nextNum != -1 {
				result[j] = nextNum
				onlyMax = true
				break
			}
		}

		j = j + 1
		// 降低一位找max
		if !onlyMax {
			result = result[1:]
			j = 0
		}

		for ; j < len(result); j++ {
			result[j] = Max(digits)
		}
	}

	if len(result) == 0 {
		return -1
	}

	maxNum := 0
	for i := range result {
		maxNum = maxNum*10 + result[i]
	}

	return maxNum
}

func Max(digits []int) int {
	if len(digits) == 0 {
		return -1
	}
	return digits[len(digits)-1]
}

func findLastMax(n int, digits []int) int {
	if len(digits) == 0 {
		return -1
	} else if len(digits) == 1 && digits[0] <= n {
		return digits[0]
	}

	for i := range digits {
		if digits[i] > n {
			if i > 0 && digits[i-1] <= n {
				return digits[i-1]
			}
		}
	}

	if digits[len(digits)-1] <= n {
		return digits[len(digits)-1]
	}

	return -1
}

func SplitNum(n int) []int {
	if n < 10 {
		return []int{n}
	}

	result := []int{}
	for n > 0 {
		num := n % 10
		n /= 10

		result = append([]int{num}, result...)
	}

	return result
}
