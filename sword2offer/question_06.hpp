/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: question_06.hpp
 * 时间: 4/27/2020-9:59 PM
 * 作者: Pip
 */

#include <bits/stdc++.h>
#include "gtest/gtest.h"

using namespace std;

/**
 * 问题链接：
 *      根据某二叉树的先序和中序遍历结果，重建二叉树
 *      先序遍历结果(root-left-right)：{1, 2, 4, 7, 3, 5, 6, 8}
 *      中序遍历结果(left-root-right)：{4, 7, 2, 1, 5, 3, 8, 6}
 * 解题思路：
 */
struct binaryTreeNode {
    binaryTreeNode() : data(0), left(nullptr), right(nullptr) {}

    binaryTreeNode(int data, binaryTreeNode *left, binaryTreeNode *right) : data(data), left(left), right(right) {}

    int data;
    binaryTreeNode *left;
    binaryTreeNode *right;
};

class Solution {

public:
    /**
     * 先序遍历结果(root-left-right)：{1, 2, 4, 7, 3, 5, 6, 8}
     * 中序遍历结果(left-root-right)：{4, 7, 2, 1, 5, 3, 8, 6}
     * @param preOrder
     * @param midOrder
     * @return
     */
    static vector<int> constructBinaryTree(vector<int> preOrder, vector<int> midOrder) {
        vector<int> ret;
        binaryTreeNode *root = Solution::rebuildBinaryTree(preOrder, midOrder);
        preTravel(root, ret);
        return ret;
    }

private:
    static binaryTreeNode *rebuildBinaryTree(const vector<int> &preOrder, const vector<int> &midOrder) {
        return preOrder.empty() ? nullptr : _rebuildBinaryTree(preOrder, midOrder);
    }

    static void preTravel(binaryTreeNode *root, vector<int> &order) {
        if (nullptr == root) {
            return;
        }
        order.push_back(root->data);
        preTravel(root->left, order);
        preTravel(root->right, order);
    }

    static binaryTreeNode *_rebuildBinaryTree(vector<int> preOrder, vector<int> midOrder) {
        if (preOrder.empty() || midOrder.empty())
            return nullptr;
        binaryTreeNode *node = new binaryTreeNode();
        node->data = preOrder[0];
        auto rootIndex = std::find(midOrder.begin(), midOrder.end(), preOrder[0]);
        auto preOrderEnd = std::next(preOrder.begin(), std::distance(midOrder.begin(), rootIndex) + 1);
        // 构建左子树
        node->left = _rebuildBinaryTree(vector<int>(preOrder.begin() + 1, preOrderEnd),
                                        vector<int>(midOrder.begin(), rootIndex));
        // 构建右子树
        node->right = _rebuildBinaryTree(vector<int>(preOrderEnd, preOrder.end()),
                                         vector<int>(rootIndex + 1, midOrder.end()));
        return node;
    }

};

TEST(question_06, constructBinaryTree_01) {

    vector<int> result = Solution::constructBinaryTree({1, 2, 4, 7, 3, 5, 6, 8}, {4, 7, 2, 1, 5, 3, 8, 6});
    vector<int> result_ans = {1, 2, 4, 7, 3, 5, 6, 8};

    ASSERT_EQ(result.size(), result_ans.size());
    ASSERT_TRUE(equal(result.begin(), result.end(), result_ans.begin()));
}

TEST(question_06, constructBinaryTree_02) {

    vector<int> result = Solution::constructBinaryTree({}, {});
    vector<int> result_ans = {};

    ASSERT_EQ(result.size(), result_ans.size());
    ASSERT_TRUE(equal(result.begin(), result.end(), result_ans.begin()));
}