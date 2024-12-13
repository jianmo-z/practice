package interview

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

/*
算二叉树的深度
*/

type Node struct {
	Level int
	Val   int
	Left  *Node
	Right *Node
}

func TreeDeep(root *Node) int {
	if root == nil {
		return 0
	}
	left := TreeDeep(root.Left)
	right := TreeDeep(root.Right)

	deep := left
	if right > left {
		deep = right
	}

	return deep + 1
}

func TreeDeepFor(root *Node) int {
	if root == nil {
		return 0
	}

	nodes := []*Node{root}
	maxLevel := 0

	for len(nodes) != 0 {
		size := len(nodes)
		node := nodes[size-1]
		nodes = nodes[0 : size-1]

		if node == nil {
			continue
		}

		node.Level++

		if node.Level > maxLevel {
			maxLevel = node.Level
		}

		if node.Left != nil {
			node.Left.Level = node.Level
		}

		if node.Right != nil {
			node.Right.Level = node.Level
		}

		nodes = append(nodes, node.Left, node.Right)
	}

	return maxLevel
}

func TestMain2(t *testing.T) {
	root := &Node{
		Left: &Node{
			Left: &Node{
				Left: &Node{
					Val: 1,
				},
			},
		},
		Right: &Node{},
	}

	assert.Equal(t, 4, TreeDeepFor(root))
	assert.Equal(t, 0, TreeDeep(nil))
}
