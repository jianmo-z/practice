package interview

import (
	"fmt"
	"testing"
	"time"
)

/*
(改成一个数组的全排列了)
给你一个整数数组 nums ，找出 nums 的下一个排列
示例 1：
	输入：nums = [1,2,3]
	输出：[1,3,2]
示例 2：
	输入：nums = [3,2,1]
	输出：[1,2,3]
示例 3：
	输入：nums = [1,1,5]
	输出：[1,5,1]

1,2,3

1
	2  -> 3
	3  -> 2

2
	1  -> 3
	3  -> 1

3
	2 -> 1
	1 -> 2
*/

var result [][]int

func dp(nums []int, data []int) {
	if len(nums) == 1 {
		result = append(result, append(data, nums[0]))
		return
	}

	for i, num := range nums {
		tmpNums := []int{}
		if i >= 0 {
			tmpNums = append(tmpNums, nums[0:i]...)
		}
		if i < len(nums) {
			tmpNums = append(tmpNums, nums[i+1:]...)
		}

		dp(tmpNums, append(data, num))
	}
}

func TestPractice(t *testing.T) {

	var mem [][]byte

	sum := uint64(0)

	for i := 0; i < 8*1024; i++ {
		memCnt := uint64(1024 * 1024)
		data := make([]byte, 0, memCnt) // 1MB
		sum += memCnt
		fmt.Println("alloc:", sum/1024/1024)
		mem = append(mem, data)
	}

	time.Sleep(time.Hour * 1)

	return

	nums := []int{}
	dp(nums, nil)
	fmt.Println(len(result))
	fmt.Println(result)
}

// dlv -> remote debug
// pprof
