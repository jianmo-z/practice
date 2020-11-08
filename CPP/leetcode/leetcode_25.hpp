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

// 28 ms	10.2 MB
class Solution_1 {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k == 0) {
            return head;
        }
        int i = 0;
        ListNode *ret = nullptr;
        ListNode *ret_tail = nullptr;
        ListNode *tail = nullptr;
        ListNode *tmp = nullptr;
        ListNode *chain = nullptr;

        while (head) {

            // 先生成小链
            chain = nullptr;
            for (i = 0; i < k; i++) {
                tmp = head;
                if (nullptr == tmp)
                    break;
                head = head->next;
                if (nullptr == chain) {
                    chain = tail = tmp;
                    tail->next = nullptr;
                } else {
                    tmp->next = chain;
                    chain = tmp;
                }
            }

            // 不满足构成一个子链还原
            if (i != k && i != 0) {
                ListNode *head = nullptr;
                head = tail = chain;
                chain = chain->next;
                tail->next = nullptr;
                head->next = nullptr;
                while (chain) {
                    tmp = chain;
                    chain = chain->next;
                    tmp->next = head;
                    head = tmp;
                }
                chain = head;
            }

            // 连接到主链上
            if (nullptr == ret) {
                ret = chain;
                ret_tail = tail;
            } else {
                ret_tail->next = chain;
                ret_tail = tail;
                tail->next = nullptr;
            }
        }
        return ret;
    }

};


// 20 ms	10.6 MB
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (k == 0) {
            return head;
        }
        int i = 0;
        deque<ListNode *> st;
        ListNode *ret = nullptr;
        ListNode *tail = nullptr;

        while (head) {
            for (i = 0; i < k; i++) {
                if (nullptr == head)
                    break;
                st.push_back(head);
                head = head->next;
            }
            if (i != k && i != 0) {
                while (st.size()) {
                    if (!ret) {
                        ret = tail = st.front();
                        st.pop_front();
                    } else {
                        tail->next = st.front();
                        st.pop_front();
                        tail = tail->next;
                        tail->next = nullptr;
                    }
                }
            } else {
                while (st.size()) {
                    if (!ret) { // ret为nullptr
                        ret = tail = st.back();
                        st.pop_back();
                    } else {
                        tail->next = st.back();
                        st.pop_back();
                        tail = tail->next;
                        tail->next = nullptr;
                    }
                }
            }

        }
        return ret;
    }

};

void test() {
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
//    head->next->next = new ListNode(3);
//    head->next->next->next = new ListNode(4);
//    head->next->next->next->next = new ListNode(5);
//    head->next->next->next->next->next = new ListNode(6);

    head = s.reverseKGroup(head, 3);

    while (head) {
        cout << head->val << endl;
        delete head;
        head = head->next;
    }
}