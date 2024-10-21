package RemoveNthNodeFromEndOfList

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

//给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
//
//
//
// 示例 1：
//
//
//输入：head = [1,2,3,4,5], n = 2
//输出：[1,2,3,5]
//
//
// 示例 2：
//
//
//输入：head = [1], n = 1
//输出：[]
//
//
// 示例 3：
//
//
//输入：head = [1,2], n = 1
//输出：[1]
//
//
//
//
// 提示：
//
//
// 链表中结点的数目为 sz
// 1 <= sz <= 30
// 0 <= Node.val <= 100
// 1 <= n <= sz
//
//
//
//
// 进阶：你能尝试使用一趟扫描实现吗？
// Related Topics 链表 双指针 👍 2077 👎 0

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
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	head = &ListNode{Next: head}
	pre := head
	node := head.Next

	for node != nil {
		n--
		node = node.Next
		if node != nil && n <= 0 {
			pre = pre.Next
		}
	}

	// 删除节点
	pre.Next = pre.Next.Next

	return head.Next
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

func TestRemoveNthNodeFromEndOfList(t *testing.T) {
	assert.Equal(t, NewChain([]int{}), removeNthFromEnd(NewChain([]int{1}), 1))
	assert.Equal(t, NewChain([]int{1, 2, 3, 5}), removeNthFromEnd(NewChain([]int{1, 2, 3, 4, 5}), 2))
	assert.Equal(t, NewChain([]int{1}), removeNthFromEnd(NewChain([]int{1, 2}), 1))
}
