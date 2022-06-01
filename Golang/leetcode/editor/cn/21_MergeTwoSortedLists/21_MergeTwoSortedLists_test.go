package MergeTwoSortedLists

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
//
//
//
// 示例 1：
//
//
//输入：l1 = [1,2,4], l2 = [1,3,4]
//输出：[1,1,2,3,4,4]
//
//
// 示例 2：
//
//
//输入：l1 = [], l2 = []
//输出：[]
//
//
// 示例 3：
//
//
//输入：l1 = [], l2 = [0]
//输出：[0]
//
//
//
//
// 提示：
//
//
// 两个链表的节点数目范围是 [0, 50]
// -100 <= Node.val <= 100
// l1 和 l2 均按 非递减顺序 排列
//
// Related Topics 递归 链表 👍 2458 👎 0

type ListNode struct {
	Val  int
	Next *ListNode
}

func NewChain(nums []int) *ListNode {
	result := &ListNode{}
	tail := result

	for _, num := range nums {
		tail.Next = &ListNode{Val: num}
		tail = tail.Next
	}
	return result.Next
}

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	result := &ListNode{}
	tail := result
	for list1 != nil || list2 != nil {
		if list1 != nil && list2 != nil {
			if list1.Val <= list2.Val {
				tail.Next = &ListNode{Val: list1.Val}
				list1 = list1.Next
			} else {
				tail.Next = &ListNode{Val: list2.Val}
				list2 = list2.Next
			}
		} else if list1 != nil {
			tail.Next = &ListNode{Val: list1.Val}
			list1 = list1.Next
		} else if list2 != nil {
			tail.Next = &ListNode{Val: list2.Val}
			list2 = list2.Next
		}

		tail = tail.Next
	}

	return result.Next
}

//leetcode submit region end(Prohibit modification and deletion)

func TestMergeTwoSortedLists(t *testing.T) {
	assert.Equal(t, NewChain([]int{1, 1, 2, 3, 4, 4}), mergeTwoLists(NewChain([]int{1, 2, 4}), NewChain([]int{1, 3, 4})))
	assert.Equal(t, NewChain([]int{}), mergeTwoLists(NewChain([]int{}), NewChain([]int{})))
	assert.Equal(t, NewChain([]int{0}), mergeTwoLists(NewChain([]int{}), NewChain([]int{0})))
}
