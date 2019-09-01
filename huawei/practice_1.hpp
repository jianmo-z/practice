/* *** 代码是写给人看，顺带让机器执行 ***
 * ***  永远不要相信任何传进来的参数 ***
 * 
 * 文件: practice.hpp
 * 时间: 2019/8/31-17:49
 * 作者: Pip
 */

#include <bits/stdc++.h>

using namespace std;

int test1() {
    unsigned int n = 5;
    int num;
    int times = 0;
    int pos = -1;
    scanf("%d", &num);
    for (int i = 0; i < 30; ++i, n<<=1) {
        if (n > num) {
            break;
        }

        if ((n & num) == n) {
            ++times;
            if (-1 == pos) {
                pos = i;
            }
        }
    }
    printf("%d %d", times, pos);
    return 0;
}

int test() {
    int num = 0;
    string str;
    scanf("%d", & num);
    for (int i = 0; i < 32; ++i) {
        if(num & (1 << i)) {
            str += '1';
        } else {
            str += '0';
        }
    }
    cout << str;
}