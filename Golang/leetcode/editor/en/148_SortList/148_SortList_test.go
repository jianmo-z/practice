package leetcode

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

/*
 * @lc app=leetcode.cn id=148 lang=golang
 *
 * [148] Sort List
 *
 * https://leetcode.cn/problems/sort-list/description/
 *
 * algorithms
 * Medium (66.26%)
 * Likes:    2389
 * Dislikes: 0
 * Total Accepted:    584.5K
 * Total Submissions: 882.2K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Given the head of a linked list, return the list after sorting it in
 * ascending order.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [4,2,1,3]
 * Output: [1,2,3,4]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [-1,5,3,4,0]
 * Output: [-1,0,3,4,5]
 *
 *
 * Example 3:
 *
 *
 * Input: head = []
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the list is in the range [0, 5 * 10^4].
 * -10^5 <= Node.val <= 10^5
 *
 *
 *
 * Follow up: Can you sort the linked list in O(n logn) time and O(1) memory
 * (i.e. constant space)?
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
func sortList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}

	fast := head.Next
	slow := head

	for fast != nil && fast.Next != nil {
		fast = fast.Next.Next
		slow = slow.Next
	}

	mid := slow.Next
	slow.Next = nil

	return mergeTwoLists(sortList(head), sortList(mid))
}

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

func TestSortList(t *testing.T) {
	list := MakeLink([]int{4, 2, 1, 3})
	list = sortList(list)
	assert.Equal(t, []int{1, 2, 3, 4}, GetLink(list))

	list = MakeLink([]int{-1, 5, 3, 4, 0})
	list = sortList(list)
	assert.Equal(t, []int{-1, 0, 3, 4, 5}, GetLink(list))

	list = MakeLink([]int{})
	list = sortList(list)
	assert.Equal(t, []int{}, GetLink(list))
}
