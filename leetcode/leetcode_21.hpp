//
// Created by pip on 19-3-10.
//
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode * next;
	ListNode(int val):val(val), next(nullptr){}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode * tmp = nullptr;
		ListNode * p = nullptr, * tail = nullptr;
		// 把最终的结果累计到l1上
		while(l1 != nullptr && l2 != nullptr) {
			if(l1->val < l2->val) {
				tmp = l1;
				l1 = l1->next;
			} else {
				tmp = l2;
				l2 = l2->next;
			}

			// 尾插法,空链表添加数据
			if(p == nullptr) {
				p = tail = tmp;
			} else {
				tail->next = tmp;
				tail = tail->next;
			}
		}

		// 如果l1为空或者l2为空,则tail为nullptr使用tail->next产生访问非法内存
		if(tail != nullptr) {
			if(l1 != nullptr) {
				tail->next = l1;
			} else {
				tail->next = l2;
			}
		} else {
			if(l1 != nullptr) {
				p = l1;
			} else {
				p = l2;
			}
		}

		return p;
	}

};

void test() {
	ListNode * l1, * l2;
	l1 = new ListNode(1);
	l2 = new ListNode(1);
	l1->next = new ListNode(2);
	l2->next = new ListNode(3);
	l1->next->next = new ListNode(4);
	l2->next->next = new ListNode(4);

	Solution s;
	s.mergeTwoLists(l1, l2);

	for(int i = 0; i < 6; i++) {
		cout << l1->val << endl;
		l1 = l1->next;
	}
}