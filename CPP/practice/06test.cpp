/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 *
 * 文件: 02test
 * 时间: 2020/12/15-23:03
 * 作者: Pip
 */


#include <bits/stdc++.h>
#include "../googletest/include/gtest/gtest.h"

using namespace std;

namespace Test06 {
    struct Node{
        int val;
        Node * next;

        Node(int val) : val(val), next(nullptr) {}
    };

    class Solution {
    public:
        Node * reverseLinkedList(Node * head) {
            Node * ret = nullptr;

            while (head != nullptr) {
                Node * tmp = head;
                head = head->next;
                tmp->next = ret;
                ret = tmp;
            }
            return ret;
        }
    };

    Node * initList() {
        Node * n1 = new Node(1);
        Node * n2 = new Node(2); n1->next = n2;
        Node * n3 = new Node(3); n2->next = n3;
        Node * n4 = new Node(4); n3->next = n4;

        return n1;
    }

    void printLinkedList(Node * head) {
        while (head != nullptr) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }

    TEST(Test06, test01) {
        Solution s;

        Node* head = initList();
        printLinkedList(head);
        printLinkedList(s.reverseLinkedList(head));
    }


    // [-2^31, 2^31 - 1]
    // FF -> 1111 1111
    //
    // 0xFF FF FF FF -> 0x80 00 00 00 -> +1 -> 0x80 00 00 01 ->  -1
    // 0x80 00 00 02 -> 0xFF FF FF FD -> +1 -> 0xFF FF FF FE -> -2^31
    // -1 -> 0x80 00 00 00 + 1 -> 0x80 00 00 01 -> 0xFF FF FF F1
    TEST(Test06, test02) {
        Solution s;

        Node* head = nullptr;
        printLinkedList(head);
        printLinkedList(s.reverseLinkedList(head));
    }
}