package interview

import (
	"sort"
	"testing"
)

func merge(intervals [][]int) [][]int {
	if len(intervals) <= 1 {
		return intervals
	}
	sort.Slice(intervals, func(i, j int) bool { return intervals[i][0] < intervals[j][0] })

	result := [][]int{}
	nums1 := intervals[0]

	for i := 1; i < len(intervals); i++ {
		nums2 := intervals[i]
		nums, ok := mergeNums(nums1, nums2)
		if !ok {
			result = append(result, nums1)
			nums1 = nums2
		} else {
			nums1 = nums
		}
	}
	result = append(result, nums1)

	return result
}

func mergeNums(nums1, nums2 []int) ([]int, bool) {

	if nums1[0] > nums2[0] {
		nums1, nums2 = nums2, nums1
	}

	if nums1[1] < nums2[0] {
		return nums2, false
	}

	return []int{min(nums1[0], nums2[0]), max(nums1[1], nums2[1])}, true
}

func TestMain(t *testing.T) {
	merge([][]int{{2, 3}, {4, 5}, {6, 7}, {8, 9}, {1, 10}})
}
