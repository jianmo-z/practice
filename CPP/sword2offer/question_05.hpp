/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: question_05.hpp
 * 时间: 4/27/2020-9:12 PM
 * 作者: Pip
 */

#include <bits/stdc++.h>
#include "gtest/gtest.h"

using namespace std;

struct node{
    int data;
    struct node * next;
    node():data(0), next(nullptr){}
    node(int data, node * next): data(data), next(next){}
};

vector<int> printListReversingly(const node &head) {
    node * h = const_cast<node *>(head.next);
    stack<int> s;
    while (h) {
        s.push(h->data);
        h = h->next;
    }

    vector<int> ret;
    ret.reserve(s.size());

    while (!s.empty()) {
        ret.push_back(s.top());
        s.pop();
    }

    return ret;
}

bool isEqual(vector<int> v1, vector<int> v2) {
    if (v1.size() != v2.size())
        return false;
    return equal(v1.begin(), v1.end(), v2.begin());
}


TEST(question_05, printListReversingly) {
    node n[5];
    n[0].data = -1;
    n[0].next = &n[1];
    n[1].next = &n[2]; n[1].data = 1;
    n[2].next = &n[3]; n[2].data = 2;
    n[3].next = &n[4]; n[3].data = 3;
    n[4].next = nullptr; n[4].data = 4;

    ASSERT_TRUE(isEqual(printListReversingly(n[0]), {4, 3, 2, 1}));
    ASSERT_TRUE(isEqual(printListReversingly(n[4]), {}));
    ASSERT_TRUE(isEqual(printListReversingly(n[3]), {4}));
}