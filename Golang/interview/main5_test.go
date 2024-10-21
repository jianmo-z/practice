package interview

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

/*
输入一个以字符串表示的非负整数 sNum，从这个串中移除 k 位数字，使得剩下的数字最小。
例如：
	输入: num = "123421", k = 2； 输出: "1221"
	输入: num = "10300", k = 1； 输出: "300"
	输入: num = "1432219", k = 3，输出: "1219"
*/

var minNum string

func isLess(num, min string) bool {
	if len(min) == 0 {
		return true
	} else if len(num) > len(min) || len(num) == 0 {
		return false
	}

	return num < min
}

func ReduceNum(num string) string {
	index := 0
	for i := range num {
		if num[i] == '0' {
			index++
		} else {
			break
		}
	}

	if index == len(num) {
		return "0"
	}

	return num[index:]
}

func RemoveNum(num string, k int) string {
	minNum = ""
	removeNum(num, k, len(num)-k, len(num))
	return ReduceNum(minNum)
}

func removeNum(num string, k, aim, deep int) string {
	if k <= 0 {
		if len(num) == aim {
			return num
		}
		return ""
	} else if len(num) < aim || deep < 0 {
		return ""
	}

	for i := range num {
		// 移除当前位字符
		subNum := num[0:i]
		if i+1 < len(num) {
			subNum += num[i+1:]
		}
		numA := removeNum(subNum, k-1, aim, deep-1)
		if isLess(numA, minNum) {
			minNum = numA
		}

		// 不移除当前位字符
		numB := removeNum(num, k, aim, deep-1)
		if isLess(numB, minNum) {
			minNum = numB
		}
	}

	return ""
}

func TestMain5(t *testing.T) {
	assert.Equal(t, RemoveNum("123421", 2), "1221")
	assert.Equal(t, RemoveNum("10300", 1), "300")
	assert.Equal(t, RemoveNum("1432219", 3), "1219")
	assert.Equal(t, RemoveNum("1000", 1), "0")
	assert.Equal(t, RemoveNum("100301", 3), "0")

	// 123421 -> 432221 -> k -> 2221
	// 100301 -> 311000 -> k(2) -> 1000
	// 111223 == k
}

/*
0 -> a
1 -> b

00 a*a
01 a*b -> 0
10 b*a -> 1
11 b*b

*/
