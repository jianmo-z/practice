/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: leetcode_116.hpp
 * 时间: 2019/8/30-20:25
 * 作者: Pip
 */

#include <bits/stdc++.h>

using namespace std;
/**
 * 问题链接：https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
 * 解题链接：https://www.youtube.com/watch?v=YNu143ZN4qU
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node() {}
    Node(int _val, Node *_left, Node *_right, Node *_next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution {
public:
    Node *connect(Node *root) {
        if (!root->left || !root) {
            return root;
        }
        if (root->next) {
            root->right->next = root->next->left;
        }
        root->left->next = root->right;
        connect(root->left);
        connect(root->right);
        return root;
    }
};

void test() {
    Solution s;
    cout << "hello file leetcode_116.hpp" << endl;
}