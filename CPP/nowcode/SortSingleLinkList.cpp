/* *** 代码是写给人看，顺带让机器执行 *** * ***  永远不要相信任何传进来的参数 ***
 *
 * 文件: SortSingleLinkList
 * 时间: 2020/12/6-22:43
 * 作者: Pip
 */

#include "../comm/ListNode.cpp"
#include "../googletest/include/gtest/gtest.h"

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    /**
     *
     * @param head ListNode类 the head node
     * @return ListNode类
     */
    ListNode* sortInList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode * pHead = nullptr;


        pHead = head;
        head = head->next;
        pHead->next = nullptr;

        while (head != nullptr) {
            ListNode * node = head;
            head = head->next;
            node->next = nullptr;
            pHead = insertNode(pHead, node);
        }

        return pHead;
    }


private:
    ListNode* insertNode(ListNode* head, ListNode* node) {
        if (head == nullptr || node == nullptr) {
            return nullptr;
        }

        if (head->val > node->val) {
            node->next = head;
            return node;
        }

        ListNode * pre = head;
        ListNode * it = head->next;

        while (pre != nullptr){
            if (it == nullptr) {
                pre->next = node;
                break;
            }

            if (it->val > node->val) {
                pre->next = node;
                node->next = it;
                break;
            }
            pre = it;
            it = it->next;
        }

        return head;
    }
};

TEST(Solution, test01)
{
    Solution s;
    auto ret = s.sortInList(ListNode::getLinkedList());
    while (ret != nullptr) {
        cout << ret->val << endl;
        ret = ret->next;
    }
}

TEST(Solution, test02)
{
    Solution s;
    auto ret = s.sortInList(nullptr);
    while (ret != nullptr) {
        cout << ret->val << endl;
        ret = ret->next;
    }
}

TEST(Solution, test03)
{
    Solution s;
    auto link = ListNode::createLinkedList({-426572,-406609,724427,-157789,-132713,720732,-39078,-348926,-693458,559374,114739,-748249,428207,-767407,401563,646432,-682870,483610,-608888,94840,749542,359115,131739,935294,347325,80573,-869091,-757897,-860166,-227942,-484068,-170790,-362441,-860466,819197,817675,886101,463504,-100482,496406,-860791});
    auto ret = s.sortInList(link);
    while (ret != nullptr) {
        cout << ret->val << endl;
        ret = ret->next;
    }
}