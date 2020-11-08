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

// 4 ms	8.9 MB
class Solution {
public:
    // 有内存泄露
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *ret = head;
        deque<ListNode *> d;

        while (head) {
            d.push_back(head);
            head = head->next;
        }
        if (1 == n) { // 删除的是尾结点 或 只有一个元素
            d.pop_back();
            if (!d.empty()) { // 非空
                d.back()->next = nullptr;
            } else {
                ret = nullptr;
            }
        } else if (d.size() == n) { // 删除的是头节点
            ret = ret->next;
        } else {
            n += 1;
            while (--n) {
                d.pop_back();
            }
            d.back()->next = d.back()->next->next;
        }
        return ret;
    }

};

void test() {
//    ListNode l1(6), l2(2), l3(3), l4(4), l5(5);
//    l1.next = &l2;
//    l2.next = &l3;
//    l3.next = &l4;
//    l4.next = &l5;
//    l5.next = nullptr;

    ListNode l1(6);
    l1.next = nullptr;
    Solution s;
    ListNode *ret = s.removeNthFromEnd(&l1, 1);
    while (ret) {
        cout << ret->val << " ";
        ret = ret->next;
    }
    cout << endl;


}