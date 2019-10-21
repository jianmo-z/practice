/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: practice_02.hpp
 * 时间: 9/7/2019-6:50 PM
 * 作者: Pip
 */

#include <bits/stdc++.h>

using namespace std;

string func(int a) {
    int num = 0x40000000;
    bool start = false;
    string ret;
    for (int i = 0; i < 31; ++i) {
        if (start) {
            ret += (num & a ? '1' : '0');
        } else if (num & a) {
            start = true;
            ret += '1';
        }
        num >>= 1;
    }
    int size = ret.size();
    for (int j = 0; j < size / 2; ++j) {
        if (ret[j] != ret[size - 1 - j]) {
            return "NO";
        }
    }
    return "YES";
}

int test() {
    int n = 0, num;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        string tmp = func(num);
        if (i + 1 == n) {
            cout << tmp;
        } else {
            cout << tmp << endl;
        }
    }
    return 0;
}