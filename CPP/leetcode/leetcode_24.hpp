//
// Created by pip on 19-3-10.
//
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode * ret = nullptr;
        ListNode * pre = nullptr;
        ListNode * tail = nullptr;
        ListNode * tmp = nullptr;
        ListNode * it = nullptr;
        while(head) {
            // 第一个元素尾插
            it = head;
            head = head->next;
            if(ret == nullptr) {
                tail = ret = it;
            } else {
                tail->next = it;
                pre = tail;
                tail = tail->next;
                tail->next = nullptr;
            }

            // 第二个元素插在尾节点之前
            if(head == nullptr) {
                tail->next = nullptr;
                break;
            }
            it = head;
            head = head->next;
            if(pre == nullptr) {
                it->next = ret;
                ret =  it;
                tail = ret->next;
                tail->next = nullptr;
            } else {
                pre->next = it;
                it->next = tail;
            }
        }
        return ret;
    }
};

void test() {

    Solution s;
    ListNode * head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
//    head->next->next->next->next = new ListNode(5);
//    head->next->next->next->next->next = new ListNode(6);

    head = s.swapPairs(head);

	while(head) {
	    cout << head->val << endl;
	    delete head;
	    head = head->next;
	}
}