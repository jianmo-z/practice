/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 *
 * 文件: 01test.hpp
 * 时间: 2020/5/16-11:29
 * 作者: Pip
 */

#include <bits/stdc++.h>
#include "gtest/gtest.h"

using namespace std;

/**
 * 问题链接：C++并发编程实践，3.2章节，清单3.8
 * 解题思路：
 */

class hierarchical_mutex {
    std::mutex internal_mutex;
    unsigned long const hierarchy_value;
    unsigned long previous_hierarchy_value;
    static thread_local unsigned long this_thread_hierarchy_value;  // 线程级别的变量
    // 用thread_local修饰的变量表示在同一个线程中只会存在一份，且需要在类外进行声明

    void check_for_hierarchy_violation() {
        if (this_thread_hierarchy_value <= hierarchy_value) {
            throw std::logic_error("mutex hierarchy violated");
        }
    }

    void update_hierarchy_value() {
        previous_hierarchy_value = this_thread_hierarchy_value;
        this_thread_hierarchy_value = hierarchy_value;
    }

public:
    explicit hierarchical_mutex(unsigned long value) : hierarchy_value(value), previous_hierarchy_value(0) {}

    void lock() {
        check_for_hierarchy_violation();
        internal_mutex.lock();
        update_hierarchy_value();
    }

    void unlock() {
        this_thread_hierarchy_value = previous_hierarchy_value;
        internal_mutex.unlock();
    }

    bool try_lock() {
        check_for_hierarchy_violation();
        if (!internal_mutex.try_lock()) {
            return false;
        }
        update_hierarchy_value();
        return true;
    }
};

thread_local unsigned long hierarchical_mutex::this_thread_hierarchy_value(LLONG_MAX);

TEST(test01, hierarchical_mutex) {
    hierarchical_mutex m1(100);
    hierarchical_mutex m2(200);

// 100 -> 200
    m1.lock();
    m2.lock();
    m2.unlock();
    m1.unlock();

// 200 -> 100
    m2.lock();
    m1.lock();
    m1.unlock();
    m2.unlock();
}
