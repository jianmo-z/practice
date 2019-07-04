//
// Created by pip on 19-3-10.
//
#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *ret = nullptr, *tail = nullptr, *min = nullptr;

        for (;;) {
            if (0 == lists.size()) {
                break;
            }

            for (auto &it:lists) {
                while (it->val == tail->val && ret) { // 相同则直接挂上去

                }
            }

            // 找出最小的那个
            for (auto &it:lists) {
                if (nullptr == min) {
                    min = it;
                } else if (it) { // 节点不能为空
                    if (min->val > it->val) {
                        min = it;
                    }
                }
            }

            // 最小的数据头结点删掉
            // 如果已经没有值了应该从lists中删除
            if (min) {

            }

        }
        return ret;
    }
};

void test() {
    Solution s;
    vector<ListNode *> lists;

    s.mergeKLists(lists);
}