/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 *
 * 文件: ListNode
 * 时间: 2020/12/6-22:44
 * 作者: Pip
 */


/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 *
 * 文件: ListNode
 * 时间: 2020/12/6-22:44
 * 作者: Pip
 */

#include "bits/stdc++.h"

using namespace std;

/**
 * @author Pip
 */

struct ListNode {
	int val;
	struct ListNode *next;

    ListNode(int val) : val(val) {
        this->next = nullptr;
    }

    ListNode() : val(0) {
        this->next = nullptr;
    }

    static ListNode * getLinkedList() {
        // 2 3 5 4 1
	    auto l1 = new ListNode(2);
	    auto l2 = new ListNode(3); l1->next = l2;
	    auto l3 = new ListNode(5); l2->next = l3;
	    auto l4 = new ListNode(4); l3->next = l4;
	    auto l5 = new ListNode(1); l4->next = l5;

        return l1;
	}

	static ListNode * createLinkedList(vector<int> array) {

        ListNode* head = new ListNode();
        ListNode* tail = head;

        for(int i : array) {
            tail->next = new ListNode(i);
            tail = tail->next;
        }
        tail =  head->next;
        delete head;
        return tail;
    }
};