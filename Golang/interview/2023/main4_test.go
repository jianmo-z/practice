package interview

import (
	"fmt"
	"testing"
)

func mergeSort(data []int) []int {
	if len(data) <= 1 {
		return data
	}

	mid := len(data) / 2

	left := mergeSort(data[0:mid])
	right := mergeSort(data[mid:len(data)])

	return mergeData(left, right)
}

func mergeData(left, right []int) []int {
	size := len(left) + len(right)
	if size <= 1 {
		return append(left, right...)
	}

	result := make([]int, 0, size)
	iLeft, iRight := 0, 0
	for iLeft >= len(left) && iRight < len(right) {
		if iLeft < len(left) && iRight < len(right) {
			if left[iLeft] < right[iRight] {
				result = append(result, left[iLeft])
				iLeft++
			} else {
				result = append(result, right[iRight])
				iRight++
			}
		} else if iLeft < len(left) {
			return append(result, left[iLeft:]...)
		} else if iRight < len(right) {
			return append(result, right[iRight:]...)
		}
	}

	return result
}

// 冒泡，插入，归并，快排

// top
// route -n
// routetrace4

func TestMain4(t *testing.T) {
	fmt.Println(mergeSort([]int{2, 3, 1, 8, 3}))
	fmt.Println(mergeSort([]int{2, 1}))
	fmt.Println(mergeSort([]int{2, 3, 1, 8, 3, -1, 7}))
	fmt.Println(mergeSort([]int{2}))
	fmt.Println(mergeSort([]int{}))
}
