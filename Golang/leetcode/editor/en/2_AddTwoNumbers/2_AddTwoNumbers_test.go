package leetcode

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

/*
 * @lc app=leetcode.cn id=2 lang=golang
 *
 * [2] Add Two Numbers
 *
 * https://leetcode.cn/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (44.49%)
 * Likes:    10863
 * Dislikes: 0
 * Total Accepted:    2.2M
 * Total Submissions: 5M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order, and each of their nodes
 * contains a single digit. Add the two numbers and return the sum as a linked
 * list.
 *
 * You may assume the two numbers do not contain any leading zero, except the
 * number 0 itself.
 *
 *
 * Example 1:
 *
 *
 * Input: l1 = [2,4,3], l2 = [5,6,4]
 * Output: [7,0,8]
 * Explanation: 342 + 465 = 807.
 *
 *
 * Example 2:
 *
 *
 * Input: l1 = [0], l2 = [0]
 * Output: [0]
 *
 *
 * Example 3:
 *
 *
 * Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * Output: [8,9,9,9,0,0,0,1]
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in each linked list is in the range [1, 100].
 * 0 <= Node.val <= 9
 * It is guaranteed that the list represents a number that does not have
 * leading zeros.
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
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	res := &ListNode{}
	tail := res
	carry := 0

	for l1 != nil || l2 != nil || carry > 0 {
		left, right := 0, 0
		if l1 != nil {
			left = l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			right = l2.Val
			l2 = l2.Next
		}

		sum := left + right + carry

		tail.Next = &ListNode{Val: sum % 10}
		carry = sum / 10
		tail = tail.Next
	}

	return res.Next
}

// @lc code=end

func TestAddTwoNumbers(t *testing.T) {
	l1 := MakeLink([]int{2, 4, 3})
	l2 := MakeLink([]int{5, 6, 4})
	res := addTwoNumbers(l1, l2)
	assert.Equal(t, []int{7, 0, 8}, GetLink(res))

	l1 = MakeLink([]int{0})
	l2 = MakeLink([]int{0})
	res = addTwoNumbers(l1, l2)

	assert.Equal(t, []int{0}, GetLink(res))

	l1 = MakeLink([]int{9, 9, 9, 9, 9, 9, 9})
	l2 = MakeLink([]int{9, 9, 9, 9})
	res = addTwoNumbers(l1, l2)
	assert.Equal(t, []int{8, 9, 9, 9, 0, 0, 0, 1}, GetLink(res))
}
