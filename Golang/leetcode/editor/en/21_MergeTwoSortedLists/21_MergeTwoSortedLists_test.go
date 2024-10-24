package leetcode

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

/*
 * @lc app=leetcode.cn id=21 lang=golang
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.cn/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (67.14%)
 * Likes:    3613
 * Dislikes: 0
 * Total Accepted:    1.9M
 * Total Submissions: 2.8M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * You are given the heads of two sorted linked lists list1 and list2.
 *
 * Merge the two lists into one sorted list. The list should be made by
 * splicing together the nodes of the first two lists.
 *
 * Return the head of the merged linked list.
 *
 *
 * Example 1:
 *
 *
 * Input: list1 = [1,2,4], list2 = [1,3,4]
 * Output: [1,1,2,3,4,4]
 *
 *
 * Example 2:
 *
 *
 * Input: list1 = [], list2 = []
 * Output: []
 *
 *
 * Example 3:
 *
 *
 * Input: list1 = [], list2 = [0]
 * Output: [0]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in both lists is in the range [0, 50].
 * -100 <= Node.val <= 100
 * Both list1 and list2 are sorted in non-decreasing order.
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
func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {

	head := &ListNode{}
	tail := head

	for list1 != nil || list2 != nil {

		var node *ListNode

		if list1 != nil && list2 != nil {
			if list1.Val < list2.Val {
				node = list1
				list1 = list1.Next
			} else {
				node = list2
				list2 = list2.Next
			}
		} else if list1 == nil {
			node = list2
			list2 = list2.Next
		} else if list2 == nil {
			node = list1
			list1 = list1.Next
		}

		node.Next = nil
		tail.Next = node

		tail = tail.Next
	}

	return head.Next
}

// @lc code=end

func TestMergeTwoLists(t *testing.T) {
	list1 := MakeLink([]int{1, 2, 4})
	list2 := MakeLink([]int{1, 3, 4})

	list := mergeTwoLists(list1, list2)

	assert.Equal(t, []int{1, 1, 2, 3, 4, 4}, GetLink(list))

	list1 = MakeLink([]int{})
	list2 = MakeLink([]int{})

	list = mergeTwoLists(list1, list2)

	assert.Equal(t, []int{}, GetLink(list))

	list1 = MakeLink([]int{})
	list2 = MakeLink([]int{0})

	list = mergeTwoLists(list1, list2)

	assert.Equal(t, []int{0}, GetLink(list))
}
