package leetcode

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

/*
 * @lc app=leetcode.cn id=23 lang=golang
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.cn/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (60.62%)
 * Likes:    2897
 * Dislikes: 0
 * Total Accepted:    884.9K
 * Total Submissions: 1.5M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * You are given an array of k linked-lists lists, each linked-list is sorted
 * in ascending order.
 *
 * Merge all the linked-lists into one sorted linked-list and return it.
 *
 *
 * Example 1:
 *
 *
 * Input: lists = [[1,4,5],[1,3,4],[2,6]]
 * Output: [1,1,2,3,4,4,5,6]
 * Explanation: The linked-lists are:
 * [
 * ⁠ 1->4->5,
 * ⁠ 1->3->4,
 * ⁠ 2->6
 * ]
 * merging them into one sorted list:
 * 1->1->2->3->4->4->5->6
 *
 *
 * Example 2:
 *
 *
 * Input: lists = []
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: lists = [[]]
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * k == lists.length
 * 0 <= k <= 10^4
 * 0 <= lists[i].length <= 500
 * -10^4 <= lists[i][j] <= 10^4
 * lists[i] is sorted in ascending order.
 * The sum of lists[i].length will not exceed 10^4.
 *
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeKLists(lists []*ListNode) *ListNode {
	head := &ListNode{}
	tail := head

	for {
		min := -1
		empty := true

		for i := range lists {
			if lists[i] != nil && (min == -1 || lists[min].Val > lists[i].Val) {
				min = i
			}

			if lists[i] != nil {
				empty = false
			}
		}

		if empty {
			break
		}

		tmp := lists[min].Next

		tail.Next = lists[min]
		tail = tail.Next
		tail.Next = nil

		lists[min] = tmp

	}

	return head.Next
}

// @lc code=end

func TestMergeKLists(t *testing.T) {
	lists := []*ListNode{
		MakeLink([]int{1, 4, 5}),
		MakeLink([]int{1, 3, 4}),
		MakeLink([]int{2, 6}),
	}

	res := mergeKLists(lists)

	assert.Equal(t, []int{1, 1, 2, 3, 4, 4, 5, 6}, GetLink(res))

	lists = []*ListNode{
		MakeLink([]int{}),
		MakeLink([]int{}),
		MakeLink([]int{}),
	}

	res = mergeKLists(lists)

	assert.Equal(t, []int{}, GetLink(res))
}
