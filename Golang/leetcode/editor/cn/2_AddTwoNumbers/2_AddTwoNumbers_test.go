package AddTwoNumbers

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

//给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
//
// 请你将两个数相加，并以相同形式返回一个表示和的链表。
//
// 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
//
//
//
// 示例 1：
//
//
//输入：l1 = [2,4,3], l2 = [5,6,4]
//输出：[7,0,8]
//解释：342 + 465 = 807.
//
//
// 示例 2：
//
//
//输入：l1 = [0], l2 = [0]
//输出：[0]
//
//
// 示例 3：
//
//
//输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
//输出：[8,9,9,9,0,0,0,1]
//
//
//
//
// 提示：
//
//
// 每个链表中的节点数在范围 [1, 100] 内
// 0 <= Node.val <= 9
// 题目数据保证列表表示的数字不含前导零
//
// Related Topics 递归 链表 数学 👍 8143 👎 0

type ListNode struct {
	Val  int
	Next *ListNode
}

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	carry := 0
	result := &ListNode{}
	tail := result

	for l1 != nil || l2 != nil {
		a, b := 0, 0
		if l1 != nil {
			a = l1.Val
			l1 = l1.Next
		}
		if l2 != nil {
			b = l2.Val
			l2 = l2.Next
		}

		sum := a + b + carry
		tail.Next = &ListNode{Val: sum % 10}
		carry = sum / 10
		tail = tail.Next
	}

	if carry != 0 {
		tail.Next = &ListNode{Val: carry}
	}
	return result.Next
}

//leetcode submit region end(Prohibit modification and deletion)

func NewChain(nums []int) *ListNode {
	result := &ListNode{}
	tail := result

	for _, num := range nums {
		tail.Next = &ListNode{Val: num}
		tail = tail.Next
	}
	return result.Next
}
func TestAddTwoNumbers(t *testing.T) {
	assert.Equal(t, NewChain([]int{7, 0, 8}), addTwoNumbers(NewChain([]int{2, 4, 3}), NewChain([]int{5, 6, 4})))
	assert.Equal(t, NewChain([]int{0}), addTwoNumbers(NewChain([]int{0}), NewChain([]int{0})))
	assert.Equal(t, NewChain([]int{8, 9, 9, 9, 0, 0, 0, 1}), addTwoNumbers(NewChain([]int{9, 9, 9, 9, 9, 9, 9}), NewChain([]int{9, 9, 9, 9})))
}
