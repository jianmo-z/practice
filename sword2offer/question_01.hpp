/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: question_01.hpp
 * 时间: 2020/4/15-20:06
 * 作者: Pip
 */

#include <bits/stdc++.h>

using namespace std;

class CMyString {
public:
    CMyString(const char *mData = nullptr) {
        int size = mData == nullptr ? 1 : strlen(mData) + 1;
        char *temp = new char[size];
        if(mData != nullptr) {
            strcpy(temp, mData);
        }
        this->m_data = temp;
    }

    CMyString(const CMyString &str) {
        char *temp = new char[strlen(str.m_data) + 1];
        strcpy(temp, str.m_data);
        this->m_data = temp;
    }

    CMyString &operator=(const CMyString &str) {
        // 判断是否是自赋值
        if (&str != this) {
            // 临时对象
            CMyString tempStr(str);

            // 把临时对象和当前对象的实例进行交换，临时对象析构时也会释放资源
            std::swap(this->m_data, tempStr.m_data);
        }

        // 链式编程连续赋值
        return *this;
    }

    friend ostream &operator<<(ostream &out, const CMyString & str) {
        out << &str.m_data << ":" <<  str.m_data;
        return out;
    }

    virtual ~CMyString() {
        if (nullptr != this->m_data) {
            delete[] this->m_data;
        }

    }

private:
    char *m_data;
};

int test() {
    // 测试
    CMyString c1("hello c1");
    CMyString c2;
    CMyString c3;
    CMyString c4;

    // 测试打印对象
    cout << "c1:" <<c1 << endl;

    // 把一个实例赋值给另一个实例
    c2 = c1;
    cout << "c1:" << c1 << endl;
    cout << "c2:" << c2 << endl;

    // 赋值给自己
    c1 = c1;
    cout << "c1:" << c1 << endl;

    // 连续赋值
    c4 = c3 = c2 = c1;

    cout << "c1:" << c1 << endl;
    cout << "c2:" << c2 << endl;
    cout << "c3:" << c3 << endl;
    cout << "c4:" << c4 << endl;

    return 0;
}