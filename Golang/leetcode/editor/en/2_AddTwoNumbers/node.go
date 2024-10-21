package leetcode

type ListNode struct {
	Val  int
	Next *ListNode
}

// MakeLink
func MakeLink(nodes []int) *ListNode {
	head := &ListNode{}
	tail := head

	for i := range nodes {
		tail.Next = &ListNode{
			Val: nodes[i],
		}
		tail = tail.Next
	}

	return head.Next
}

func GetLink(link *ListNode) []int {
	nodes := []int{}

	for link != nil {
		nodes = append(nodes, link.Val)
		link = link.Next
	}

	return nodes
}
