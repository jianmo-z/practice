package SymmetricTree

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

//给你一个二叉树的根节点 root ， 检查它是否轴对称。
//
//
//
// 示例 1：
//
//
//输入：root = [1,2,2,3,4,4,3]
//输出：true
//
//
// 示例 2：
//
//
//输入：root = [1,2,2,null,3,null,3]
//输出：false
//
//
//
//
// 提示：
//
//
// 树中节点数目在范围 [1, 1000] 内
// -100 <= Node.val <= 100
//
//
//
//
// 进阶：你可以运用递归和迭代两种方法解决这个问题吗？
// Related Topics 树 深度优先搜索 广度优先搜索 二叉树 👍 1943 👎 0

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func NewTree(data []int) *TreeNode {
	if len(data) == 0 {
		return nil
	}
	root := &TreeNode{Val: data[0]}
	queue := []*TreeNode{root}

	index := 0
	for len(queue) != 0 && index < len(data)-1 {
		if data[index+1] != -1 && index < len(data) {
			left := &TreeNode{Val: data[index+1]}
			queue[0].Left = left
			queue = append(queue, left)
		}
		if data[index+2] != -1 && index < len(data) {
			right := &TreeNode{Val: data[index+2]}
			queue[0].Right = right
			queue = append(queue, right)
		}
		index += 2
		queue = queue[1:]
	}

	return root
}

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isSymmetric(root *TreeNode) bool {
	if root == nil {
		return true
	}
	return mirror(root.Left, root.Right)
}

func mirror(left, right *TreeNode) bool {
	if left == nil && right == nil {
		return true
	} else if left == nil || right == nil {
		return false
	}

	if left.Val != right.Val {
		return false
	}

	return mirror(left.Right, right.Left) && mirror(left.Left, right.Right)
}

//leetcode submit region end(Prohibit modification and deletion)

func TestSymmetricTree(t *testing.T) {
	assert.True(t, isSymmetric(nil))
	assert.True(t, isSymmetric(NewTree([]int{1, 2, 2, 3, 4, 4, 3})))
	assert.False(t, isSymmetric(NewTree([]int{1, 2, 2, -1, 3, -1, 3})))
}
