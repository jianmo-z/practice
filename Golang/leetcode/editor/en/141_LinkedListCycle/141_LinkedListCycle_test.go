package leetcode

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

/*
 * @lc app=leetcode.cn id=141 lang=golang
 *
 * [141] Linked List Cycle
 *
 * https://leetcode.cn/problems/linked-list-cycle/description/
 *
 * algorithms
 * Easy (52.87%)
 * Likes:    2210
 * Dislikes: 0
 * Total Accepted:    1.4M
 * Total Submissions: 2.6M
 * Testcase Example:  '[3,2,0,-4]\n1'
 *
 * Given head, the head of a linked list, determine if the linked list has a
 * cycle in it.
 *
 * There is a cycle in a linked list if there is some node in the list that can
 * be reached again by continuously following the next pointer. Internally, pos
 * is used to denote the index of the node that tail's next pointer is
 * connected to. Note that pos is not passed as a parameter.
 *
 * Return true if there is a cycle in the linked list. Otherwise, return
 * false.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [3,2,0,-4], pos = 1
 * Output: true
 * Explanation: There is a cycle in the linked list, where the tail connects to
 * the 1st node (0-indexed).
 *
 *
 * Example 2:
 *
 *
 * Input: head = [1,2], pos = 0
 * Output: true
 * Explanation: There is a cycle in the linked list, where the tail connects to
 * the 0th node.
 *
 *
 * Example 3:
 *
 *
 * Input: head = [1], pos = -1
 * Output: false
 * Explanation: There is no cycle in the linked list.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of the nodes in the list is in the range [0, 10^4].
 * -10^5 <= Node.val <= 10^5
 * pos is -1 or a valid index in the linked-list.
 *
 *
 *
 * Follow up: Can you solve it using O(1) (i.e. constant) memory?
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

func NextN(head *ListNode, n int) *ListNode {
	for i := 0; i < n; i++ {
		if head == nil {
			return nil
		}
		head = head.Next
	}
	return head
}

func hasCycle(head *ListNode) bool {
	fast := head
	slow := head

	for fast != nil && slow != nil {
		fast = NextN(fast, 2)
		if fast == nil {
			return false
		}

		slow = NextN(slow, 1)

		if fast == slow {
			return true
		}
	}

	return false
}

// @lc code=end

func TestHasCycle(t *testing.T) {
	head := MakeLink([]int{1, 2, 3, 4, 5})
	assert.False(t, hasCycle(head))
}
