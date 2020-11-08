/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: question_07.hpp
 * 时间: 2020/5/2-19:51
 * 作者: Pip
 */

#include <bits/stdc++.h>
#include "gtest/gtest.h"

using namespace std;

/**
 * 问题链接：用两个栈实现队列
 * 解题思路：
 */

template <typename T>
class MyQueue {
public:
    MyQueue() {}
    void pushBack(T other) {
        while (!m_stack_out.empty()) {
            m_stack_in.push(m_stack_out.top());
            m_stack_out.pop();
        }
        m_stack_in.push(other);
    }
    T popHead() {
        while (!m_stack_in.empty()) {
            m_stack_out.push(m_stack_in.top());
            m_stack_in.pop();
        }
        T ret = m_stack_out.top();
        m_stack_out.pop();
        return ret;
    }

private:
    stack<T> m_stack_in;
    stack<T> m_stack_out;

};

TEST(question_07, testMyQueue) {
    MyQueue<int> queue;
    queue.pushBack(1);
    queue.pushBack(2);

    queue.pushBack(3);
    ASSERT_EQ(queue.popHead(), 1);

    queue.pushBack(3);
    queue.pushBack(4);
    ASSERT_EQ(queue.popHead(), 2);
    ASSERT_EQ(queue.popHead(), 3);
    ASSERT_EQ(queue.popHead(), 3);
    ASSERT_EQ(queue.popHead(), 4);
}
