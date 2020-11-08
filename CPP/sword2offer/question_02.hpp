/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: question_02.hpp
 * 时间: 2020/4/15-22:42
 * 作者: Pip
 */

#include <bits/stdc++.h>

using namespace std;

// 懒汉-单例模式
class Singletion_01 {
public:
    static Singletion_01 &getInstance() {
        if (nullptr == Singletion_01::_instance) {
            // unique_lock<mutex> (locker, std::defer_lock).lock();
            unique_lock<mutex> m(Singletion_01::_locker);

            this_thread::sleep_for(chrono::seconds(1));
            if (nullptr == Singletion_01::_instance) {
                _instance = new Singletion_01();
            }
        }
        return *_instance;
    }

private:
    /**
     * 构造函数、拷贝构造函数、赋值函数
     */
    Singletion_01() {}

    Singletion_01(Singletion_01 const &) {}

    Singletion_01 &operator=(Singletion_01 const &) { return *Singletion_01::_instance; }

    static Singletion_01 *_instance;
    static mutex _locker;
};

// 定义静态成员变量
Singletion_01 *Singletion_01::_instance = nullptr;
mutex Singletion_01::_locker;

// 恶汉-单例模式
class Singletion_02 {
public:
    static Singletion_02 &getInstance() {
        return *Singletion_02::_instance;
    }

private:
    /**
     * 构造函数、拷贝构造函数、赋值函数
     */
    Singletion_02() {}

    Singletion_02(Singletion_02 const &) {}

    Singletion_02 &operator=(Singletion_02 const &) { return *Singletion_02::_instance; }

    static Singletion_02 *_instance;
};

// 定义静态成员变量
Singletion_02 *Singletion_02::_instance = new Singletion_02();

int test() {
    // Singletion_01();
    // Singletion_01(Singletion_01::getInstance());
    // Singletion_01 single = Singletion_01::getInstance();

    // Singletion_02();
    // Singletion_02(Singletion_02::getInstance());
    // Singletion_02 single = Singletion_02::getInstance();

    // thread_1
    thread thread_1(thread([]() {
        for (int i = 0; i < 5; ++i) {
            cout << "thread_1 = " << &Singletion_01::getInstance() << endl;
            this_thread::sleep_for(chrono::seconds(1));
        }
    }));

    // thread_2
    thread thread_2(thread([]() {
        for (int i = 0; i < 5; ++i) {
            cout << "thread_2 = " << &Singletion_01::getInstance() << endl;
            this_thread::sleep_for(chrono::seconds(1));
        }
    }));

    // 等待线程结束
    thread_1.join();
    thread_2.join();

    return 0;
}