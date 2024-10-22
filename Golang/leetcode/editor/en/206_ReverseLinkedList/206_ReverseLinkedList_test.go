package leetcode

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

/*
 * @lc app=leetcode.cn id=206 lang=golang
 *
 * [206] Reverse Linked List
 *
 * https://leetcode.cn/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (75.10%)
 * Likes:    3702
 * Dislikes: 0
 * Total Accepted:    2.1M
 * Total Submissions: 2.8M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given the head of a singly linked list, reverse the list, and return the
 * reversed list.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [1,2,3,4,5]
 * Output: [5,4,3,2,1]
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,2]
 * Output: [2,1]
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
 * The number of nodes in the list is the range [0, 5000].
 * -5000 <= Node.val <= 5000
 *
 *
 *
 * Follow up: A linked list can be reversed either iteratively or recursively.
 * Could you implement both?
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
func reverseList(head *ListNode) *ListNode {
	var rHead *ListNode
	if head == nil {
		return nil
	}

	for head != nil {
		tmp := head.Next

		head.Next = rHead
		rHead = head
		head = tmp
	}

	return rHead
}

// @lc code=end

func TestReverseList(t *testing.T) {
	head := MakeLink([]int{1, 2, 3, 4, 5})
	head = reverseList(head)
	assert.Equal(t, []int{5, 4, 3, 2, 1}, GetLink(head))

	head = MakeLink([]int{1, 2})
	head = reverseList(head)
	assert.Equal(t, []int{2, 1}, GetLink(head))

	head = MakeLink([]int{})
	head = reverseList(head)
	assert.Equal(t, []int{}, GetLink(head))
}
