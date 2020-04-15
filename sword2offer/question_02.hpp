/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: question_02.hpp
 * 时间: 2020/4/15-22:42
 * 作者: Pip
 */

#include <bits/stdc++.h>

using namespace std;

class Singletion_01 {
private:
    /**
     * 构造函数、拷贝构造函数、赋值函数
     */
    Singletion_01(): instance(nullptr) {}
    Singletion_01(Singletion_01 const & instance){}
    Singletion_01& operator = (const Singletion_01 & instance){return *this;}
    Singletion_01 * instance;

};

int test() {
    cout << __cplusplus << endl;
    return 0;
}